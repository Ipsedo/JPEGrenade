//
// Created by samuel on 24/07/2020.
//

#include <iostream>

#include "markers.h"

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
    std::cout << "Will write " << px_side << "*" << px_side << "px white JPEG in \"" << jpeg_out_file << "\" file" << std::endl;

    return 0;
}

