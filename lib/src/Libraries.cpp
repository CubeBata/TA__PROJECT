#include <Libraries.h>

size_t random(size_t min, size_t max)
{
    std::random_device rd;
    static std::mt19937_64 gen(rd());
    std::uniform_int_distribution<std::size_t> dist(min, max);
    return dist(gen);
}

template <typename T>
void show(const std::set<T> &container) {
    if (container.empty()) {
        std::cout << "{}\n";
        return;
    }
    std::cout << "{ ";
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << (i==container.size()-1?" }\n":", ");
    }
}