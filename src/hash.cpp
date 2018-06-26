#include "hash.h"


uint32_t calcutale_sum32 (std::istream &hashfile) {
    char block[4];
    uint32_t result = 0;
    while (true) {
        hashfile.read(block, 4);
        const size_t n = hashfile.gcount();
        if (!n) {
            break;
        }
        uint32_t value = 0;
        for (size_t i = 0; i < n; ++i) {
            value += static_cast<uint32_t>(block[i]) << ((3-i)*8);
        }
        result += value;
    }
    return result;
}



uint32_t calculate_crc32 (std::istream &hashfile) {
    uint32_t crc_table[256];
    uint32_t crc;
    
    for (unsigned int i = 0; i < 256; i++) {
        crc = i;
        for (int j = 0; j < 8; j++) {
            crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
        }
        crc_table[i] = crc;
    }
    
    crc = 0xFFFFFFFFUL;
    
    char block[4];
    while (true) {
        hashfile.read(block, 4);
        const size_t n = hashfile.gcount();
        if (!n) {
            break;
        }
        for (size_t i = 0; i < n; ++i) {
            crc = crc_table[(crc ^ block[i]) & 0xFF] ^ (crc >> 8);
        }
    }
    
    return crc = crc ^ 0xFFFFFFFFUL;
}

