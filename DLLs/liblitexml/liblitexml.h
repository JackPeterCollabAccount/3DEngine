#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

namespace LiteXML
{
	//Main class - important stuff is here
	class LibLiteXML
	{
	public:
		__declspec(dllexport) LibLiteXML();
		__declspec(dllexport) int Open(std::string f);
		__declspec(dllexport) std::string ReadValue(std::string p);
		__declspec(dllexport) void WriteValue(std::string i, std::string v);
		__declspec(dllexport) int DeleteValue(std::string i);
		__declspec(dllexport) int SaveFile(std::string f);
		__declspec(dllexport) int Process() {return 0;}
		__declspec(dllexport) ~LibLiteXML();

		std::string data;

		private:

	};

	//:O something went wrong handler
	class LiteXMLException
	{
		public:
			__declspec(dllexport) LiteXMLException(std::string why) : why(why) {}
			std::string __declspec(dllexport) virtual What();

		private:
			std::string why;
	};

	//And a final bit to sum up the fact it fucked up
	class IOException : public LiteXMLException
	{
		public:
			__declspec(dllexport) IOException(std::string why) : LiteXMLException(why) {}
			__declspec(dllexport) std::string virtual What();
	};

}