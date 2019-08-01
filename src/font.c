
// This file is generated automatically from font.txt by font.py

#include <avr/io.h>
#include <avr/pgmspace.h>
__attribute__ ((aligned (512))) PROGMEM const char font_char_scanlines[]  = {
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
// 0x08, 0x95,   // ret
// 0x08, 0x95,//0xa8, 0x2f,   // mov     r26, r24 // XL = r24
// 0x08, 0x95,//0xb9, 0x2f,   // mov     r27, r25 // XH = r25
// 0x08, 0x95,//0xf7, 0x2f,   // mov     r31, r23 // ZH = r23
// 0x08, 0x95,//0xed, 0x91,   // ld      r30, X+  // ZL = *X++
// 0x09, 0x94,   // ijmp
// 0 XXXXXX_ addr:0x604
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 1 XXXXX__ addr:0x60b
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 2 XXXX_X_ addr:0x612
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 3 XX_XXX_ addr:0x619
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 4 XX___X_ addr:0x620
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 5 X_XXXX_ addr:0x627
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 6 X__XXX_ addr:0x62e
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 7 X____X_ addr:0x635
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 8 X______ addr:0x63c
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 9 _XXXXX_ addr:0x643
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 10 _XXXX__ addr:0x64a
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 11 _XX____ addr:0x651
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 12 _X___X_ addr:0x658
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 13 __XXX__ addr:0x65f
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 14 __X____ addr:0x666
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 15 ___X___ addr:0x66d
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 16 _____X_ addr:0x674
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x98, 0xb9,   // out 0x08, r25
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp
// 17 _______ addr:0x67b
0x88, 0xb9,   // out 0x08, r24
0xed, 0x91,   // ld r30, X+
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x88, 0xb9,   // out 0x08, r24
0x09, 0x94,  // ijmp

0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
};

