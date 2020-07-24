//
// Created by samuel on 24/07/2020.
//

#ifndef JPEGREANDE_MARKERS_H
#define JPEGREANDE_MARKERS_H

// http://vip.sugovica.hu/Sardi/kepnezo/JPEG%20File%20Layout%20and%20Format.htm

/**
 * Différents marqueurs utiles pour JPEG
 */
#define SOI 0xD8 // Start of image
#define SOS 0xDA // Start of scan
#define EOI 0xD9 // End of Image
#define DQT 0xDB // Quantization Table
#define EOB 0x00 // End of Block
#define ZRL 0xF0 // Zero Run Length

#endif //JPEGREANDE_MARKERS_H
