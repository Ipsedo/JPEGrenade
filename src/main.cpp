//
// Created by samuel on 24/07/2020.
//

#include <iostream>
#include <cmath>

#include "markers.h"
#include "types.h"
#include "enc.h"

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
    for (int i = 0; i < 64; i++) test.values[int(floor(i / 8.))][i % 8] = std::byte{(unsigned char) i};

    zigzag_block zigzag_test = zigzag_encode(test);

    for (auto b : zigzag_test)
        std::cout << std::to_integer<int>(b) << ", ";
    std::cout << std::endl;

    return 0;
}

