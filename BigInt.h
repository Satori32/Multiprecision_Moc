#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "Vector.h"

struct BigInt
{
    Vector<uint8_t> Dight;
    size_t Use = 0;
};
template<class T>
struct Pair {
    T A = 0;
    T B = 0;
};

BigInt ConstructBigInt();
BigInt ConstructBigInt(char* Number, size_t L);
bool Free(BigInt& In);
int BitIndex(BigInt& In, size_t N);
bool SetBit(BigInt& In, size_t Idx, bool B);
bool PushBit(BigInt& In, bool B);
BigInt Duplicate(BigInt& In);
bool BitPush(BigInt& In, bool B);
bool And(BigInt& In, bool B, size_t N);
bool Or(BigInt& In, bool B, size_t N);
bool Not(BigInt& In, size_t N);
bool Nand(BigInt& In, bool B, size_t N);
bool Equal(BigInt& In, bool B, size_t N);
bool And(const bool& A, const bool& B);
bool OR(const bool& A, const bool& B);
bool Not(const bool& A);
bool Nand(const bool& A, const bool& B);
bool Nor(const bool& A, const bool& B);
bool Equal(const bool& A, const bool& B);
bool AndEQ(BigInt& In, BigInt& B);
BigInt And(BigInt& In, BigInt& B);
bool OrEQ(BigInt& In, BigInt& B);
BigInt Or(BigInt& In, BigInt& B);
bool NotEQ(BigInt& In, BigInt& B);
BigInt Not(BigInt& In);
bool XorEQ(BigInt& In, BigInt& B);
BigInt Xor(BigInt& In, BigInt& B);
bool NandEQ(BigInt& In, BigInt& B);
BigInt Nand(BigInt& In, BigInt& B);
bool NorEQ(BigInt& In, BigInt& B);
BigInt Nor(BigInt& In, BigInt& B);
bool EqualEQ(BigInt& In, BigInt& B);
BigInt Equal(BigInt& In, BigInt& B);
Pair<bool> HarfAdder(const bool& A, const bool& B);
Pair<bool> FullAdder(const bool& A, const bool& B, const bool& X);
template<class T> BigInt MakeBasic(const T& X);
bool From(BigInt& In, char* S, size_t L);
BigInt Add(BigInt& In, BigInt B);
bool AddEQ(BigInt& In, BigInt& B);
BigInt Sub(BigInt& In, BigInt B);
bool SubEQ(BigInt& In, BigInt& B);
BigInt LeftShift(BigInt& In, size_t X);
BigInt RightShift(BigInt& In, size_t X);
bool MulEQ(BigInt& In, BigInt B);
BigInt Mul(BigInt& In, BigInt& B)
bool DivEQ(BigInt& In, BigInt B);
BigInt Div(BigInt& In, BigInt& B);
BigInt Mod(BigInt& In, BigInt B);
bool Inclimental(BigInt& In);
bool Declimental(BigInt& In);
template<class T> BigInt Add(BigInt& In, T Number);
template<class T> BigInt Sub(BigInt& In, T Number);
template<class T> BigInt Mul(BigInt& In, T Number);
template<class T> BigInt Div(BigInt& In, T Number);
template<class T> BigInt Mod(BigInt& In, T Number);