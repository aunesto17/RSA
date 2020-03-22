//
//  lfsr.cpp
//  LFSR_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 4/13/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "lfsr.h"


LFSR::LFSR(unsigned int t)
{
    if (t < 64) {
        semS    = genSemilla(t);
        tempZZ  = a_entero<ZZ>(semS);
    }
    else{
        semS = genSemilla(t);
        cad  = genCadenaBit(t,semS);
        tempZZ = a_entero<ZZ>(cad);
    }
    
    //cout << semS << endl;
    //cout << cad << endl;
    //cout << cad.size() << endl;
    //cout << "holi boli: " << tempZZ << endl;
}


string LFSR::genSemilla(unsigned int b)
{
    string semTmp;
    tmp     = getSemilla();
    semTmp  = a_binario(tmp);
    if (b < 64) return corregirCadBits(b, semTmp);
    else        return semTmp;
}

string LFSR::genCadenaBit(unsigned int b,string sem)
{
    bool x,y;
    string tmp,cad;
    unsigned long tam = sem.size();
    //Usamos s_i+3 = s_i+1 + s_i
    for (unsigned long i = sem.size(); i < b; i++) {
        x = sem[tam]-'0'; y = sem[tam-1]-'0';
        tmp = (x^y)+'0';
        sem.insert(0, tmp);
        //cout << "n. cad: " << sem << endl;
        tam--;
    }
    //calculamos un tap aleatorio
    unsigned int tap = getRandMod(b);
    //Left Shift hasta que tengamos el tamano de bits
    while (sem[0]!='1') {
        tap = getRandMod(b);
        x = sem[0]-'0';
        for (unsigned int i=0; i < b-1; i++) {
            sem[i] = sem[i+1];
        }
        y = sem[tap]-'0';
        sem[b-1] = (x^y)+'0';
    }
    //nos aseguramos que sea impar
    sem[b-1] = '1';
    return sem;
}

void LFSR::nuevoNum(unsigned int t)
{
    semS    = genSemilla(t);
    cad     = genCadenaBit(t,semS);
    tempZZ  = a_entero<ZZ>(cad);
}

ZZ LFSR::getNum()
{
    return tempZZ;
}

uint64_t getSemilla()
{
    FILE *fp = fopen("/dev/random", "r");
    if (!fp) {
        perror("randgetter");
        exit(-1);
    }
    uint64_t value = 0;
    //cout << "tam. val.: " << sizeof(value) << endl;
    int i;
    for (i=0; i < sizeof(value) ; i++) {
        value <<= 8;
        //cout << "val. shift: " << value << endl;
        value |= fgetc(fp);
        //cout << "val.: " << value << endl;
    }
    fclose(fp);
    return value;
}

unsigned int getRandMod(unsigned int m)
{
    uint64_t ranTmp = getSemilla();
    return mod_mult<uint64_t, unsigned long,unsigned int>(ranTmp, m);
}