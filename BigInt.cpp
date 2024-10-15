#include "BigInt.h"

BigInt ConstructBigInt() {
    BigInt B;
    B.Dight = ConstructVector<uint8_t>(16);
    B.Use = 0;
    return B;
}

BigInt ConstructBigInt(char* Number, size_t L) {
    BigInt B;
    From(B, Number, L);
    return B;
}

bool Free(BigInt& In) {
    Free(In.Dight);
    In.Use = 0;

    return true;
}



size_t BitCount(BigInt& In) {
    return In.Use;
}

int BitIndex(BigInt& In, size_t N) {

    if (N > BitCount(In)) { return -1; }

    size_t X = N / 8;
    size_t Y = N % 8;
    if (Index(In, X + 1) == NULL) { return -1; }
    uint8_t Z = *Index(In.Dight, X + 1);

    return (Z & (1 << Y)) > 0 ? 1 : 0;
}
bool SetBit(BigInt& In, size_t Idx, bool B) {
    if (Idx > BitCount(In)) { return -1; }

    size_t X = Idx / 8;
    size_t Y = Idx % 8;
    if (Index(In, X + 1) == NULL) { return false; }
    uint8_t Z = *Index(In.Dight, X + 1);

    uint8_t A = 0 ^ 0;
    uint8_t B = (1 << Y) ^ 0;
    uint8_t C = (Z & B) & (B << Y);

    Back(In.Dight) = C;

    return true;
}

bool PushBit(BigInt& In, bool B) {
    if (SetBit(In, BitCount(In) + 1, B) == false) { return true; }
    In.Use++;
    if ((In.Use / 8 + 1) >= Size(In.Dight)) { Push(In.Dight, 0); }

    return true;
}

BigInt Duplicate(BigInt& In) {
    BigInt A;
    A.Dight = Duplicate<uint8_t>(In.Dight);
    A.Use = In.Use;
    return A;
}


bool BitPush(BigInt& In, bool B) {
    size_t N = BitCount(In) + 1;

    if (SetBit(In, N++, B) == false) { return false; };
    In.Use++;

    return true;
}
bool And(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) & BitIndex(X, N);
    Free(X);
    return Y;
}
bool Or(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) | BitIndex(X, N);
    Free(X);
    return Y;
}

bool Not(BigInt& In, size_t N) {
    bool Y = BitIndex(In, N);
    return !Y;
}
bool Xor(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) ^ BitIndex(X, N);
    Free(X);
    return Y;
}
bool Nand(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) & BitIndex(X, N);
    Free(X);
    return !Y;
}
bool Nor(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) | BitIndex(X, N);
    Free(X);
    return !Y;
}
bool Equal(BigInt& In, bool B, size_t N) {
    BigInt X = ConstructBigInt();
    SetBit(X, N, B);
    bool Y = BitIndex(In, N) ^ BitIndex(X, N);
    Free(X);
    return !Y;
}/**/
bool And(const bool& A, const bool& B) {
    return A & B;
}

bool OR(const bool& A, const bool& B) {
    return A | B;
}
bool Not(const bool& A) {
    return !A;
    //  return ~A;//why not work this line...
}

bool Xor(const bool& A, const bool& B) {
    return A ^ B;
}
bool Nand(const bool& A, const bool& B) {
    return !(A & B);
}

