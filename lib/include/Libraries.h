#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <random>
#include <limits>
#include <stdexcept>

using str = std::string;
template <typename T> 
using vec = std::vector<T>;
size_t random(
    size_t min = std::numeric_limits<std::size_t>::min(), 
    size_t max = std::numeric_limits<std::size_t>::max()
);
template <typename T>
void show(const std::set<T>& container);
