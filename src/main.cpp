#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include "hash.h"

int main(int argc, char *argv[]) {
    
    std::string help(argv[1]);
    if ((help == "-h") || (help == "help")) {
        std::cout << "usage: hash <algorithm> </path/to/file>" << std::endl;
        return 1;
    }
    
    if (argc < 3) {
        std::cerr << "use -h or help" << std::endl;
        return 2;
    }
    
    
    
    std::string filename(argv[2]);
    std::ifstream hashfile(filename);
    
    if (hashfile.fail()) {
        std::cerr << "cannot open file '" << filename << "'" << std::endl;
        return 3;
    }
    
    std::string algstr(argv[1]);
    if (algstr == "crc32") {
        std::cout << "'" << filename << "' crc32 hash is: " << calculate_crc32(hashfile) << std::endl;
    } else if (algstr == "sum32") {
        std::cout << "'" << filename << "' sum32 hash is: " << calcutale_sum32(hashfile) << std::endl;
    } else {
        std::cerr << "unknown algorithm '" << algstr << "'" << std::endl;
        std::cerr << "please use one of these: 'crc32' or 'sum32'";
        return 4;
    }
    
    return 0;
}


