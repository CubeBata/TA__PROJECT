@echo off
setlocal enabledelayedexpansion

:: for color text
for /F %%A in ('echo prompt $E ^| cmd') do set "ESC=%%A"

set "CLEAR_SCREEN=false"
set "FROM_SCRATCH=false"
set "ONLY="

:parse_arguments
if "%~1" == "" goto end_arguments

if "%~1" == "-c" (
    set "CLEAR_SCREEN=true"
) else if "%~1" == "--clear" (
    set "CLEAR_SCREEN=true"
) else if "%~1" == "-fs" (
    set "FROM_SCRATCH=true"
) else if "%~1" == "--from-scratch" (
    set "FROM_SCRATCH=true"
) else if "%~1" == "--release" (
    set "ONLY=r"
) else if "%~1" == "-r" (
    set "ONLY=r"
) else if "%~1" == "--debug" (
    set "ONLY=d"
) else if "%~1" == "-d" (
    set "ONLY=d"
) else (
    call :output "Error: unknown flag: %~1" 41
    goto to_exit
)

shift
goto parse_arguments

:end_arguments

if "%CLEAR_SCREEN%" == "true" cls

if "%FROM_SCRATCH%" == "true" (
    if exist build_debug rmdir /s /q build_debug
    if exist build_release rmdir /s /q build_release
)

:to_main

if "%ONLY%" == "r" (
    goto releasing
)

:debugging
call :output "Configuring Debug..." 44
cmake -G "MinGW Makefiles" -B build_debug -DCMAKE_BUILD_TYPE=Debug
call :output "==========[ ECHO: CONFIGURE DONE ]=========" 42

call :output "Building Debug..." 44
cmake --build build_debug
call :output "==========[ ECHO: BUILD DONE ]=========" 42

if "%ONLY%" == "d" (
    goto to_exit
)

:releasing
call :output "Configuring Release..." 44
cmake -G "MinGW Makefiles" -B build_release -DCMAKE_BUILD_TYPE=Release
call :output "==========[ ECHO: CONFIGURE DONE ]=========" 42

call :output "Building Release..." 44
cmake --build build_release
call :output "==========[ ECHO: BUILD DONE ]=========" 42
goto to_exit

:output 
if "%~2" == "" (
    echo %~1
) else (
    echo !ESC![%~2m%~1!ESC![0m
)
exit /b

:to_exit
exit /b 0
