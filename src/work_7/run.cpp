#include "CommandHandler.h"
#include <cmath>
#include <fstream>

int main(int argc, char *argv[]) {


    if (argc != 2) return 1;

    if (std::isdigit(argv[1][0])) {
        int bulkSize = std::atoi(argv[1]);
        if (bulkSize > 0) {
            CommandHandler c(bulkSize);

        }
    } else {
        std::string line;
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            std::getline(file, line);
            CommandHandler c(std::atoi(line.c_str()));
            c.start(file);

        }else {
            return 1;
        }
    }

std::cout << "Done bulk" << std::endl;
    return 0;
}