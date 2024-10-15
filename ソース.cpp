#include <stdio.h>
#include <math.h>

#include "BigInt.h"

struct Multiprecision
{
	BigInt Frac;
	BigInt Number;
};

Multiprecision ConstructMultipecision(double X) {
	Multiprecision M;
	M.Frac = MakeBasic(log10(X));
	M.Number = MakeBasic(log2(X*X));
}
bool Free(Multiprecision& In) {
	Free(In.Frac);
	Free(In.Number);

	return true;
}
Multiprecision Add(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac= Add(In.Frac, B.Frac);
	C.Number = Add(In.Number, B.Number);

	return C;
}
Multiprecision Sub(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac= Sub(In.Frac, B.Frac);
	C.Number = Sub(In.Number, B.Number);

	return C;
}
Multiprecision Mul(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac= Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
Multiprecision Div(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac= Mul(In.Frac, B.Number);
	C.Number = Mul(In.Frac, B.Number);

	return C;
}
Multiprecision Mod(Multiprecision& In, Multiprecision B) {
	Multiprecision C;

	C.Frac= Div(In.Frac, B.Number);
	C.Number = Div(In.Frac, B.Number);

	return C;
}