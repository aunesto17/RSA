//
//  rsa.h
//  RSA_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 5/28/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#ifndef __RSA_2015__rsa__
#define __RSA_2015__rsa__

#include "lfsr.h"

class rsa
{
private:
    int varDic;
    const int tamAlfa = 76;
    ZZ p,q,d,phiN;
    void generarClaves(unsigned int);
    //string cifradoBloques(string);
    string valFirma,decif;
    ZZ getPrimo(unsigned int);
    ZZ genE(ZZ);
    ZZ genD(ZZ,ZZ);
    void mostrarClaves();
public:
    rsa(){};
    rsa(unsigned int,unsigned int);
    string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890,;:-_<>@*+().";
    string firma;
    ZZ N,e;
    ZZ Npu,Epu;
    ZZ millerIter;
    string cifrado(string);
    string decifrado(string);
    string msj_aDigitos(string);
    string subFirma(string,unsigned int);
    string completarBloques(string,unsigned int);
    string cifrarBloques(string,unsigned int);
    string firmaDigital(string);
    string decifrarBloques(string,unsigned int);
    string decifrarFirma(string);
    string traducirCad(string);
    string nuevoMensaje(string,string,string);
    string recibirMensaje(string,string,string);
    char aLetra(ZZ);
};

bool Miller(ZZ,ZZ);


#endif /* defined(__RSA_2015__rsa__) */
