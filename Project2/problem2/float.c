#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {
    // get exponent
    unsigned int* pt = (unsigned int*) (&f);
    unsigned int exp = ((*pt) >> 23) & 0xff;

    if (exp==255){
        return 1;
    }

    return 0;

}


float get_M  ( float f ) {
    // convert float pointer to int pointer
	unsigned int* pt = (unsigned int*) (&f);
    
    // get exponent
    unsigned int exp = ((*pt) >> 23) & 0xff;

    // get mantisa bits
    unsigned int man = (*pt) & (0x007fffff);
    man = man | 0x3f800000; // set exp to 127 and thus E to 0

    // convert mantisa back to decimal
    if ((exp != 0) && (exp != 255)){
        return *((float*) &man);
    } else {
        return *((float*) &man) - 1;
    }
    
    return 0.0; 
}


int get_s ( float f ) {

    // convert float pointer to int pointer
	unsigned int* pt = (unsigned int*) (&f);
    unsigned int sign = (*pt) >> 31;

	return 1 - ((signed int) sign) * 2;
}


int get_E ( float f ) {
    // convert float pointer to int pointer
	unsigned int* pt = (unsigned int*) (&f);

    // get rid of all mantissa bits
    unsigned int exp = (*pt) >> 23;

    // get rid of sign bit
    exp = (exp & 0xff);

    if (exp == 0) {
        return -126; // denormalized
    } else if (exp == 255)
    {
        return 255; // special values
    }
    
    return exp - 127;
}













      



    
    
