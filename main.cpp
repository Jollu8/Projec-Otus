#include <cstdlib>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

const std::string run_ipFilter = "./temp_exec/work_2_FilterIP/ipFilter";
const char *build_ipFilter = "mkdir -p ./temp_exec/work_2_FilterIP && cd ./temp_exec/work_2_FilterIP && cmake ../../src/work_2_FilterIP/ && make";

const std::string run_work_3 = "./temp_exec/work_3_allocator/allocator";
const char * build_work_3 = "mkdir -p ./temp_exec/work_3_allocator && cd ./temp_exec/work_3_allocator && cmake ../../src/work_3_allocator/ && make";


const std::string run_work_4 = "./temp_exec/work_4_SFINAE/print_ip";
const char * build_work_4 = "mkdir -p ./temp_exec/work_4_SFINAE && cd ./temp_exec/work_4_SFINAE && cmake ../../src/work_4_SFINAE/ && make";

const std::string run_work_5 = "./temp_exec/work_5/editor";
const char * build_work_5 = "mkdir -p ./temp_exec/work_5 && cd ./temp_exec/work_5 && cmake ../../src/work_5/ && make";

const std::string run_work_6 = "./temp_exec/work_6/matrix";
const char * build_work_6 = "mkdir -p ./temp_exec/work_6 && cd ./temp_exec/work_6 && cmake ../../src/work_6/ && make";

const std::string run_work_7 = "./temp_exec/work_7/bulk";
const char * build_work_7 = "mkdir -p ./temp_exec/work_7 && cd ./temp_exec/work_7 && cmake ../../src/work_7/ && make";

const std::string run_work_8 = "./temp_exec/work_8/bayan";
const char * build_work_8 = "mkdir -p ./temp_exec/work_8 && cd ./temp_exec/work_8 && cmake ../../src/work_8/ && make";



int main() {
    using namespace std::chrono_literals;




//    std::cout << "\n\n=============== work_2_FilterIP ====================\n" << std::endl;
//    std::ifstream ipFilter(run_ipFilter);
//    if (!ipFilter)
//        std::system(build_ipFilter);
//    std::system(std::string(run_ipFilter + " ./data/ip_filter.tsv").c_str());
//    std::this_thread::sleep_for(2000ms);
//
//
//    std::cout << "\n\n================= work_3_allocator =================\n" << std::endl;
//    std::ifstream work_3(run_work_3);
//    if (!work_3)
//        std::system(build_work_3);
//    std::system(run_work_3.c_str());
//    std::this_thread::sleep_for(2000ms);

//    std::cout << "\n\n================= work_4_SFINAE =================\n" << std::endl;
//    std::ifstream work_4(run_work_4);
//    if (!work_4)
//        std::system(build_work_4);
//    std::system(run_work_4.c_str());
//    std::this_thread::sleep_for(2000ms);

//    std::cout << "\n\n================= work_5_editor =================\n" << std::endl;
//    std::ifstream work_5(run_work_5);
//    if (!work_5)
//        std::system(build_work_5);
//    std::system(run_work_5.c_str());
//    std::this_thread::sleep_for(2000ms);

//    std::cout << "\n\n================= work_6_matrix =================\n" << std::endl;
//    std::ifstream work_6(run_work_6);
//    if (!work_6)
//        std::system(build_work_6);
//    std::system(run_work_6.c_str());
//    std::this_thread::sleep_for(2000ms);

    std::cout << "\n\n================= work_7_bulk =================\n" << std::endl;
    std::ifstream work_7(run_work_7);
    if (!work_7)
        std::system(build_work_7);
    std::system(std::string(run_work_7 + " ./data/commands_for_work_7.txt").c_str());
    std::this_thread::sleep_for(2000ms);


//    std::cout << "\n\n================= work_8_bayan =================\n" << std::endl;
//    std::ifstream work_8(run_work_8);
//    if (!work_8)
//        std::system(build_work_8);
//    std::system(std::string(run_work_8 + " -s ~/.. -e QT -l1 -f1 -b100 -m t?g*.*").c_str());
//    std::this_thread::sleep_for(2000ms);

}



