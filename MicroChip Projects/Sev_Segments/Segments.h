#include "DIO.h"
#ifndef SEGMENTS_H
#define SEGMENTS_H

#define Seg_PortA PortA
#define Seg_PortB PortB
#define Seg_PortC PortC
#define Seg_PortD PortD

#define Seg_Pin0 Pin0
#define Seg_Pin1 Pin1
#define Seg_Pin2 Pin2
#define Seg_Pin3 Pin3
#define Seg_Pin4 Pin4
#define Seg_Pin5 Pin5
#define Seg_Pin6 Pin6
#define Seg_Pin7 Pin7

#define Seg_EN1 1
#define Seg_EN2 2

void Seg_Init(uint8 segment_ID);
void Seg_Display(uint8 number);

#endif