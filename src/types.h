//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_TYPES_H
#define JPEGREANDE_TYPES_H

#include <vector>
#include <cstddef>
#include <unordered_map>

/**
 * type pour le block 8 * 8 px
 * grey scale
 */
typedef std::byte block[8][8];

/**
 * Sortie de l'encodage zigzag
 */
typedef  std::vector<std::byte> zigzag_block;

/**
 * On définit le type pair_rle :
 * unsigned char, un octet dont :
 * 	- les 4 premier bits représentent le nombre de 0 (Codage RLE sur 0)
 * 	- les 4 dernier bits représentent la magnitude du prochain coefficient non-nul
 * int, le prochain coefficient non-nul
 */
typedef std::tuple<std::byte, std::byte> pair_rle;

/**
 * Sortie de l'encodage RLE
 */
typedef std::vector<pair_rle> rle_block;

/**
 * Suite de bits
 */
typedef std::vector<bool> bits_array;

/**
 * On définit un type pair_dc_ac
 * unsigned char : idem que pour pair_rle
 * std::string : la représentation binaire du coefficient DC ou AC
 */
typedef std::tuple<std::byte, bits_array> pair_dc_ac;

/**
 * Sortie de l'encodage AC DC  _\m/
 */
typedef std::vector<pair_dc_ac> dc_ac_block;

/**
 * Huffman tables types def
 */
typedef std::unordered_map<std::byte, bits_array> huffman_table;
typedef std::unordered_map<bits_array, std::byte> inv_huffman_table;

/**
 * Grey scale jpeg dans un premier temps
 */
struct img_white {
    int nb_block_w;
    int nb_block_h;

    /**
     * 2^16 = 65 536
     * 65 536 / 8 = 8 192
     * 8 192^2 = 67 108 864 de blocks à générer :)
     *
     * `white_block` à répéter nb_block_w * nb_block_h fois
     */
    block white_block;

    block quant_matrix;

    huffman_table huff_table;
    inv_huffman_table inv_huff_table;
};

#endif //JPEGREANDE_TYPES_H
