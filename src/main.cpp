//
// Created by samuel on 24/07/2020.
//

#include <iostream>
#include <cmath>

#include "types.h"
#include "enc.h"
#include "jpeg.h"

void build_header() {
    // TODO build header
}

int main(int argc, char **argv) {

    auto usage_msg = "Wrong arg number, usage :\n"
                     "$ # Create a white jpeg named \"out.jpeg\" of 512*512px\n"
                     "$ ./JPEGrenade 512 out.jpeg";

    if (argc != 3) {
        std::cerr << usage_msg << std::endl;
        return 1;
    }

    int px_side = std::stoi(argv[1]);
    std::string jpeg_out_file = argv[2];

    std::cout << "Begin JPEG-Grenade creation" << std::endl;
    std::cout << "Will write " << px_side << " * " << px_side << " px white JPEG in \""
              << jpeg_out_file << "\" file" << std::endl;

    std::cout << "test zig-zag" << std::endl;

    block test;
    // extrait patch d'image
    int tmp_test[8][8]{{71, 73, 74, 74,  73,  73,  74,  76},
                       {75, 77, 79, 78,  77,  75,  76,  76},
                       {75, 77, 78, 77,  75,  73,  73,  74},
                       {73, 74, 76, 75,  73,  73,  74,  76},
                       {73, 75, 76, 77,  77,  79,  83,  87},
                       {76, 77, 79, 81,  83,  88,  94,  98},
                       {84, 88, 93, 96,  99,  103, 109, 112},
                       {83, 88, 96, 101, 104, 105, 108, 109}};

    for (int i = 0; i < 64; i++) test.values[int(floor(i / 8.))][i % 8] = tmp_test[int(floor(i / 8.))][i % 8];

    block q_matrix;
    // Default quant matrix, osef comme on a que des 0
    int tmp_q_matrix[8][8]{{16, 11, 10, 16, 24,  40,  51,  61},
                           {12, 12, 14, 19, 26,  58,  60,  55},
                           {14, 13, 16, 24, 40,  57,  69,  56},
                           {14, 17, 22, 29, 51,  87,  80,  62},
                           {18, 22, 37, 56, 68,  109, 103, 77},
                           {24, 35, 55, 64, 81,  104, 113, 92},
                           {49, 64, 78, 87, 103, 121, 120, 101},
                           {72, 92, 95, 98, 112, 100, 103, 99}};

    for (int i = 0; i < 64; i++)
        q_matrix.values[int(floor(i / 8.))][i % 8] = tmp_q_matrix[int(floor(i / 8.))][i % 8];

    block dct_block = dct(test);
    block qt_block = quantize(dct_block, q_matrix);
    zigzag_block zigzag_test = zigzag_encode(qt_block);

    for (auto v : zigzag_test.values)
        std::cout << v << ", ";
    std::cout << std::endl;

    return 0;
}

