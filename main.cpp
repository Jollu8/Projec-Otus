#include <cstdlib>
#include <fstream>

#include <cstdlib>
#include <fstream>

int main() {
    std::ifstream ifile("./temp_exec/work_2_FilterIP/ipfilter");
    if(!ifile) {
        std::system("mkdir -p ./temp_exec/work_2_FilterIP && cd ./temp_exec/work_2_FilterIP && cmake ../../src/work_2_FilterIP/ && make");
    }
    system("./temp_exec/work_2_FilterIP/ipfilter ./data/ip_filter.tsv");
}



