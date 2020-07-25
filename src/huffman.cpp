//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#include "huffman.h"

std::tuple<huffman_table, huffman_table> compute_huffman(std::vector<dc_ac_block> d_blocks) {
    // First count bytes occurence
    bytes_freq dc_freq;
    bytes_freq ac_freq;

    for (auto p_b : d_blocks) {
        pair_dc_ac dc = p_b[0];
        std::byte magn = std::get<0>(dc);
        bits_array dc_bits = std::get<1>(dc);

        if (dc_freq.find(magn) == dc_freq.end())
            dc_freq[magn] = 0.;

        dc_freq[magn] += 1.;

        dc_ac_block ac_pairs(p_b.begin() + 1, p_b.end());

        for (auto ac : ac_pairs) {
            std::byte zero_n_magn = std::get<0>(ac);
            bits_array ac_bits = std::get<1>(ac);

            if (ac_freq.find(zero_n_magn) == ac_freq.end())
                ac_freq[zero_n_magn] = 0.;

            ac_freq[zero_n_magn] += 1.;
        }
    }

    for (auto k_v : dc_freq) {
        std::byte key = k_v.first;
        double count = k_v.second;
        dc_freq[key] = count / dc_freq.size();
    }

    for (auto k_v : ac_freq) {
        std::byte key = k_v.first;
        double count = k_v.second;
        ac_freq[key] = count / ac_freq.size();
    }

    return std::tuple<huffman_table, huffman_table>();
}
