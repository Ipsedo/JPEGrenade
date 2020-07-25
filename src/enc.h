//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_ENC_H
#define JPEGREANDE_ENC_H

#include "types.h"

// 1 : DCT
block dct(block p_block);

// 2 : Quantize
block quantize(block curr_block, block quantize_matrix);

// 3 : Zig-Zag scanning
zigzag_block zigzag_encode(block q_block);

// 4 : RLE
rle_block rle(zigzag_block z_block);

// 5 : AC DC
dc_ac_block dc_ac(rle_block r_block);

// 6 : Huffman
bits_array huffman(dc_ac_block d_block, huffman_table table);

#endif //JPEGREANDE_ENC_H
