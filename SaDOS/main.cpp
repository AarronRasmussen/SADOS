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
#include "MNISTReader.hpp"

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

void greeting() {
    std::ifstream f("SaDOSLogo.txt");

    std::string line;

    while(std::getline(f, line)) {
        std::cout << line << std::endl;
    }

    f.close();

    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    greeting();
    std::vector<Number> numVec;

    int* labelArray = MNISTReader::readLabel("/Users/aarronrasmussen/SaDOS/train-labels-idx1-ubyte");
    MNISTReader::readData("/Users/aarronrasmussen/SaDOS/train-images-idx3-ubyte");

    for(size_t i = 0; i < 60000; i++) {
        std::cout << labelArray[i] << std::endl;
    }

    delete [] labelArray;
}
