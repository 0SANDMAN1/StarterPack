/*
 * STD_Types.h
 *
 * Created: 9/23/2023 1:41:25 PM
 *  Author: user
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef char s8; // byte: 1 range: -128 to 127 format specifier %c
typedef unsigned char u8; // byte: 1 range: 0 to 255 format specifier %c
typedef short s16; // byte: 2 range: -32,768 to 32,767 format specifier %hd
typedef unsigned short u16; // byte: 2 range: 0 to 65535 format specifier %hu
typedef long s32; // byte: 8 or 4(32-Bit) range: -9223372036854775808 to 9223372036854775807 format specifier %ld
typedef unsigned long u32; // byte: 8 range: 0 to 18446744073709551615 format specifier %lu

typedef enum{
	STD_Low=0,
	STD_High
}STD_LevelTypes;

#endif /* STD_TYPES_H_ */