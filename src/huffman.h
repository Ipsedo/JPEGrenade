//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_HUFFMAN_H
#define JPEGREANDE_HUFFMAN_H

#include <tuple>

#include "types.h"

/**
 *
 * @param d_block
 * @return
 */
std::tuple<huffman_table, huffman_table>
        compute_huffman(dc_ac_block d_block);


#endif //JPEGREANDE_HUFFMAN_H
