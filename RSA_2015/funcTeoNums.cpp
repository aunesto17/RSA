//
//  funcTeoNums.cpp
//  LFSR_2015
//
//  Created by Alexander Arturo Baylon Ibanez on 5/28/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "funcTeoNums.h"


string corregirCadBits(unsigned int b,string c)
{
    for (unsigned long i=c.size();i > b ; i--) {
        c.erase(c.begin());
    }
    c[c.size()-1] = '1';
    return c;
}

ZZ expo_rap(ZZ a, ZZ b,ZZ m) {
    ZZ exp(1);
    ZZ x = mod_n(a, m);
    while(b>0) {
        if((b&1)==1) exp = mod_n(exp*x,m);
        x = mod_n(x*x,m);
        b = b>>1;
    }
    return exp;
}


vector<int> cribaEratostenes(int numLimite)
{
    int bound = (int) floor(sqrt(numLimite));
    vector<bool> primos(numLimite, true);
    vector<int> criba;
    primos[0] = false;
    primos[1] = false;
    //Since 2 is a special case if we do it separately we can optimize the rest since
    //they will all be odd
    for(int i = 4; i < numLimite; i += 2)
    {
        primos[i] = false;
    }
    criba.push_back(2);
    //Since the only ones we need to look at are odd we can step by 2
    for (int i = 3; i  <= bound; i += 2)
    {
        if (primos[i])
        {
            //Since we are looping already we might as well start filling the
            //criba vector
            criba.push_back(i);
            //Since all the even multiples are already accounted for we start
            //at the square of the number
            //and since it is odd skip to every other multiple
            for (int j = i*i; j < numLimite; j += i * 2)
            {
                primos[j] = false;
            }
        }
    }
    //Fill the rest of the vector starting one past the square root of the numLimite
    for(int i = bound+1;i < numLimite; i++)
    {
        if(primos[i])
            criba.push_back(i);
    }
    return criba;
}

ZZ euclides_ext(ZZ a,ZZ b)
{
    ZZ r,s,t,q,r1,r2,s1,s2,t1,t2;
    r1 = a; r2 = b;
    s1 = t2 = 1;
    t1 = s2 = 0;
    while (r2 > 0) {
        q = r1/r2;
        //actualizando r's
        r  = r1 - (q*r2);
        r1 = r2; r2 = r;
        //actualizando s's
        s  = s1 - (q*s2);
        s1 = s2; s2 = s;
        //actualizando t's
        t  = t1 - (q*t2);
        t1 = t2; t2 = t;
    }
    //cout << s1 << endl;
    if(s1>0)
        return s1;
    else
        return s1 + b;
}

int numDigitos(ZZ num)
{
    int digitos = 0;
    while (num>0) {
        num /= 10;
        digitos++;
    }
    return digitos;
}

int numDigitos_int(int num)
{
    int digitos = 0;
    while (num>0) {
        num /= 10;
        digitos++;
    }
    return digitos;
}

string noCero(string cad)
{
    while (cad[0]=='0') {
        cad.erase(cad.begin());
    }
    return cad;
}

string compCeros(string cad,unsigned int tam)
{
    ZZ temp;
    temp = tam - cad.size();
    for (int i=0; i<temp; i++) {
        cad.insert(cad.begin(),'0');
    }
    return cad;
}

string aString(ZZ num)
{
    stringstream buffer;
    buffer << num;
    return buffer.str();
}

/*
ZZ aEntero(string cad)
{
    istringstream str(cad);
    ZZ temp;
    str >> temp;
    return temp;
}
*/
ZZ aEntero(string cad)
{
    stringstream convert(cad);
    ZZ temp;
    if ( !(convert>>temp) )
        return  to_ZZ(-1);
    return temp;
}

ZZ exp_modular_bit(ZZ base,ZZ exp,ZZ modulo){
    ZZ b(1);
    if (exp==0) return b;
    ZZ A; A=base;
    
    if(bit(exp,0)==1)
        b=base;
    
    int tamano = int(NumBits(exp));
    
    for (int i=1;i<tamano;i++){
        A = mod_n(A*A,modulo);
        if(bit(exp,i)==1){
            b=mod_n(A*b, modulo);
        }
    }
    return b;
}

string ingreFirma()
{
    string tmp;
    cout << "Ingrese el valor de la Firma Digital: ";
    cin >> tmp;
    return tmp;
}

string borrarEnd(string cad,unsigned tamN)
{
    for (int i=0; i<tamN; i++) {
        cad.erase(cad.size()-1);
    }
    return cad;
}

ZZ restoChino(ZZ num,ZZ p,ZZ q,ZZ d)
{
    //cout << "Num: " << num << endl;
    //Descomponemos en funcion de p y q
    //cout << "p: " << p << " q: " << q << endl;
    //cout << "d : " << d << endl;
    ZZ Dp = mod_n(d, p-1);
    ZZ Dq = mod_n(d, q-1);
    //cout << "Dp: " << Dp << " Dq: " << Dq << endl;
    //Calculamos P
    ZZ P(p*q);
    //cout << "P: " << P << endl;
    //Hallamos las inversas de q y p con mod p y q
    ZZ q1 = euclides_ext(q, p);
    ZZ q2 = euclides_ext(p, q);
    //cout << "q1: " << q1 << " q2: " << q2 << endl;
    //Multiplicamos todos los resultados
    //ZZ D =  (expZZ(num, Dp) * q * q1)+
    //      (expZZ(num, Dq) * p * q2);
    ZZ D =  mod_n((exp_modular_bit(num, Dp,P) * q * q1),P)+
    mod_n((exp_modular_bit(num, Dq,P) * p * q2),P);
    //cout << "D1: " << D << endl;
    //Sacamos su modulo P
    D = mod_n(D, P);
    //cout << "D2: " << D << endl;
    //como k=0 retornamos D
    return D;
}

void pausa()
{
    cout << "Presione una tecla para continuar.... ";
    cin.ignore().get();
}

void menuPrincipal()
{
    cout << "##### ESTRUCTURAS DISCRETAS 3: CIFRADO RSA #####" << endl;
    

}


void clear_screen()
{
    system("cls");
}

unsigned int ingresar(string a)
{
    unsigned int num;
    cout << "Ingrese el numero de " << a <<  ": ";
    cin >> num;
    return num;
}

ZZ exp_modular(ZZ base,ZZ exp,ZZ modulo){
    ZZ res(1);
    // Mientras que el exponente no sea 0
    while(exp > 0){
        //Si el exponente es impar se actualiza el resultado.
        if (exp % 2 == 1)
            res = (res*base) % modulo;
        // exp = exp/2;
        exp >>= 1;
        // base = base ^ 2 % mod
        base    = (base*base)%modulo;
    }
    return res;
};
