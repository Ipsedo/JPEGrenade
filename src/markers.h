//
// Created by samuel on 24/07/2020.
//

#ifndef JPEGREANDE_MARKERS_H
#define JPEGREANDE_MARKERS_H

// La bible :
// https://www.w3.org/Graphics/JPEG/itu-t81.pdf

/**
 * Différents marqueurs utiles pour JPEG
 */

// Common JPEG markers https://en.wikipedia.org/wiki/JPEG
// https://www.disktuna.com/list-of-jpeg-markers/

// Ceux dont on a besoin
#define PAD 0xFF
#define SOI 0xD8  // Start of image
#define SOF1 0xC1 // Start of frame (baseline DCT)
#define SOS 0xDA  // Start of scan
#define DQT 0xDB  // Quantization Table(s)
#define DHT 0xC4  // Define huffman Table(s)

// pas utilisés pour le moment
#define DRI 0xDD  // Define restart interval
#define RST8 0xD8 // Restart n = 8
#define APP8 0xE8 // Application specific n = 8
#define COM 0xFE  // Comment
#define EOI 0xD9  // End of Image


#define EOB 0x00  // End of Block
#define ZRL 0xF0  // Zero Run Length

#endif //JPEGREANDE_MARKERS_H
