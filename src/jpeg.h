//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_JPEG_H
#define JPEGREANDE_JPEG_H

#include <cstddef>
#include <vector>

std::vector<std::byte> get_jpeg_header(int px_size_x, int px_size_y);

#endif //JPEGREANDE_JPEG_H
