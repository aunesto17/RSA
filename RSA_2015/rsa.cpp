//
//  rsa.cpp
//  RSA_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 5/28/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "rsa.h"

rsa::rsa(unsigned int tamBit,unsigned int dic)
{
    millerIter  = 20;
    generarClaves(tamBit/2);
    mostrarClaves();
    varDic      = dic;
    //pausa();
    //cout << "p: " << p << endl;
    //cout << "q: " << q << endl;
}


void rsa::generarClaves(unsigned int tamBit)
{
    p       = getPrimo(tamBit);
    q       = getPrimo(tamBit);
    N       = p * q;
    phiN    = (p-1)*(q-1);
    e       = genE(phiN);
    d       = euclides_ext(e, phiN);
    //Epu = e;
    //Npu = N;
}

ZZ rsa::getPrimo(unsigned int bits)
{
    LFSR gen(bits);
    ZZ temp;
    do {
        temp = gen.getNum();
        gen.nuevoNum(bits);
    } while (Miller(temp, millerIter)==false);
    return temp;
}

ZZ rsa::genE(ZZ pN)
{
    ZZ temp;
    LFSR gen(int(NumBits(pN)/2));
    do {
        temp = gen.getNum();
        gen.nuevoNum(int(NumBits(pN)/2));
    } while (mcd(temp, pN)!=1);
    return temp;
}

string rsa::cifrado(string msj)
{
    unsigned int tamBloq,tamN,tamMsj;
    string sec2digi;
    //tamBloq = numDigitos(Npu)-1;
    tamBloq = numDigitos(Npu)-1;
    cout << "1.tam bloq: " << tamBloq << endl;
    tamN    = tamBloq + 1;
    cout << "2.digitos N: " << tamN << endl;
    tamMsj  = int(msj.size());
    cout << "3.Tam Mensaje: " << tamMsj << endl;
    sec2digi= msj_aDigitos(msj);
    cout << "4.secuencia: " << sec2digi << endl;
    cout << tamBloq << endl;
    sec2digi= completarBloques(sec2digi, tamBloq);
    cout << "5.secuencia. compl: " << sec2digi << endl;
    sec2digi= cifrarBloques(sec2digi, tamBloq);
    cout << "6.msj. cifrado: " << sec2digi << endl;
    //valFirma = ingreFirma();
    valFirma = "B";
    firma = firmaDigital(valFirma);
    cout << "firm: " << firma << endl;
    firma = compCeros(firma, tamN);
    cout << "Firma.cifrado: " << firma.size() << endl;
    cout << "Epu: " << Epu << endl;
    cout << "Npu: " << Npu << endl;
    sec2digi += firma;
    return sec2digi;
}

string rsa::decifrado(string cif)
{
    string temp = cif;
    unsigned int tamBloq,tamN;
    tamBloq = numDigitos(N)-1;
    cout << "tambloq: " << tamBloq << endl;
    tamN    = tamBloq + 1;
    firma   = subFirma(cif, tamN);
    cout << "firma.raw: " << firma << endl;
    cout << "raw.tam: " << firma.size() << endl;
    temp    = borrarEnd(cif, tamN);
    cout << "firm: " << firma << endl;
    cout << "firmless: " << temp << endl;
    decif   = decifrarBloques(temp, tamN);
    cout << "antes.de.trad: " << decif << endl;
    decif   = traducirCad(decif);
    firma   = decifrarFirma(firma);
    decif += alfa[to_int(aEntero(firma))];
    cout << "Decifrado Final: " << decif << endl;
    return decif;
}


void rsa::mostrarClaves()
{
    cout << "##### CLAVES #####:" << endl;
    cout << "p: PRIVADO" << p << endl;
    cout << "q: PRIVADO" << q << endl;
    cout << "phiN: PRIVADO" << phiN << endl;
    cout << "d: PRIVADO " << d << endl;
    cout << "e: " << e << endl;
    cout << "N: " << N << endl;
}

string rsa::msj_aDigitos(string msj)
{
    unsigned int tamCifras = numDigitos_int(tamAlfa+varDic);
    string digitos,temp;
    //Iteramos cada elemento del mensaje.
    for (int i=0; i < msj.size(); i++) {
        //Comprobamos su posicion en el alfabeto
        temp = to_string(alfa.find(msj[i])+varDic);
        for (int j=int(temp.size()); j<tamCifras; j++) {
            temp.insert(0,to_string(0));
        }
        //Agregamos la posicion a la cadena
        digitos += temp;
    }
    return digitos;
}

string rsa::completarBloques(string dig,unsigned int tamB)
{
    //Hallamos el nuevo tamano de elementos del mensaje
    unsigned int tamDigitos = int(dig.size());;
    //Si el tamano de los bloques divide al numero
    //de elementos de la cadena entonces no completamos nada.
    if(mod_n(tamDigitos,tamB)==0) return dig;
    while (mod_n(tamDigitos,tamB)!=0) {
        //dig += to_string(49);
        dig += to_string(23+varDic);
        tamDigitos = int(dig.size());
    }
    return dig;
}

