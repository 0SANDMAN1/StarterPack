#ifndef STD_H
#define STD_H

typedef unsigned char uint8; // byte: 1 range: 0 to 255 format specifier %c
typedef char Int8; // byte: 1 range: -128 to 127 format specifier %c
typedef unsigned short uint16; // byte: 2 range: 0 to 65535 format specifier %hu
typedef short int16; // byte: 2 range: -32,768 to 32,767 format specifier %hd
typedef unsigned int uint32; // byte: 4 range: 0 to 4,294,967,295  format specifier %u
typedef int int32; // byte: 4 range: -2,147,483,648 to 2,147,483,647  format specifier %d
typedef enum { FALSE, TRUE } Bool; // Conventionally, use uppercase for enum members

#endif