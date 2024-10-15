#include "Multiprecision .h"

Multiprecision ConstructMultipecision(double X) {
	Multiprecision M;
	M.Frac = MakeBasic(log10(X));
	M.Number = MakeBasic(log2(X * X));
	return M;
}
Multiprecision ConstructMultipecision(BigInt& F, BigInt& N) {
	Multiprecision M;
	M.Frac = Duplicate(F);
	M.Number = Duplicate(N);
	return M;
}
bool Free(Multiprecision& In) {
	Free(In.Frac);
	Free(In.Number);

	return true;
}
Multiprecision Add(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac = Add(In.Frac, B.Frac);
	C.Number = Add(In.Number, B.Number);

	return C;
}
Multiprecision Sub(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac = Sub(In.Frac, B.Frac);
	C.Number = Sub(In.Number, B.Number);

	return C;
}
Multiprecision Mul(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac = Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
Multiprecision Div(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac = Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
Multiprecision Mod(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac = Div(In.Frac, B.Number);
	C.Number = Div(In.Frac, B.Number);

	return C;
}
template<class T>
Multiprecision Add(Multiprecision& in, T N) {
	Multiprecision X = ConstructMultipecision(N);
	Multiprecision A = Add(In, X);
	Free(X);
	return A;
}
template<class T>
Multiprecision Sub(Multiprecision& in, T N) {
	Multiprecision X = ConstructMultipecision(N);
	Multiprecision A = Sub(In, X);
	Free(X);
	return A;
}
template<class T>
Multiprecision Mul(Multiprecision& in, T N) {
	Multiprecision X = ConstructMultipecision(N);
	Multiprecision A = Mul(In, X);
	Free(X);
	return A;
}
template<class T>
Multiprecision Div(Multiprecision& in, T N) {
	Multiprecision X = ConstructMultipecision(N);
	Multiprecision A = Div(In, X);
	Free(X);
	return A;
}

template<class T>
Multiprecision Mod(Multiprecision& in, T N) {
	Multiprecision X = ConstructMultipecision(N);
	Multiprecision A = Mod(In, X);
	Free(X);
	return A;
}
template<class T>
bool EQ(Multiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (NotEQ(C.Frac, In.Frac) == false) { return false; }
	if (NotEQ(C.Number, In.Number) == false) { return false; }
	Free(C);
	return true;
}
bool EQ(Multiprecision& In, Multiprecision& B) {
	if (NotEQ(B.Frac, In.Frac) == false) { return false; }
	if (NotEQ(B.Number, In.Number) == false) { return false; }

	return true;
}
template<class T>
bool NotEQ(Multiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (NotEQ(C.Frac, In.Frac) == false) { return false; }
	if (NotEQ(C.Number, In.Number) == false) { return false; }
	Free(C);
	return true;
}
bool NotEQ(Multiprecision& In, Multiprecision& B) {
	if (EQ(B.Frac, In.Frac) == false) { return false; }
	if (EQ(B.Number, In.Number) == false) { return false; }

	return true;
}
template<class T>
bool UpperLeft(Multiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (UpperLeft(C.Frac, In.Frac) == false) { return false; }
	Free(C);
	return true;
}
bool UpperLeft(Multiprecision& In, Multiprecision& B) {
	if (UpperLeft(B.Frac, In.Frac) <= 0) { return false; }

	return true;
}
template<class T>
bool UpperRight(Multiprecision& In, T& B) {
	Multiprecision C = ConstructMultipecision(B);
	if (UpperRight(C.Frac, In.Frac) == false) { return false; }
	Free(C);
	return true;
}
bool UpperRight(Multiprecision& In, Multiprecision& B) {
	if (UpperRight(B.Frac, In.Frac) >= 0) { return false; }

	return true;
}

template<class T>
Multiprecision Abs(Multiprecision& In) {
	Multiprecision M = Mul(In, -1);
	Multiprecision T = ConstructMultipecision(In.Frac, In.Number);

	int X = UpperRight(T, M);

	Multiprecision Y = X == 1 ? T : M;
	Multiprecision* P = X == 1 ? &M : &T;

	Free(*P);
	return Y;
}

template<class T, class U>
Multiprecision NewtonMethod(Multiprecision& X, T& (*Fun)(const U&), T(*FunDash)(const U&), std::size_t Lim) {
	Multiprecision XN = ConstructMultipecision(0);
	Multiprecision XT = ConstructMultipecision(1);
	size_t C = 0;
	Multiprecision A = ABS(XT);
	Multiprecision B = ConstructMultipecision(0);
	while (EQ(A, B) == true) {
		Multiprecision XX = Div(Fun(X), (FunDash(X));
		X = Sub(X, XX);
		Free(XX);
		Free(XT);
		XT = Sub(X, XN);
		Free(XN);
		XN = X;
		A = ABS(XT);
		if (C == Lim && Lim != 0) { break; }
		C++;
	}
	Free(XT);
	Free(XN);
	Free(B);
	return X;

}

template<class T>
bool Swap(T& A, T& B) {
	T X = A;
	A = B;
	B = X;

	return true;
}
template<class T, class U>
Multiprecision BisectionMethod(Multiprecision Low, Multiprecision High, T *Fun(const U&), std::size_t Lim = 50) {
	Low = ConstructMultipecision(Low.Frac, Low.Number);
	High = ConstructMultipecision(High.Frac, High.Number);

	if (UpperLeft(Low, High) == 1) Swap(Low, High);


	Multiprecision XN = ConstructMultipecision(0);
	Multiprecision P = Add(Low, High);
	Multiprecision X = Div(P, 2);
	Free(P);
	int SL = UpperLeft(Fun(Low), 0) ? 1 : -1;
	int SH = UpperLeft(Fun(High), 0) ? 1 : -1;

	std::size_t C = 0;
	free(X);
	P = Add(Low, High);
	X = Div(P, 2);
	Free(P);
	int SM = Fun(X) > 0 ? 1 : -1;
	if (SM == SL) {
		Free(Low);
		Low = ConstructMultipecision(X.Frac, X, Number);
	}
	else {
		Free(High);
		High = ConstructMultipecision(X.Frac, X, Number);;
	}
	C++;
	Multiprecision Z = Sub(X, XN);
	Multiprecision A = Abs(Z);
	while (UpperLeft(A, 0) == true) {
		if (C == Lim && Lim != 0) { break; }

		XN = X;
		P = Add(Low, High);
		X = Div(P, 2);
		Free(P);
		int SM = UpperLeft(Fun(X), 0) ? 1 : -1;
		if (SM == SL) {
			Free(Low);
			Low = X;
		}
		else {
			Free(High);
			High = X;
		}
		C++;
		Free(Z);
		Z = Sub(X, XN);
		Free(A);
		A = Abs(Z);

	}
	Free(Z);
	Z = Sub(X, XN);
	Free(A);
	A = Abs(Z);
	Free(Low) :
		Free(High);
	return X;
}

template<class T = double, class U>
Multiprecision NewtonBisectionMethod(Multiprecision& X, T* BMFun(const U&), T* NMFun(const U&), T* NMFD(const T&), std::size_t Lim = 50) {//maybe perfect answer.
	Multiprecision A = NewtonMethod<T>(X, NMFun, NMFunDash, Lim);
	Multiprecision B = BisectionMethod(L, H, BMFun, Lim);
	Free(A);
	return B:
}