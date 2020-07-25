//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#include "enc.h"

// https://github.com/asad82/Zigzag-Scan/blob/master/ZigZagScan.cpp <3
zigzag_block zigzag_encode(block curr_block) {
    int count = 0;
    std::byte tmp_store[8];
    zigzag_block res(64, std::byte{0});

    // Get the First half of the data
    for (int i = 0; i < 7; i++) {
        if (i == 0) res[count++] = curr_block.values[i][i];

        if (i > 0) {
            int index = 0;

            for (int k = i, col = 0; k >= 0; k--, col++) tmp_store[index++] = curr_block.values[k][col];

            if (i % 2 == 0) for (int k = 0; k < index; k++) res[count++] = tmp_store[k];
            else  for (int k = index - 1; k >= 0; k--) res[count++] = tmp_store[k];
        }
    }

    // Get the second half of the data
    for (int i = 0; i < 8; i++) {
        int index = 0;
        for (int k = i, col = 7; k < 8; k++, col--) tmp_store[index++] = curr_block.values[k][col];


        if (i % 2 == 0) for (int k = 0; k < index; k++) res[count++] = tmp_store[k];
        else for (int k = index - 1; k >= 0; k--) res[count++] = tmp_store[k];
    }

    return res;
}

block quantize(block curr_block, block quant_mtrix){
    return block();
}

block dct(block p_block) {
    return block();
}

rle_block rle(zigzag_block z_block) {
    return rle_block();
}

dc_ac_block dc_ac(rle_block r_block) {
    return dc_ac_block();
}

bits_array huffman(dc_ac_block d_block, huffman_table table) {
    return bits_array();
}
