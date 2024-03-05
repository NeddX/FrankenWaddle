#include <iostream>

#include "FrankList.hpp"

auto main(int argc, char* argv[]) -> int
{
    using namespace vhuk;

    FrankList<int> f{ 5, 6, 1, 8, 2 };

    std::cout << f << std::endl << std::endl;
    f.pop_back();
    std::cout << f << std::endl << std::endl;
    f.pop_front();
    std::cout << f << std::endl << std::endl;

    return 0;
}
