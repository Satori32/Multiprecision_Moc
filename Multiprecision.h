#pragma once
#include <stdio.h>
#include <math.h>

#include "BigInt.h"

struct Multiprecision
{
	BigInt Frac;
	BigInt Number;
};


Multiprecision ConstructMultipecision(double X);
Multiprecision ConstructMultipecision(BigInt& F, BigInt& N);
bool Free(Multiprecision& In);
Multiprecision Add(Multiprecision& In, Multiprecision B);
Multiprecision Sub(Multiprecision& In, Multiprecision B);
Multiprecision Mul(Multiprecision& In, Multiprecision B);
Multiprecision Div(Multiprecision& In, Multiprecision B);
Multiprecision Mod(Multiprecision& In, Multiprecision B);
template<class T> Multiprecision Add(Multiprecision& in, T N);
template<class T> Multiprecision Sub(Multiprecision& in, T N);
template<class T> Multiprecision Mul(Multiprecision& in, T N);
template<class T> Multiprecision Div(Multiprecision& in, T N);
template<class T> Multiprecision Mod(Multiprecision& in, T N);
template<class T> bool EQ(Multiprecision& In, T& B);
bool EQ(Multiprecision& In, Multiprecision& B);
template<class T> bool NotEQ(Multiprecision& In, T& B);
bool NotEQ(Multiprecision& In, Multiprecision& B);
template<class T> bool UpperLeft(Multiprecision& In, T& B);
bool UpperLeft(Multiprecision& In, Multiprecision& B);
template<class T> bool UpperRight(Multiprecision& In, T& B);
bool UpperRight(Multiprecision& In, Multiprecision& B);
