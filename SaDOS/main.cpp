//
//  main.cpp
//  SaDOS:
//
//  Silicon
//  and
//  Disk
//  Operating
//  System
//
//  Created by Aarron Rasmussen on 1/9/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cassert>

#include <arpa/inet.h>

uint32_t readUint32(std::ifstream& f);

//TODO: Move this to a seperate file.

struct Number{
public:
    uint8_t label;
    uint8_t number[28][28];

    Number(uint8_t label, uint8_t number[28][28]) {
        this->label = label;

        for(size_t i = 0; i < 28; i++) {
            for(size_t j = 0; j < 28; j++) {
                this->number[i][j] = number[i][j];
            }
        }
    }
};

std::vector<Number> numVec;

void readData(const std::string& filePath) {
    std::ifstream f(filePath);

    int magicNum = readUint32(f);
    int sampleSize = readUint32(f);

    assert(magicNum = 2051);

    int rows = readUint32(f);
    int columns = readUint32(f);

    assert(rows == 28);
    assert(columns == 28);

    uint8_t image[28][28];
    for(size_t i = 0; i < sampleSize; ++i) {
        f.read(reinterpret_cast<char*>(&image), sizeof(image));

        for(size_t y = 0; y < 28; y++) {
            for(size_t x = 0; x < 28; x++) {
                std::cout << (image[y][x] > 0 ? '.' : ' ');
            }
            std::cout << "\n";
        }
    }

    assert(f.good());
    assert(!f.eof());
    f.peek();
    assert(f.eof());
}

void readLabel(const std::string& filePath) {
    std::ifstream f(filePath, std::ios::binary);

    int magicNum = readUint32(f);
    int sampleSize = readUint32(f);

    assert(magicNum == 2049);

    int c;
    for(int i = 0; i < sampleSize; i++) {
        c = f.get();
        std::cout << static_cast<int>(c) << std::endl;
    }

    assert(f.good());
    assert(!f.eof());
    f.peek();
    assert(f.eof());
}

uint32_t readUint32(std::ifstream& f) {
    uint32_t magicNum;

    f.read(reinterpret_cast<char*>(&magicNum), sizeof(magicNum));

    return ntohl(magicNum);
}

void greeting() {
    std::ifstream f("/Users/aarronrasmussen/SaDOS/SaDOS/SaDOSLogo.txt");

    std::string line;

    while(std::getline(f, line)) {
        std::cout << line << std::endl;
    }
}

int main(int argc, const char * argv[]) {

    greeting();

    try {
        readData("/Users/aarronrasmussen/SaDOS/train-images-idx3-ubyte");
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        readLabel("/Users/aarronrasmussen/SaDOS/train-labels-idx1-ubyte");
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }
}