__attribute__ ((aligned (256))) char font_chars[]  = {
//--------------------------------------
    // char #0 ? col 0
    123 ,// _______
    // char #1 ? col 0
    123 ,// _______
    // char #2 ? col 0
    123 ,// _______
    // char #3 ? col 0
    123 ,// _______
    // char #4 ? col 0
    123 ,// _______
    // char #5 ? col 0
    123 ,// _______
    // char #6 ? col 0
    123 ,// _______
    // char #7 ? col 0
    123 ,// _______
    // char #8 ? col 0
    123 ,// _______
    // char #9 ? col 0
    123 ,// _______
    // char #10 ? col 0
    123 ,// _______
    // char #11 ? col 0
    123 ,// _______
    // char #12 ? col 0
    123 ,// _______
    // char #13 ? col 0
    123 ,// _______
    // char #14 ? col 0
    123 ,// _______
    // char #15 ? col 0
    123 ,// _______
    // char #16 ? col 0
    123 ,// _______
    // char #17 ? col 0
    123 ,// _______
    // char #18 ? col 0
    123 ,// _______
    // char #19 ? col 0
    123 ,// _______
    // char #20 ? col 0
    123 ,// _______
    // char #21 ? col 0
    123 ,// _______
    // char #22 ? col 0
    123 ,// _______
    // char #23 ? col 0
    123 ,// _______
    // char #24 ? col 0
    123 ,// _______
    // char #25 ? col 0
    123 ,// _______
    // char #26 ? col 0
    123 ,// _______
    // char #27 ? col 0
    123 ,// _______
    // char #28 ? col 0
    123 ,// _______
    // char #29 ? col 0
    123 ,// _______
    // char #30 ? col 0
    123 ,// _______
    // char #31 ? col 0
    123 ,// _______
    // char #32   col 0
    123 ,// _______
    // char #33 ! col 0
    102 ,// __X____
    // char #34 " col 0
    53 ,// X____X_
    // char #35 # col 0
    53 ,// X____X_
    // char #36 $ col 0
    102 ,// __X____
    // char #37 % col 0
    53 ,// X____X_
    // char #38 & col 0
    81 ,// _XX____
    // char #39 ' col 0
    102 ,// __X____
    // char #40 ( col 0
    102 ,// __X____
    // char #41 ) col 0
    60 ,// X______
    // char #42 * col 0
    74 ,// _XXXX__
    // char #43 + col 0
    102 ,// __X____
    // char #44 , col 0
    123 ,// _______
    // char #45 - col 0
    123 ,// _______
    // char #46 . col 0
    123 ,// _______
    // char #47 / col 0
    123 ,// _______
    // char #48 0 col 0
    4 ,// XXXXXX_
    // char #49 1 col 0
    116 ,// _____X_
    // char #50 2 col 0
    4 ,// XXXXXX_
    // char #51 3 col 0
    4 ,// XXXXXX_
    // char #52 4 col 0
    53 ,// X____X_
    // char #53 5 col 0
    4 ,// XXXXXX_
    // char #54 6 col 0
    4 ,// XXXXXX_
    // char #55 7 col 0
    4 ,// XXXXXX_
    // char #56 8 col 0
    4 ,// XXXXXX_
    // char #57 9 col 0
    4 ,// XXXXXX_
    // char #58 : col 0
    81 ,// _XX____
    // char #59 ; col 0
    81 ,// _XX____
    // char #60 < col 0
    116 ,// _____X_
    // char #61 = col 0
    123 ,// _______
    // char #62 > col 0
    60 ,// X______
    // char #63 ? col 0
    67 ,// _XXXXX_
    // char #64 @ col 0
    4 ,// XXXXXX_
    // char #65 A col 0
    74 ,// _XXXX__
    // char #66 B col 0
    74 ,// _XXXX__
    // char #67 C col 0
    74 ,// _XXXX__
    // char #68 D col 0
    11 ,// XXXXX__
    // char #69 E col 0
    11 ,// XXXXX__
    // char #70 F col 0
    11 ,// XXXXX__
    // char #71 G col 0
    74 ,// _XXXX__
    // char #72 H col 0
    53 ,// X____X_
    // char #73 I col 0
    74 ,// _XXXX__
    // char #74 J col 0
    109 ,// ___X___
    // char #75 K col 0
    53 ,// X____X_
    // char #76 L col 0
    60 ,// X______
    // char #77 M col 0
    53 ,// X____X_
    // char #78 N col 0
    53 ,// X____X_
    // char #79 O col 0
    74 ,// _XXXX__
    // char #80 P col 0
    74 ,// _XXXX__
    // char #81 Q col 0
    74 ,// _XXXX__
    // char #82 R col 0
    74 ,// _XXXX__
    // char #83 S col 0
    67 ,// _XXXXX_
    // char #84 T col 0
    11 ,// XXXXX__
    // char #85 U col 0
    53 ,// X____X_
    // char #86 V col 0
    53 ,// X____X_
    // char #87 W col 0
    53 ,// X____X_
    // char #88 X col 0
    53 ,// X____X_
    // char #89 Y col 0
    53 ,// X____X_
    // char #90 Z col 0
    4 ,// XXXXXX_
    // char #91 [ col 0
    11 ,// XXXXX__
    // char #92 \ col 0
    60 ,// X______
    // char #93 ] col 0
    67 ,// _XXXXX_
    // char #94 ^ col 0
    74 ,// _XXXX__
    // char #95 _ col 0
    123 ,// _______
    // char #96 ` col 0
    60 ,// X______
    // char #97 a col 0
    74 ,// _XXXX__
    // char #98 b col 0
    60 ,// X______
    // char #99 c col 0
    123 ,// _______
    // char #100 d col 0
    116 ,// _____X_
    // char #101 e col 0
    123 ,// _______
    // char #102 f col 0
    95 ,// __XXX__
    // char #103 g col 0
    67 ,// _XXXXX_
    // char #104 h col 0
    60 ,// X______
    // char #105 i col 0
    102 ,// __X____
    // char #106 j col 0
    109 ,// ___X___
    // char #107 k col 0
    123 ,// _______
    // char #108 l col 0
    81 ,// _XX____
    // char #109 m col 0
    123 ,// _______
    // char #110 n col 0
    123 ,// _______
    // char #111 o col 0
    123 ,// _______
    // char #112 p col 0
    123 ,// _______
    // char #113 q col 0
    123 ,// _______
    // char #114 r col 0
    123 ,// _______
    // char #115 s col 0
    123 ,// _______
    // char #116 t col 0
    102 ,// __X____
    // char #117 u col 0
    123 ,// _______
    // char #118 v col 0
    123 ,// _______
    // char #119 w col 0
    123 ,// _______
    // char #120 x col 0
    123 ,// _______
    // char #121 y col 0
    123 ,// _______
    // char #122 z col 0
    123 ,// _______
    // char #123 { col 0
    95 ,// __XXX__
    // char #124 | col 0
    102 ,// __X____
    // char #125 } col 0
    81 ,// _XX____
    // char #126 ~ col 0
    123 ,// _______
    // char #127  col 0
    102 ,// __X____
//--------------------------------------
    // char #0 ? col 1
    123 ,// _______
    // char #1 ? col 1
    123 ,// _______
    // char #2 ? col 1
    123 ,// _______
    // char #3 ? col 1
    123 ,// _______
    // char #4 ? col 1
    123 ,// _______
    // char #5 ? col 1
    123 ,// _______
    // char #6 ? col 1
    123 ,// _______
    // char #7 ? col 1
    123 ,// _______
    // char #8 ? col 1
    123 ,// _______
    // char #9 ? col 1
    123 ,// _______
    // char #10 ? col 1
    123 ,// _______
    // char #11 ? col 1
    123 ,// _______
    // char #12 ? col 1
    123 ,// _______
    // char #13 ? col 1
    123 ,// _______
    // char #14 ? col 1
    123 ,// _______
    // char #15 ? col 1
    123 ,// _______
    // char #16 ? col 1
    123 ,// _______
    // char #17 ? col 1
    123 ,// _______
    // char #18 ? col 1
    123 ,// _______
    // char #19 ? col 1
    123 ,// _______
    // char #20 ? col 1
    123 ,// _______
    // char #21 ? col 1
    123 ,// _______
    // char #22 ? col 1
    123 ,// _______
    // char #23 ? col 1
    123 ,// _______
    // char #24 ? col 1
    123 ,// _______
    // char #25 ? col 1
    123 ,// _______
    // char #26 ? col 1
    123 ,// _______
    // char #27 ? col 1
    123 ,// _______
    // char #28 ? col 1
    123 ,// _______
    // char #29 ? col 1
    123 ,// _______
    // char #30 ? col 1
    123 ,// _______
    // char #31 ? col 1
    123 ,// _______
    // char #32   col 1
    123 ,// _______
    // char #33 ! col 1
    102 ,// __X____
    // char #34 " col 1
    53 ,// X____X_
    // char #35 # col 1
    11 ,// XXXXX__
    // char #36 $ col 1
    74 ,// _XXXX__
    // char #37 % col 1
    109 ,// ___X___
    // char #38 & col 1
    60 ,// X______
    // char #39 ' col 1
    102 ,// __X____
    // char #40 ( col 1
    60 ,// X______
    // char #41 ) col 1
    102 ,// __X____
    // char #42 * col 1
    4 ,// XXXXXX_
    // char #43 + col 1
    102 ,// __X____
    // char #44 , col 1
    123 ,// _______
    // char #45 - col 1
    123 ,// _______
    // char #46 . col 1
    123 ,// _______
    // char #47 / col 1
    116 ,// _____X_
    // char #48 0 col 1
    53 ,// X____X_
    // char #49 1 col 1
    116 ,// _____X_
    // char #50 2 col 1
    116 ,// _____X_
    // char #51 3 col 1
    116 ,// _____X_
    // char #52 4 col 1
    53 ,// X____X_
    // char #53 5 col 1
    60 ,// X______
    // char #54 6 col 1
    60 ,// X______
    // char #55 7 col 1
    116 ,// _____X_
    // char #56 8 col 1
    53 ,// X____X_
    // char #57 9 col 1
    53 ,// X____X_
    // char #58 : col 1
    81 ,// _XX____
    // char #59 ; col 1
    81 ,// _XX____
    // char #60 < col 1
    102 ,// __X____
    // char #61 = col 1
    11 ,// XXXXX__
    // char #62 > col 1
    102 ,// __X____
    // char #63 ? col 1
    116 ,// _____X_
    // char #64 @ col 1
    53 ,// X____X_
    // char #65 A col 1
    53 ,// X____X_
    // char #66 B col 1
    53 ,// X____X_
    // char #67 C col 1
    60 ,// X______
    // char #68 D col 1
    53 ,// X____X_
    // char #69 E col 1
    60 ,// X______
    // char #70 F col 1
    60 ,// X______
    // char #71 G col 1
    60 ,// X______
    // char #72 H col 1
    53 ,// X____X_
    // char #73 I col 1
    102 ,// __X____
    // char #74 J col 1
    109 ,// ___X___
    // char #75 K col 1
    53 ,// X____X_
    // char #76 L col 1
    60 ,// X______
    // char #77 M col 1
    25 ,// XX_XXX_
    // char #78 N col 1
    32 ,// XX___X_
    // char #79 O col 1
    53 ,// X____X_
    // char #80 P col 1
    53 ,// X____X_
    // char #81 Q col 1
    53 ,// X____X_
    // char #82 R col 1
    53 ,// X____X_
    // char #83 S col 1
    60 ,// X______
    // char #84 T col 1
    102 ,// __X____
    // char #85 U col 1
    53 ,// X____X_
    // char #86 V col 1
    53 ,// X____X_
    // char #87 W col 1
    53 ,// X____X_
    // char #88 X col 1
    46 ,// X__XXX_
    // char #89 Y col 1
    53 ,// X____X_
    // char #90 Z col 1
    116 ,// _____X_
    // char #91 [ col 1
    60 ,// X______
    // char #92 \ col 1
    102 ,// __X____
    // char #93 ] col 1
    116 ,// _____X_
    // char #94 ^ col 1
    53 ,// X____X_
    // char #95 _ col 1
    123 ,// _______
    // char #96 ` col 1
    102 ,// __X____
    // char #97 a col 1
    116 ,// _____X_
    // char #98 b col 1
    60 ,// X______
    // char #99 c col 1
    74 ,// _XXXX__
    // char #100 d col 1
    116 ,// _____X_
    // char #101 e col 1
    74 ,// _XXXX__
    // char #102 f col 1
    102 ,// __X____
    // char #103 g col 1
    53 ,// X____X_
    // char #104 h col 1
    60 ,// X______
    // char #105 i col 1
    123 ,// _______
    // char #106 j col 1
    123 ,// _______
    // char #107 k col 1
    60 ,// X______
    // char #108 l col 1
    102 ,// __X____
    // char #109 m col 1
    53 ,// X____X_
    // char #110 n col 1
    74 ,// _XXXX__
    // char #111 o col 1
    74 ,// _XXXX__
    // char #112 p col 1
    74 ,// _XXXX__
    // char #113 q col 1
    74 ,// _XXXX__
    // char #114 r col 1
    74 ,// _XXXX__
    // char #115 s col 1
    67 ,// _XXXXX_
    // char #116 t col 1
    11 ,// XXXXX__
    // char #117 u col 1
    53 ,// X____X_
    // char #118 v col 1
    53 ,// X____X_
    // char #119 w col 1
    53 ,// X____X_
    // char #120 x col 1
    53 ,// X____X_
    // char #121 y col 1
    53 ,// X____X_
    // char #122 z col 1
    4 ,// XXXXXX_
    // char #123 { col 1
    102 ,// __X____
    // char #124 | col 1
    102 ,// __X____
    // char #125 } col 1
    109 ,// ___X___
    // char #126 ~ col 1
    123 ,// _______
    // char #127  col 1
    11 ,// XXXXX__
//--------------------------------------
    // char #0 ? col 2
    123 ,// _______
    // char #1 ? col 2
    123 ,// _______
    // char #2 ? col 2
    123 ,// _______
    // char #3 ? col 2
    123 ,// _______
    // char #4 ? col 2
    123 ,// _______
    // char #5 ? col 2
    123 ,// _______
    // char #6 ? col 2
    123 ,// _______
    // char #7 ? col 2
    123 ,// _______
    // char #8 ? col 2
    123 ,// _______
    // char #9 ? col 2
    123 ,// _______
    // char #10 ? col 2
    123 ,// _______
    // char #11 ? col 2
    123 ,// _______
    // char #12 ? col 2
    123 ,// _______
    // char #13 ? col 2
    123 ,// _______
    // char #14 ? col 2
    123 ,// _______
    // char #15 ? col 2
    123 ,// _______
    // char #16 ? col 2
    123 ,// _______
    // char #17 ? col 2
    123 ,// _______
    // char #18 ? col 2
    123 ,// _______
    // char #19 ? col 2
    123 ,// _______
    // char #20 ? col 2
    123 ,// _______
    // char #21 ? col 2
    123 ,// _______
    // char #22 ? col 2
    123 ,// _______
    // char #23 ? col 2
    123 ,// _______
    // char #24 ? col 2
    123 ,// _______
    // char #25 ? col 2
    123 ,// _______
    // char #26 ? col 2
    123 ,// _______
    // char #27 ? col 2
    123 ,// _______
    // char #28 ? col 2
    123 ,// _______
    // char #29 ? col 2
    123 ,// _______
    // char #30 ? col 2
    123 ,// _______
    // char #31 ? col 2
    123 ,// _______
    // char #32   col 2
    123 ,// _______
    // char #33 ! col 2
    102 ,// __X____
    // char #34 " col 2
    53 ,// X____X_
    // char #35 # col 2
    53 ,// X____X_
    // char #36 $ col 2
    74 ,// _XXXX__
    // char #37 % col 2
    102 ,// __X____
    // char #38 & col 2
    88 ,// _X___X_
    // char #39 ' col 2
    102 ,// __X____
    // char #40 ( col 2
    60 ,// X______
    // char #41 ) col 2
    102 ,// __X____
    // char #42 * col 2
    74 ,// _XXXX__
    // char #43 + col 2
    4 ,// XXXXXX_
    // char #44 , col 2
    123 ,// _______
    // char #45 - col 2
    74 ,// _XXXX__
    // char #46 . col 2
    123 ,// _______
    // char #47 / col 2
    109 ,// ___X___
    // char #48 0 col 2
    53 ,// X____X_
    // char #49 1 col 2
    116 ,// _____X_
    // char #50 2 col 2
    4 ,// XXXXXX_
    // char #51 3 col 2
    4 ,// XXXXXX_
    // char #52 4 col 2
    4 ,// XXXXXX_
    // char #53 5 col 2
    4 ,// XXXXXX_
    // char #54 6 col 2
    4 ,// XXXXXX_
    // char #55 7 col 2
    116 ,// _____X_
    // char #56 8 col 2
    4 ,// XXXXXX_
    // char #57 9 col 2
    4 ,// XXXXXX_
    // char #58 : col 2
    123 ,// _______
    // char #59 ; col 2
    123 ,// _______
    // char #60 < col 2
    60 ,// X______
    // char #61 = col 2
    123 ,// _______
    // char #62 > col 2
    116 ,// _____X_
    // char #63 ? col 2
    95 ,// __XXX__
    // char #64 @ col 2
    46 ,// X__XXX_
    // char #65 A col 2
    4 ,// XXXXXX_
    // char #66 B col 2
    11 ,// XXXXX__
    // char #67 C col 2
    60 ,// X______
    // char #68 D col 2
    53 ,// X____X_
    // char #69 E col 2
    11 ,// XXXXX__
    // char #70 F col 2
    11 ,// XXXXX__
    // char #71 G col 2
    46 ,// X__XXX_
    // char #72 H col 2
    4 ,// XXXXXX_
    // char #73 I col 2
    102 ,// __X____
    // char #74 J col 2
    109 ,// ___X___
    // char #75 K col 2
    11 ,// XXXXX__
    // char #76 L col 2
    60 ,// X______
    // char #77 M col 2
    18 ,// XXXX_X_
    // char #78 N col 2
    39 ,// X_XXXX_
    // char #79 O col 2
    53 ,// X____X_
    // char #80 P col 2
    11 ,// XXXXX__
    // char #81 Q col 2
    53 ,// X____X_
    // char #82 R col 2
    11 ,// XXXXX__
    // char #83 S col 2
    4 ,// XXXXXX_
    // char #84 T col 2
    102 ,// __X____
    // char #85 U col 2
    53 ,// X____X_
    // char #86 V col 2
    53 ,// X____X_
    // char #87 W col 2
    53 ,// X____X_
    // char #88 X col 2
    95 ,// __XXX__
    // char #89 Y col 2
    74 ,// _XXXX__
    // char #90 Z col 2
    74 ,// _XXXX__
    // char #91 [ col 2
    60 ,// X______
    // char #92 \ col 2
    109 ,// ___X___
    // char #93 ] col 2
    116 ,// _____X_
    // char #94 ^ col 2
    123 ,// _______
    // char #95 _ col 2
    123 ,// _______
    // char #96 ` col 2
    123 ,// _______
    // char #97 a col 2
    67 ,// _XXXXX_
    // char #98 b col 2
    11 ,// XXXXX__
    // char #99 c col 2
    60 ,// X______
    // char #100 d col 2
    67 ,// _XXXXX_
    // char #101 e col 2
    11 ,// XXXXX__
    // char #102 f col 2
    74 ,// _XXXX__
    // char #103 g col 2
    67 ,// _XXXXX_
    // char #104 h col 2
    11 ,// XXXXX__
    // char #105 i col 2
    102 ,// __X____
    // char #106 j col 2
    109 ,// ___X___
    // char #107 k col 2
    53 ,// X____X_
    // char #108 l col 2
    102 ,// __X____
    // char #109 m col 2
    25 ,// XX_XXX_
    // char #110 n col 2
    53 ,// X____X_
    // char #111 o col 2
    53 ,// X____X_
    // char #112 p col 2
    53 ,// X____X_
    // char #113 q col 2
    53 ,// X____X_
    // char #114 r col 2
    60 ,// X______
    // char #115 s col 2
    4 ,// XXXXXX_
    // char #116 t col 2
    102 ,// __X____
    // char #117 u col 2
    53 ,// X____X_
    // char #118 v col 2
    53 ,// X____X_
    // char #119 w col 2
    53 ,// X____X_
    // char #120 x col 2
    95 ,// __XXX__
    // char #121 y col 2
    67 ,// _XXXXX_
    // char #122 z col 2
    116 ,// _____X_
    // char #123 { col 2
    60 ,// X______
    // char #124 | col 2
    102 ,// __X____
    // char #125 } col 2
    116 ,// _____X_
    // char #126 ~ col 2
    32 ,// XX___X_
    // char #127  col 2
    11 ,// XXXXX__
//--------------------------------------
    // char #0 ? col 3
    123 ,// _______
    // char #1 ? col 3
    123 ,// _______
    // char #2 ? col 3
    123 ,// _______
    // char #3 ? col 3
    123 ,// _______
    // char #4 ? col 3
    123 ,// _______
    // char #5 ? col 3
    123 ,// _______
    // char #6 ? col 3
    123 ,// _______
    // char #7 ? col 3
    123 ,// _______
    // char #8 ? col 3
    123 ,// _______
    // char #9 ? col 3
    123 ,// _______
    // char #10 ? col 3
    123 ,// _______
    // char #11 ? col 3
    123 ,// _______
    // char #12 ? col 3
    123 ,// _______
    // char #13 ? col 3
    123 ,// _______
    // char #14 ? col 3
    123 ,// _______
    // char #15 ? col 3
    123 ,// _______
    // char #16 ? col 3
    123 ,// _______
    // char #17 ? col 3
    123 ,// _______
    // char #18 ? col 3
    123 ,// _______
    // char #19 ? col 3
    123 ,// _______
    // char #20 ? col 3
    123 ,// _______
    // char #21 ? col 3
    123 ,// _______
    // char #22 ? col 3
    123 ,// _______
    // char #23 ? col 3
    123 ,// _______
    // char #24 ? col 3
    123 ,// _______
    // char #25 ? col 3
    123 ,// _______
    // char #26 ? col 3
    123 ,// _______
    // char #27 ? col 3
    123 ,// _______
    // char #28 ? col 3
    123 ,// _______
    // char #29 ? col 3
    123 ,// _______
    // char #30 ? col 3
    123 ,// _______
    // char #31 ? col 3
    123 ,// _______
    // char #32   col 3
    123 ,// _______
    // char #33 ! col 3
    123 ,// _______
    // char #34 " col 3
    123 ,// _______
    // char #35 # col 3
    11 ,// XXXXX__
    // char #36 $ col 3
    74 ,// _XXXX__
    // char #37 % col 3
    53 ,// X____X_
    // char #38 & col 3
    46 ,// X__XXX_
    // char #39 ' col 3
    123 ,// _______
    // char #40 ( col 3
    60 ,// X______
    // char #41 ) col 3
    102 ,// __X____
    // char #42 * col 3
    123 ,// _______
    // char #43 + col 3
    102 ,// __X____
    // char #44 , col 3
    102 ,// __X____
    // char #45 - col 3
    123 ,// _______
    // char #46 . col 3
    81 ,// _XX____
    // char #47 / col 3
    102 ,// __X____
    // char #48 0 col 3
    53 ,// X____X_
    // char #49 1 col 3
    116 ,// _____X_
    // char #50 2 col 3
    60 ,// X______
    // char #51 3 col 3
    116 ,// _____X_
    // char #52 4 col 3
    116 ,// _____X_
    // char #53 5 col 3
    116 ,// _____X_
    // char #54 6 col 3
    53 ,// X____X_
    // char #55 7 col 3
    116 ,// _____X_
    // char #56 8 col 3
    53 ,// X____X_
    // char #57 9 col 3
    116 ,// _____X_
    // char #58 : col 3
    81 ,// _XX____
    // char #59 ; col 3
    81 ,// _XX____
    // char #60 < col 3
    102 ,// __X____
    // char #61 = col 3
    11 ,// XXXXX__
    // char #62 > col 3
    102 ,// __X____
    // char #63 ? col 3
    123 ,// _______
    // char #64 @ col 3
    46 ,// X__XXX_
    // char #65 A col 3
    53 ,// X____X_
    // char #66 B col 3
    53 ,// X____X_
    // char #67 C col 3
    60 ,// X______
    // char #68 D col 3
    53 ,// X____X_
    // char #69 E col 3
    60 ,// X______
    // char #70 F col 3
    60 ,// X______
    // char #71 G col 3
    53 ,// X____X_
    // char #72 H col 3
    53 ,// X____X_
    // char #73 I col 3
    102 ,// __X____
    // char #74 J col 3
    109 ,// ___X___
    // char #75 K col 3
    53 ,// X____X_
    // char #76 L col 3
    53 ,// X____X_
    // char #77 M col 3
    53 ,// X____X_
    // char #78 N col 3
    46 ,// X__XXX_
    // char #79 O col 3
    53 ,// X____X_
    // char #80 P col 3
    60 ,// X______
    // char #81 Q col 3
    46 ,// X__XXX_
    // char #82 R col 3
    46 ,// X__XXX_
    // char #83 S col 3
    116 ,// _____X_
    // char #84 T col 3
    102 ,// __X____
    // char #85 U col 3
    53 ,// X____X_
    // char #86 V col 3
    46 ,// X__XXX_
    // char #87 W col 3
    39 ,// X_XXXX_
    // char #88 X col 3
    32 ,// XX___X_
    // char #89 Y col 3
    102 ,// __X____
    // char #90 Z col 3
    60 ,// X______
    // char #91 [ col 3
    60 ,// X______
    // char #92 \ col 3
    116 ,// _____X_
    // char #93 ] col 3
    116 ,// _____X_
    // char #94 ^ col 3
    123 ,// _______
    // char #95 _ col 3
    123 ,// _______
    // char #96 ` col 3
    123 ,// _______
    // char #97 a col 3
    53 ,// X____X_
    // char #98 b col 3
    53 ,// X____X_
    // char #99 c col 3
    60 ,// X______
    // char #100 d col 3
    53 ,// X____X_
    // char #101 e col 3
    60 ,// X______
    // char #102 f col 3
    102 ,// __X____
    // char #103 g col 3
    116 ,// _____X_
    // char #104 h col 3
    53 ,// X____X_
    // char #105 i col 3
    102 ,// __X____
    // char #106 j col 3
    109 ,// ___X___
    // char #107 k col 3
    11 ,// XXXXX__
    // char #108 l col 3
    102 ,// __X____
    // char #109 m col 3
    18 ,// XXXX_X_
    // char #110 n col 3
    53 ,// X____X_
    // char #111 o col 3
    53 ,// X____X_
    // char #112 p col 3
    11 ,// XXXXX__
    // char #113 q col 3
    67 ,// _XXXXX_
    // char #114 r col 3
    60 ,// X______
    // char #115 s col 3
    116 ,// _____X_
    // char #116 t col 3
    102 ,// __X____
    // char #117 u col 3
    53 ,// X____X_
    // char #118 v col 3
    46 ,// X__XXX_
    // char #119 w col 3
    39 ,// X_XXXX_
    // char #120 x col 3
    32 ,// XX___X_
    // char #121 y col 3
    116 ,// _____X_
    // char #122 z col 3
    74 ,// _XXXX__
    // char #123 { col 3
    102 ,// __X____
    // char #124 | col 3
    102 ,// __X____
    // char #125 } col 3
    109 ,// ___X___
    // char #126 ~ col 3
    74 ,// _XXXX__
    // char #127  col 3
    60 ,// X______
//--------------------------------------
    // char #0 ? col 4
    123 ,// _______
    // char #1 ? col 4
    123 ,// _______
    // char #2 ? col 4
    123 ,// _______
    // char #3 ? col 4
    123 ,// _______
    // char #4 ? col 4
    123 ,// _______
    // char #5 ? col 4
    123 ,// _______
    // char #6 ? col 4
    123 ,// _______
    // char #7 ? col 4
    123 ,// _______
    // char #8 ? col 4
    123 ,// _______
    // char #9 ? col 4
    123 ,// _______
    // char #10 ? col 4
    123 ,// _______
    // char #11 ? col 4
    123 ,// _______
    // char #12 ? col 4
    123 ,// _______
    // char #13 ? col 4
    123 ,// _______
    // char #14 ? col 4
    123 ,// _______
    // char #15 ? col 4
    123 ,// _______
    // char #16 ? col 4
    123 ,// _______
    // char #17 ? col 4
    123 ,// _______
    // char #18 ? col 4
    123 ,// _______
    // char #19 ? col 4
    123 ,// _______
    // char #20 ? col 4
    123 ,// _______
    // char #21 ? col 4
    123 ,// _______
    // char #22 ? col 4
    123 ,// _______
    // char #23 ? col 4
    123 ,// _______
    // char #24 ? col 4
    123 ,// _______
    // char #25 ? col 4
    123 ,// _______
    // char #26 ? col 4
    123 ,// _______
    // char #27 ? col 4
    123 ,// _______
    // char #28 ? col 4
    123 ,// _______
    // char #29 ? col 4
    123 ,// _______
    // char #30 ? col 4
    123 ,// _______
    // char #31 ? col 4
    123 ,// _______
    // char #32   col 4
    123 ,// _______
    // char #33 ! col 4
    102 ,// __X____
    // char #34 " col 4
    123 ,// _______
    // char #35 # col 4
    53 ,// X____X_
    // char #36 $ col 4
    102 ,// __X____
    // char #37 % col 4
    123 ,// _______
    // char #38 & col 4
    67 ,// _XXXXX_
    // char #39 ' col 4
    123 ,// _______
    // char #40 ( col 4
    102 ,// __X____
    // char #41 ) col 4
    60 ,// X______
    // char #42 * col 4
    123 ,// _______
    // char #43 + col 4
    102 ,// __X____
    // char #44 , col 4
    81 ,// _XX____
    // char #45 - col 4
    123 ,// _______
    // char #46 . col 4
    81 ,// _XX____
    // char #47 / col 4
    60 ,// X______
    // char #48 0 col 4
    4 ,// XXXXXX_
    // char #49 1 col 4
    116 ,// _____X_
    // char #50 2 col 4
    4 ,// XXXXXX_
    // char #51 3 col 4
    4 ,// XXXXXX_
    // char #52 4 col 4
    116 ,// _____X_
    // char #53 5 col 4
    4 ,// XXXXXX_
    // char #54 6 col 4
    4 ,// XXXXXX_
    // char #55 7 col 4
    116 ,// _____X_
    // char #56 8 col 4
    4 ,// XXXXXX_
    // char #57 9 col 4
    4 ,// XXXXXX_
    // char #58 : col 4
    81 ,// _XX____
    // char #59 ; col 4
    102 ,// __X____
    // char #60 < col 4
    116 ,// _____X_
    // char #61 = col 4
    123 ,// _______
    // char #62 > col 4
    60 ,// X______
    // char #63 ? col 4
    102 ,// __X____
    // char #64 @ col 4
    46 ,// X__XXX_
    // char #65 A col 4
    53 ,// X____X_
    // char #66 B col 4
    11 ,// XXXXX__
    // char #67 C col 4
    74 ,// _XXXX__
    // char #68 D col 4
    11 ,// XXXXX__
    // char #69 E col 4
    11 ,// XXXXX__
    // char #70 F col 4
    60 ,// X______
    // char #71 G col 4
    67 ,// _XXXXX_
    // char #72 H col 4
    53 ,// X____X_
    // char #73 I col 4
    74 ,// _XXXX__
    // char #74 J col 4
    81 ,// _XX____
    // char #75 K col 4
    53 ,// X____X_
    // char #76 L col 4
    4 ,// XXXXXX_
    // char #77 M col 4
    53 ,// X____X_
    // char #78 N col 4
    53 ,// X____X_
    // char #79 O col 4
    74 ,// _XXXX__
    // char #80 P col 4
    60 ,// X______
    // char #81 Q col 4
    74 ,// _XXXX__
    // char #82 R col 4
    53 ,// X____X_
    // char #83 S col 4
    11 ,// XXXXX__
    // char #84 T col 4
    102 ,// __X____
    // char #85 U col 4
    74 ,// _XXXX__
    // char #86 V col 4
    102 ,// __X____
    // char #87 W col 4
    25 ,// XX_XXX_
    // char #88 X col 4
    53 ,// X____X_
    // char #89 Y col 4
    102 ,// __X____
    // char #90 Z col 4
    4 ,// XXXXXX_
    // char #91 [ col 4
    11 ,// XXXXX__
    // char #92 \ col 4
    123 ,// _______
    // char #93 ] col 4
    67 ,// _XXXXX_
    // char #94 ^ col 4
    123 ,// _______
    // char #95 _ col 4
    4 ,// XXXXXX_
    // char #96 ` col 4
    123 ,// _______
    // char #97 a col 4
    67 ,// _XXXXX_
    // char #98 b col 4
    74 ,// _XXXX__
    // char #99 c col 4
    74 ,// _XXXX__
    // char #100 d col 4
    67 ,// _XXXXX_
    // char #101 e col 4
    74 ,// _XXXX__
    // char #102 f col 4
    102 ,// __X____
    // char #103 g col 4
    74 ,// _XXXX__
    // char #104 h col 4
    53 ,// X____X_
    // char #105 i col 4
    102 ,// __X____
    // char #106 j col 4
    81 ,// _XX____
    // char #107 k col 4
    53 ,// X____X_
    // char #108 l col 4
    102 ,// __X____
    // char #109 m col 4
    53 ,// X____X_
    // char #110 n col 4
    53 ,// X____X_
    // char #111 o col 4
    74 ,// _XXXX__
    // char #112 p col 4
    60 ,// X______
    // char #113 q col 4
    116 ,// _____X_
    // char #114 r col 4
    60 ,// X______
    // char #115 s col 4
    11 ,// XXXXX__
    // char #116 t col 4
    95 ,// __XXX__
    // char #117 u col 4
    74 ,// _XXXX__
    // char #118 v col 4
    102 ,// __X____
    // char #119 w col 4
    25 ,// XX_XXX_
    // char #120 x col 4
    53 ,// X____X_
    // char #121 y col 4
    74 ,// _XXXX__
    // char #122 z col 4
    4 ,// XXXXXX_
    // char #123 { col 4
    95 ,// __XXX__
    // char #124 | col 4
    102 ,// __X____
    // char #125 } col 4
    81 ,// _XX____
    // char #126 ~ col 4
    123 ,// _______
    // char #127  col 4
    11 ,// XXXXX__

};
