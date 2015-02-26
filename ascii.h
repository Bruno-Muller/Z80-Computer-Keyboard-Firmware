/* 
 * File:   ascii.h
 * Author: Bruno
 *
 * Created on 20 f�vrier 2015, 23:18
 */

#ifndef ASCII_H
#define	ASCII_H

#define LOOKUP_TABLE_SIZE 0x84

const unsigned char unshifted[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 'a',  '&',  0x00,
0x00, 0x00, 'w',  's',  'q',  'z',  '�',  0x00,
0x00, 'c',  'x',  'd',  'e',  0x27, 0x22, 0x00,
0x00, ' ',  'v',  'f',  't',  'r',  '(',  0x00,
0x00, 'n',  'b',  'h',  'g',  'y',  '-',  0x00,
0x00, 0x00, ',',  'j',  'u',  '�',  '_',  0x00,
0x00, ';',  'k',  'i',  'o',  '�',  '�',  0x00,
0x00, ':',  '!',  'l',  'm',  'p',  ')',  0x00,
0x00, 0x00, '�',  0x00, '^',  '=',  0x00, 0x00,
0x00, 0x00, 0x0D, '$',  0x00, '*',  0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, '1',  0x00, '4',  '7',  0x00, 0x00, 0x00,
'0',  '.',  '2',  '5',  '6',  '8',  0x1B, 0x00,
0x00, '+',  '3',  '-',  '*',  '9',  0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};

const unsigned char shifted[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 'A',  '1',  0x00,
0x00, 0x00, 'W',  'S',  'Q',  'Z',  '2',  0x00,
0x00, 'C',  'X',  'D',  'E',  '4',  '3',  0x00,
0x00, ' ',  'V',  'F',  'T',  'R',  '5',  0x00,
0x00, 'N',  'B',  'H',  'G',  'Y',  '6',  0x00,
0x00, 0x00, '?',  'J',  'U',  '7',  '8',  0x00,
0x00, '.',  'K',  'I',  'O',  '0',  '9',  0x00,
0x00, '/',  0x00, 'L',  'M',  'P',  '�',  0x00,
0x00, 0x00, '%',  0x00, '�',  '*',  0x00, 0x00,
0x00, 0x00, 0x0D, '�',  0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};

const unsigned char altered[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, '~',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, '{',  '#',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, '[',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, '|',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, '`',  0x5C, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, '@',  '^',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, ']',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, '}',  0x00, 0x00,
0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};

#endif	/* ASCII_H */