string rsa::cifrarBloques(string dig,unsigned int tamB)
{
    unsigned int tamDigitos;
    //Recalculamos el tamano de digitos de la cadena.
    tamDigitos = int(dig.size());
    //Variables temporales para un string y un numero.
    string sTemp,cifrado;
    ZZ nTemp(0);
    //Iteramos por cada bloque.
    for (int i=0; i<tamDigitos; i+=tamB) {
        //Guardamos solo un bloque a la vez.
        for (int j=i,k=0; k<tamB; j++,k++){
            sTemp += dig[j];
        }
        //Le quitamos los ceros que se anteponen.
        sTemp = noCero(sTemp);
        cout << "prob.1: " << sTemp << endl;
        //Lo ciframos con la clave publica y N.
        cout << "epu: " << Epu << endl;
        cout << "Epu: " << Npu << endl;
        //nTemp = expo_rap(aEntero(sTemp), Epu,Npu);
        nTemp = exp_modular(aEntero(sTemp), Epu,Npu);
        cout << "num.beta.: " << nTemp << endl;
        //nTemp = expo_rap(aEntero(sTemp), e,N);
        //Lo adicionamos a una nueva cadena, pero antes
        //lo completamos con 0s adelante si es necesario(tamN).
        cifrado += compCeros(aString(nTemp), tamB+1);
        //Reiniciamos la cadena temporal.
        sTemp = "";
    }
    return cifrado;
}

string rsa::firmaDigital(string f)
{
    ZZ val, rubrica,firma;
    val     = alfa.find(f);
    //rubrica = expo_rap(val, d, N);
    rubrica = restoChino(val, p, q, d);
    firma   = expo_rap(rubrica, Epu, Npu);
    return aString(firma);
}

string rsa::subFirma(string cif, unsigned int tamN)
{
    string temp;
    temp = cif.substr(cif.size()-tamN,tamN);
    temp = noCero(temp);
    return temp;
}

string rsa::decifrarBloques(string cif,unsigned int tamN)
{
    //Calculamos el tamano del mensaje cifrado.
    unsigned int tamCifrado = int(cif.size());
    //Variables temporales.
    string sTemp,decifrado;
    ZZ nTemp(0);
    //Tomamos bloques de tamano N.
    for (int i=0; i<tamCifrado; i+=tamN) {
        //Guardamos el bloque
        for (int j=i,k=0; k<tamN; j++,k++)
            sTemp += cif[j];
        //Le quitamos los ceros que se anteponen
        cout << "problema0: " << sTemp << endl;
        sTemp = noCero(sTemp);
        cout << "problema1: " << sTemp << endl;
        //Deciframos el mensaje con la clave privada y N.
        cout << "d: " << d << endl;
        nTemp = exp_modular(aEntero(sTemp), d,N);
        //nTemp = restoChino(aEntero(sTemp), p, q, d);
        sTemp = aString(nTemp);
        cout << "Num.alfa: " << sTemp << endl;
        //Completamos los ceros de acuerdo al tamBloq
        sTemp = compCeros(sTemp, tamN-1);
        //Lo adicionamos a una cadena
        decifrado += sTemp;
        //Reiniciamos el string temporal
        sTemp = "";
    }
    return decifrado;
}

string rsa::decifrarFirma(string f)
{
    ZZ val, rubrica,firma;
    //rubrica = expo_rap(aEntero(f), d, N);
    rubrica = restoChino(aEntero(f), p, q, d);
    //cout << "rubri: " << rubrica << endl;
    firma   = expo_rap(rubrica, Epu, Npu);
    //cout << "firma deci: " << firma << endl;
    return aString(firma);
}

string rsa::traducirCad(string des)
{
    unsigned int tamCifrado = int(des.size());
    unsigned int tamCifras = numDigitos_int(tamAlfa+varDic);
    //cout << "tamcifras: " << tamCifras << endl;
    //cout << "tamcifrado: " << tamCifrado << endl;
    //Recalculamos el tamano de la cadena
    //Inicializamos variables temporales.
    string sTemp,orig;
    ZZ nTemp(0);
    //Iteramos por toda la cadena.
    for (int i=0; i<tamCifrado; i+=tamCifras) {
        //Tomamos bloques del tamano de los digitos del alfabeto(tamCifras)
        for (int j=i,k=0; k<tamCifras; j++,k++) {
            sTemp += des[j];
        }
        //cout << "pos: " << sTemp << endl;
        nTemp = aEntero(sTemp);
        //Convertimos el numero a letra y lo adicionamos a la
        //cadena final decifrada
        orig.insert(orig.end(),1,aLetra(nTemp));
        //Reiniciamos el string temporal.
        sTemp = "";
    }
    return orig;
}

string rsa::nuevoMensaje(string Npublico, string Epublico, string mensaje_original)
{
    Npu = aEntero(Npublico);
    Epu = aEntero(Epublico);
    return cifrado(mensaje_original);
}

string rsa::recibirMensaje(string Npublico, string Epublico, string mensaje_cifrado)
{
    Npu = aEntero(Npublico);
    Epu = aEntero(Epublico);
    cout << "Epu: " << Epu << endl;
    cout << "Npu: " << Npu << endl;
    return decifrado(mensaje_cifrado);
}



bool Miller(ZZ n,ZZ iter)
{
    ZZ bol(1);
    LFSR ran(int(NumBits(n)/2));
    if (n ==2 || n==3) return true;
    if ( n<=1 || (n&1)==0 ) return false;
    // escribir n-1 como d*2^s factorizando las potencias de 2 de n-1
    long s(0);
    ZZ m(n-1);
    while ((m&1)==0) {
        s += 1;
        m = m>>1;
    }
    ZZ d = (n-1) / LeftShift(bol, s);
    ZZ a,x;
    for (int i=0; i<iter; i++) {
        a = ran.getNum();
        x = expo_rap(a, d, n);
        
        if (x==1 || x==n-1) continue;
        
        bol = 2;
        for (int r=1; r<=s-1; ++r) {
            x = expo_rap(x, bol, n);
            if (x==1) return false;
            if (x==n-1) goto LOOP;
        }
        return false;
    LOOP:
        ran.nuevoNum(int(NumBits(n)/2));
        continue;
    }

    return true;
}

char rsa::aLetra(ZZ num)
{
    int pos = conv<int>(num);
    //cout << "alfa.pos: " << pos << endl;
    return alfa[pos-varDic];
}



