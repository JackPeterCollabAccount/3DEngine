// liblitexml.
#pragma once

#include <string>

namespace LiteXML
{
	class liblitexml {
	public:
		double worked;
		__declspec(dllexport) liblitexml(std::string f);
		__declspec(dllexport) ~liblitexml();

		// Returns a + b
        static double __declspec(dllexport) Add(double a, double b);

	private:
		char * memblock;
	};
}