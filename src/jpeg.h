//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_JPEG_H
#define JPEGREANDE_JPEG_H

#include <cstddef>
#include <vector>

#include "types.h"

std::vector<std::byte> get_jpeg_header(int px_size_x, int px_size_y);

/**
 * TODO voir si les prgm genre gimp bouffe *factor de memoire
 *
 * - 8 Frames possibles par JPEG
 * - 255 scans possible dans un frame en groupe de 4 scans
 * - un scan 8 * 8 de pixel de coté
 * - scale * 4 possible
 *
 * 8 * 255 * 8 * 4 = 65280px de coté
 * 3.96Go
 *
 * Compression pure (sans les headers des scans et frames) :
 * 1 block 8 * 8 = 64B -> EOB 1B
 * code Huffman avec table[EOB] == "1" : EOB 1B -> 1bit
 *
 * 64 * 8 = 512
 *
 * 3.96Go / 512 = 7.93Mo (lol à vérifier ^⁾
 *
 * @param sample_per_line
 * @param line
 * @return
 */
std::vector<uint8_t> get_frame_header(uint8_t nf, uint16_t max_y, uint16_t max_y, std::bitset<4> h, std::bitset<4> v);

std::vector<uint8_t> get_scan_header(uint8_t ns);

std::vector<dc_ac_block> get_black_scan(int img_width, int img_height);

#endif //JPEGREANDE_JPEG_H
