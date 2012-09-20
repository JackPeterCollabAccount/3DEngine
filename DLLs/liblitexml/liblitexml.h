#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>

namespace LiteXML
{
	class LibLiteXML
	{
		public:
			__declspec(dllexport) LibLiteXML();
			__declspec(dllexport) int Open(std::string f);
			__declspec(dllexport) ~LibLiteXML();

			std::string data;
			private:
  
	};

	class LiteXMLException
	{
		public:
			__declspec(dllexport) LiteXMLException(std::string why) : why(why) {}
			std::string __declspec(dllexport) virtual What();

		private:
			std::string why;
	};

	class IOException : public LiteXMLException
	{
		public:
			__declspec(dllexport) IOException(std::string why) : LiteXMLException(why) {}
		std::string __declspec(dllexport) virtual What();
	};

}