//
// Created by samuel on 25/07/2020.
// You need to cite the author by referencing : https://github.com/Ipsedo
//

#include <iostream>
#include <string>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <cmath>

#include "jpeg.h"
#include "markers.h"

std::vector<std::byte> get_jpeg_header(int px_size_x, int px_size_y) {
    return std::vector<std::byte>();
}

std::vector<uint8_t> get_frame_header(uint8_t nf, uint16_t max_y, uint16_t max_x, uint8_t h, uint8_t v) {

    if (h < 1u || 4u < h) {
        std::cout << "Frame horizontal scale factor must be [1 - 4], "
                     "actual = " << h << std::endl;
        exit(1);
    }

    if (v < 1u || 4u < v) {
        std::cout << "Frame vertical scale factor must be [1 - 4], "
                     "actual = " << v << std::endl;
        exit(1);
    }

    if (nf < 1u) {
        std::cout << "Number of image component in frame must be > 1, "
                     "actual = " << nf << std::endl;
        exit(1);
    }

    if (max_x > (1u << 14u) || max_y > (1u << 14u)) {
        std::cout << "JPEG max side size is 2^14, actual : max_y = "
        << max_y << ", max_x = " << max_x << std::endl;
        exit(1);
    }

    uint16_t lf = 8u + 3u * nf;
    uint8_t p = 8u; // RGB [0 - 255]

    std::vector<uint8_t> header
    {PAD, SOF1,
     (uint8_t) (lf >> 8u), (uint8_t) lf,
     p,
     (uint8_t) (max_y >> 8u), (uint8_t) max_y,
     (uint8_t) (max_x >> 8u), (uint8_t) max_x,
     nf
    };

    h <<= 4u;
    uint8_t h_v_i = h | v;
    for (size_t i = 0; i < nf; i++) {
        uint8_t c_i = i;
        uint8_t t_q_i = 0; // Quant table ID

        header.insert(header.end(), {c_i, h_v_i, t_q_i});
    }

    return header;
}

std::vector<uint8_t> get_scan_header(uint8_t ns, uint8_t nf, uint8_t cs_start) {
    if (ns < 1 || 4 < ns) {
        std::cout << "Number of scan component must be [1 - 4], actual = " << ns << std::endl;
        exit(1);
    }
    if (ns > nf) {
        std::cout << "\"Csj shall be a member of the set of Ci specified in the frame header.\"" << std::endl
                  << "Number of scan greater than number of frame : ns = " << ns << ", nf = " << nf << std::endl;
        exit(1);
    }

    uint16_t ls = 6 + 2 * ns;

    std::vector<uint8_t> header
    {PAD, SOS,
     (uint8_t) (ls >> 8u), (uint8_t) ls, ns};

    for (size_t j = 0; j < ns; j++) {
        uint8_t c_s_j = cs_start + j;
        uint8_t t_d_j = 0; // DC entropy coding table selector
        uint8_t t_a_j = 0; // AC entropy coding table selector

        header.insert(header.end(), {c_s_j, t_d_j, t_a_j});
    }

    // Sequential DCT -> calcul de [0-63] 2^6 coeffs
    uint8_t ss = 0;
    uint8_t se = 63;

    uint8_t ah = 0uL << 4u;
    uint8_t al = 0uL;
    uint8_t ah_al = ah | al;

    header.insert(header.end(), {ss, se, ah_al});

    return header;
}

std::vector<dc_ac_block> get_black_scan(int img_width, int img_height) {
    if (img_width != img_height) {
        std::cout << "Image width and height are different : w = " << img_width << ", h = " << img_height << std::endl;
        exit(1);
    }

    if (img_width % 8 != 0 || img_height % 8 != 0) {
        std::cout << "Image width or height are not multiple of 8 : w % 8 == "
                  << img_width % 8 << ", h % 8 == " << img_height % 8 << std::endl;
        exit(1);
    }

    return std::vector<dc_ac_block>();
}

std::vector<uint8_t> code_quant_table(block quant_table, uint8_t tq) {
    std::vector<uint8_t> quant_table_bytes{PAD, DQT};

    uint16_t lq = 2 + 65 * 8 * 8; // length
    uint8_t pq = 0;

    quant_table_bytes.insert(quant_table_bytes.end(), {(uint8_t) (lq >> 8u), (uint8_t) lq, pq, tq});

    for (size_t k = 0; k < 8 * 8; k++)
        quant_table_bytes.push_back((uint8_t) (size_t) quant_table.values[int(floor(k / 8.))][k % 8]);

    return quant_table_bytes;
}

std::vector<uint8_t> code_huffman_table_syntax(const huffman_table table, uint8_t tc, uint8_t th) {
    std::vector<uint8_t> huffman_table_bytes{PAD, DHT};

    uint16_t lh = 0;

    return huffman_table_bytes;
}

std::vector<uint8_t> code_huffman_table(const huffman_table table) {
    std::vector<uint16_t> bits;
    std::vector<uint8_t> keys;

    for (const auto k_v : table) {
        std::vector<bool> huffman_code = k_v.second;
        uint8_t value = k_v.first;

        keys.push_back(value);

        auto code_length = (uint16_t) huffman_code.size();

        std::vector<std::string> str_code(huffman_code.size());
        std::transform(huffman_code.begin(), huffman_code.end(), str_code.begin(), [](bool b){ return b ? "1" : "0"; });
        std::string code_str = std::accumulate(str_code.begin(), str_code.end(), std::string{});

        code_str += std::string(16 - code_str.size(), '0');

        auto code = (uint16_t) std::bitset<16>(code_str).to_ulong();
    }

    return std::vector<uint8_t>();
}
