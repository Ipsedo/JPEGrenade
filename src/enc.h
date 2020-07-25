//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_ENC_H
#define JPEGREANDE_ENC_H

#include "types.h"

// 1 : DCT
/**
 *
 * @param p_block
 * @return
 */
block dct(block p_block);

// 2 : Quantize
/**
 *
 * @param curr_block
 * @param quantize_matrix
 * @return
 */
block quantize(block curr_block, block quantize_matrix);

// 3 : Zig-Zag scanning
/**
 *
 * @param q_block
 * @return
 */
zigzag_block zigzag_encode(block q_block);

// 4 : RLE
/**
 *
 * @param z_block
 * @return
 */
rle_block rle(zigzag_block z_block);

// 5 : AC DC
/**
 *
 * @param r_block
 * @return
 */
dc_ac_block dc_ac(rle_block r_block);

// 6 : Huffman
/**
 *
 * @param d_block
 * @param table
 * @return
 */
bits_array huffman(dc_ac_block d_block, huffman_table table);

#endif //JPEGREANDE_ENC_H
