#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include "ip.h"

#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Укажите имя файла в качестве аргумента командной строки.\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Не удалось открыть файл " << filename << '\n';
        return 1;
    }

    ip::IpPool ipPool;

    try {
        for (std::string line; std::getline(file, line);) {
            ipPool.push_back(ip::parse(line));
        }
        std::sort(begin(ipPool), end(ipPool), ip::IpReverseComparator{});
#if 0 // должен просто вывести сортированными
        std::copy(begin(ipPool), end(ipPool), std::ostream_iterator<ip::Ip>(std::cout, "\n"));
#endif
        std::cout << "First_1\n:";
        ip::filter<ip::FilterType::First_1>(ipPool, std::cout);
        std::cout << "\nFirst_46_Second_70\n:";
        ip::filter<ip::FilterType::First_46_Second_70>(ipPool, std::cout);
        std::cout << "\nAny_46\n";
        ip::filter<ip::FilterType::Any_46>(ipPool, std::cout);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