bool Nor(const bool& A, const bool& B) {
    return !(A | B);
}
bool Equal(const bool& A, const bool& B) {
    return !(A ^ B);
}
bool AndEQ(BigInt& In, BigInt& B) {
    BigInt C = And(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt And(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = And(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
bool OrEQ(BigInt& In, BigInt& B) {
    BigInt C = Or(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Or(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Or(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
bool NotEQ(BigInt& In, BigInt& B) {
    BigInt C = Not(In);
    Free(In);
    In = C;
    return true;
}
BigInt Not(BigInt& In) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Not(In, i);
        BitPush(C, X);
    }
    return C;
}
bool XorEQ(BigInt& In, BigInt& B) {
    BigInt C = Or(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Xor(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Xor(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
bool NandEQ(BigInt& In, BigInt& B) {
    BigInt C = Or(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Nand(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Nand(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
bool NorEQ(BigInt& In, BigInt& B) {
    BigInt C = Or(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Nor(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Nor(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
bool EqualEQ(BigInt& In, BigInt& B) {
    BigInt C = Or(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Equal(BigInt& In, BigInt& B) {

    BigInt C = ConstructBigInt();

    for (size_t i = 0; i < BitCount(B); i++) {
        bool X = Equal(In, BitIndex(B, i), i);
        BitPush(C, X);
    }
    return C;
}
/**/
template<class T>
struct Pair {
    T A = 0;
    T B = 0;
};

Pair<bool> HarfAdder(const bool& A, const bool& B) {//std::get<0>() => S. std::get<1>() => C.
    bool S = Xor(A, B);
    bool C = And(A, B);

    return { S,C };
}


Pair<bool> FullAdder(const bool& A, const bool& B, const bool& X) {//std::get<0>() => S. std::get<1>() => C.
    auto AA = HarfAdder(A, B);
    auto BB = HarfAdder(AA.A, X);

    bool S = BB.A;
    bool C = OR(AA.B, BB.B);

    return { S,C };
}
/** /
template<class T>
T Max(T A, T B) {
    return A > B ? A : B;
}
template<class T>
T Min(T A,T B) {
    return A < B ? A : B;
}
/**/
/**/
template<class T>
const T& Max(const T& A, const T& B) {
    return A > B ? A : B;
}
template<class T>
const T& Min(const T& A, const T& B) {
    return A < B ? A : B;
}
/**/
/** /
BigInt OrEQ(BigInt& In, BigInt& B) {
    BigInt C = ConstructBigInt();
    size_t M = Max(BitCount(In), BitCount(B));
    for (size_t i = 0; i < M; i++) {
        int A = BitIndex(In, i);
        int B = BitIndex(In, i);
        if (Push(C, (A > 0 ? A : 0) | (B > 0 ? B : 0)) == false) { break; };
    }
    Free(In);
    In = C;

    return In;
}
/**/
template<class T>
BigInt MakeBasic(const T& X){
    BigInt A = ConstructBigInt();
    for(size_t i=0;i<sizeof(T)*8;i++){
        BitPush(A, X&(1 << i));
    }

    return A;
}

bool From(BigInt& In, char* S, size_t L) {
    Free(In);
    In = ConstructBigInt();

    BigInt A = MakeBasic(1);
    BigInt B = MakeBasic(10);
    for (intmax_t i = L - 1; i >= 0; i--) {
        char X[2] = { S[i],'\0' }
        AddEQ(In, Mul(A,atoi(X));
        
        MulEQ(A, B);
    }

    Free(In);
    In = A;
    Free(B);

    return true;
}

BigInt Add(BigInt& In, BigInt B) {

    size_t L = Max(Size(In.Dight), Size(B.Dight));
    Pair<bool> X{ false,false };
    BigInt V = ConstructBigInt();

    L += L % 2;

    for (std::size_t i = 0; i < L; i++) {
        X = FullAdder((BitIndex(In, i) ? true : false), (BitIndex(B, i) ? true : false), X.B);
        //V |= (X.A ? 1 : 0) << i;
        BitPush(V, X.A);
    }

    return V;
}
bool AddEQ(BigInt& In, BigInt& B) {
    BigInt C = Add(In, B);

    Free(In);
    In = C;
    return true;
}
BigInt Sub(BigInt& In, BigInt B) {

    size_t L = Max(Size(In.Dight), Size(B.Dight));
    Pair<bool> X{ false,true };
    BigInt V = ConstructBigInt();

    L += L % 2;

    for (std::size_t i = 0; i < L; i++) {
        X = FullAdder((BitIndex(In, i) ? true : false), (BitIndex(B, i) ? true : false), X.B);
        //V |= (X.A ? 1 : 0) << i;
        BitPush(V, X.A);
    }

    return V;
}
bool SubEQ(BigInt& In, BigInt& B) {
    BigInt C = Sub(In, B);

    Free(In);
    In = C;
    return true;
}
BigInt LeftShift(BigInt& In, size_t X) {
    BigInt B = ConstructBigInt();
    for (size_t i = 0; i < X; i++) {
        PushBit(B, false);
    }
    for (size_t i = 0; i < BitCount(In); i++) {
        PushBit(B, BitIndex(In, i));
    }
    return B;
}
BigInt RightShift(BigInt& In, size_t X) {
    BigInt B = ConstructBigInt();
    for (size_t i = X; i < BitCount(In); i++) {
        PushBit(B, BitIndex(In, i));
    }
    return B;
}
bool MulEQ(BigInt& In, BigInt B) {
    BigInt C = Mul(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt  Mul(BigInt& In, BigInt& B) {
    BigInt C = ConstructBigInt();
    size_t L = BitCount(B);
    for (size_t i = 0; i < L; i++) {
        if (And(B, true, i) == true) {
            AddEQ(C, LeftShift(In, i));
        }

    }
    /** /
    for (std::size_t X = 0; X < std::numeric_limits<T>::digits; X++) {
        if (B & (1 << X)) {
            C += (A << X);
        }
    }
    /**/
    return C;
}
bool DivEQ(BigInt& In, BigInt B) {
    BigInt C = Div(In, B);
    Free(In);
    In = C;
    return true;
}
BigInt Div(BigInt& In, BigInt& B) {
    BigInt C = ConstructBigInt();
    size_t L = BitCount(B);
    for (intmax_t i = L; i >= 0; i--) {
        if (And(B, true, i) == true) {
            SubEQ(C, LeftShift(In, i));
        }

    }
    return C;
}

BigInt Mod(BigInt& In, BigInt B) {
    BigInt C = Div(In, B);
    BigInt D = Mul(C, B);
    BigInt E = Sub(In, D);

    Free(C);
    Free(D);

    return E;
}

bool Inclimental(BigInt& In) {
    BigInt B = MakeBasic(1);
    bool X=AddEQ(In, B);
    Free(B);
    return X;
}
bool Declimental(BigInt& In) {
    BigInt B = MakeBasic(1);
    bool X=SubEQ(In, B);
    Free(B);
    return X;
}

template<class T>
BigInt Add(BigInt& In,T Number){
    BigInt B = MakeBasic<T>(Number);
    BigInt C = Add(In, B);
    Free(B);

    return C;
}
template<class T>
BigInt Sub(BigInt& In,T Number){
    BigInt B = MakeBasic<T>(Number);
    BigInt C = Sub(In, B);
    Free(B);

    return C;
}
template<class T>
BigInt Mul(BigInt& In,T Number){
    BigInt B = MakeBasic<T>(Number);
    BigInt C = Mul(In, B);
    Free(B);

    return C;
}
template<class T>
BigInt Div(BigInt& In,T Number){
    BigInt B = MakeBasic<T>(Number);
    BigInt C = Div(In, B);
    Free(B);

    return C;
}
template<class T>
BigInt Mod(BigInt& In,T Number){
    BigInt B = MakeBasic<T>(Number);
    BigInt C = Mod(In, B);
    Free(B);

    return C;
}