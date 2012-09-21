#include "libenc.h"
#include <Windows.h>

namespace LibEnc
{
	int __declspec(dllexport) EncSingle(int i, int amount, int length, int prev)
	{
		int temp = i;
		temp += (length+prev) * amount;
		RotateLeft(&temp, amount);
		return temp;
	}

	int __declspec(dllexport) DecSingle(int i, int amount, int length, int prev)
	{
		int temp = i;
		RotateRight(&temp, amount);
		temp -= (length+prev) * amount;
		return temp;
	}

	void __declspec(dllexport) EncString(std::string *str, int amount)
	{
		int prev = 0x43;
		int size = str->size();
		for(unsigned int c = 0; c < size; c++)
		{
			char ch = str->at(c);
			str->at(c) = EncSingle(ch, amount, size, prev);
			prev -= ch;
		}
	}

	void __declspec(dllexport) DecString(std::string *str, int amount)
	{
		int prev = 0x43;
		int size = str->size();
		for(unsigned int c = 0; c < size; c++)
		{
			char ch = str->at(c);
			str->at(c) = DecSingle(str->at(c), amount, size, prev);
			prev -= str->at(c);
		}
	}
}