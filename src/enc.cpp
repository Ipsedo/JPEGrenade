//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#include <cmath>

#include "enc.h"

int dct_one(block p_block, int i, int j) {
    double sum = 0.;
    double den = 1. / (2. * 8.);

    for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++)
        sum += p_block.values[x][y] *
                cos((2. * x + 1.) * i * M_PI * den) *
                cos((2. * y * 1.) * j * M_PI * den);

    double den_2 = 1. / sqrt(2.);
    // i == 0 ?, j == 0 ?
    double c_i = !i ? den_2 : 1., c_j = !j ? den_2 : 1.;

    return int(2. * c_i * c_j * sum / 8.);

}

block dct(block p_block) {
    block res;

    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
        res.values[i][j] = dct_one(p_block, i, j);

    return res;
}

block quantize(block curr_block, block quant_matrix){
    block res;

    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
        res.values[i][j] = curr_block.values[i][j] / quant_matrix.values[i][j];

    return res;
}

// https://github.com/asad82/Zigzag-Scan/blob/master/ZigZagScan.cpp <3
zigzag_block zigzag_encode(block curr_block) {
    int count = 0;
    int tmp_store[8]{0, 0, 0, 0, 0, 0, 0, 0};
    zigzag_block res;

    // Get the First half of the data
    for (int i = 0; i < 7; i++) {
        if (i == 0) res.values[count++] = curr_block.values[i][i];

        if (i > 0) {
            int index = 0;

            for (int k = i, col = 0; k >= 0; k--, col++) tmp_store[index++] = curr_block.values[k][col];

            if (i % 2 == 0) for (int k = 0; k < index; k++) res.values[count++] = tmp_store[k];
            else  for (int k = index - 1; k >= 0; k--) res.values[count++] = tmp_store[k];
        }
    }

    // Get the second half of the data
    for (int i = 0; i < 8; i++) {
        int index = 0;
        for (int k = i, col = 7; k < 8; k++, col--) tmp_store[index++] = curr_block.values[k][col];


        if (i % 2 == 0) for (int k = 0; k < index; k++) res.values[count++] = tmp_store[k];
        else for (int k = index - 1; k >= 0; k--) res.values[count++] = tmp_store[k];
    }

    return res;
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
