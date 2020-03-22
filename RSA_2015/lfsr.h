//
//  lfsr.h
//  LFSR_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 4/13/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#ifndef __LFSR_2015__lfsr__
#define __LFSR_2015__lfsr__


#include "funcTeoNums.h"

class LFSR
{
private:
    vector<bool> num;
    int sem,tam;
    uint64_t tmp;
    string semS,cad;
    ZZ tempZZ,tempZZ2;
public:
    LFSR(unsigned int);
    LFSR(){};
    //LFSR(ZZ);
    string genSemilla(unsigned int);
    string genCadenaBit(unsigned int,string);
    void nuevoNum(unsigned int);
    ZZ getNum();
    
};

uint64_t getSemilla();
unsigned int getRandMod(unsigned int);

#endif /* defined(__LFSR_2015__lfsr__) */
