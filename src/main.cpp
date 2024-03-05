#include <iostream>

#include "FrankList.hpp"

auto main(int argc, char* argv[]) -> int
{
    using namespace vhuk;

    FrankList<int> f{ 5, 6, 1, 8, 2, 10, 4, 12, 9, 4 };

    f.erase(std::next(f.begin(), 2), f.end());
    std::cout << f << std::endl << std::endl;

    return 0;
}
