//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#ifndef JPEGREANDE_TYPES_H
#define JPEGREANDE_TYPES_H

#include <memory>
#include <vector>
#include <cstddef>
#include <unordered_map>

/*
 * Différents types des étapes du pipeline de compression JPEG
 *
 */

/**
 * type pour le block 8 * 8 px
 * grey scale
 */
typedef struct block { int values[8][8]; } block;

/**
 * Sortie de l'encodage zigzag
 */
typedef struct zigzag_block { int values[64]; } zigzag_block;

/**
 * On définit le type pair_rle :
 * byte, un octet dont :
 * 	- les 4 premier bits représentent le nombre de 0 (Codage RLE sur 0)
 * 	- les 4 dernier bits représentent la magnitude du prochain coefficient non-nul
 * byte, le prochain coefficient non-nul
 */
typedef std::tuple<uint8_t, uint8_t> pair_rle;

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
 * byte : idem que pour pair_rle
 * bits_array : la représentation binaire du coefficient DC ou AC
 */
typedef std::tuple<uint8_t, bits_array> pair_dc_ac;

/**
 * Sortie de l'encodage AC DC  _\m/
 */
typedef std::vector<pair_dc_ac> dc_ac_block;

/*
 * Huffman types déclaration
 *
 */

/**
 * Template for B-Tree
 * @tparam T node data
 */
template<typename T>
struct node {
    double probability;
    T data;

    std::shared_ptr<node<T>> inf;
    std::shared_ptr<node<T>> sup;

    /**
     * Test if the node is a leaf
     * ie if both children are not defined
     *
     * @return if node is leaf
     */
    bool is_leaf() {
        return !inf & !sup;
    }
};

/**
 * Huffman tables types def
 */
typedef std::unordered_map<uint8_t, bits_array> huffman_table;
typedef std::unordered_map<bits_array, uint8_t> inv_huffman_table;
typedef std::unordered_map<uint8_t, double> bytes_freq;

/*
 * Encoded image wrapper
 * - use for pipeline
 * - and store image metadata
 */

/**
 * Grey scale jpeg dans un premier temps
 */
typedef struct img_white {
    int nb_block_w;
    int nb_block_h;

    /**
     * 2^16 = 65 536
     * 65 536 / 8 = 8 192
     * 8 192^2 = 67 108 864 blocs à générer :)
     *
     * `white_block` à répéter nb_block_w * nb_block_h fois
     */
    block white_block;

    block quant_matrix;

    huffman_table huff_table;
    inv_huffman_table inv_huff_table;
} img_white;

#endif //JPEGREANDE_TYPES_H
