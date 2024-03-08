#include <iostream>

#include "FrankList.hpp"

auto main(int argc, char* argv[]) -> int
{
    using namespace vhuk;

    FrankList<int> f{ 1, 1, 5, 1, 1, 3, 1, 1, 1 };
    f.insert(f.end(), 9);
    std::cout << f << std::endl;
    f.erase(f.remove_if([](auto& e) { return true; }), f.end());
    std::cout << f << std::endl;

    return 0;
}
