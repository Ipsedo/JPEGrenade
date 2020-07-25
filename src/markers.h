//
// Created by samuel on 24/07/2020.
//

#ifndef JPEGREANDE_MARKERS_H
#define JPEGREANDE_MARKERS_H

// http://vip.sugovica.hu/Sardi/kepnezo/JPEG%20File%20Layout%20and%20Format.html

/**
 * Différents marqueurs utiles pour JPEG
 */

// Common JPEG markers https://en.wikipedia.org/wiki/JPEG
#define SOI 0xD8  // Start of image
#define SOF0 0xC0 // Start of frame (baseline DCT)
#define SOF2 0xC2 // Start of frame (progressive DCT)
#define DHT 0xC4  // Define huffman Table(s)
#define DQT 0xDB  // Quantization Table(s)
#define DRI 0xDD  // Define restart interval
#define SOS 0xDA  // Start of scan
#define RST8 0xD8 // Restart n = 8
#define APP8 0xE8 // Application specific n = 8
#define COM 0xFE  // Comment
#define EOI 0xD9  // End of Image


#define EOB 0x00  // End of Block
#define ZRL 0xF0  // Zero Run Length

#endif //JPEGREANDE_MARKERS_H
