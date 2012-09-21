#pragma once

#include <string>

namespace LibEnc
{

	void inline RotateLeft(int * i, int amount)
{
	_asm
	{
		mov ebx, i
		mov ecx, [amount]
		rol [ebx], cl
	}
}

	void inline RotateRight(int * i,int amount)
{
	_asm
	{
		mov ebx, i
		mov ecx, [amount]
		ror [ebx], cl
	}
}

	int __declspec(dllexport) EncSingle(int, int, int, int);

	int __declspec(dllexport) DecSingle(int, int, int, int);

	void __declspec(dllexport) EncString(std::string*, int);

	void __declspec(dllexport) DecString(std::string* str, int);

}