//
//  MNISTReader.hpp
//  SaDOS
//
//  Created by Aarron Rasmussen on 1/10/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#ifndef MNISTReader_hpp
#define MNISTReader_hpp

#include <fstream>
#include <iostream>

class MNISTReader {
        static uint32_t readUint32(std::ifstream& f) {
        uint32_t magicNum;

        f.read(reinterpret_cast<char*>(&magicNum), sizeof(magicNum));

        return ntohl(magicNum);
    }

public:
    static void readData(const std::string& filePath) {
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

    static int* readLabel(const std::string& filePath) {
        std::ifstream f(filePath, std::ios::binary);

        int magicNum = readUint32(f);
        int sampleSize = readUint32(f);

        assert(magicNum == 2049);

        int* labelArray = new int [sampleSize];

        int c;
        for(int i = 0; i < sampleSize; i++) {
            c = f.get();
            labelArray[i] = static_cast<int>(c);
        }

        assert(f.good());
        assert(!f.eof());
        f.peek();
        assert(f.eof());

        return labelArray;
    }
};

#endif /* MNISTReader_hpp */
