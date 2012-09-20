#pragma once

#include "liblitexml.h"

namespace LiteXML {

#pragma region

 LibLiteXML::LibLiteXML() 
 {
 }

 int LibLiteXML::Open(std::string f)
 {
	std::fstream file;
	
	try
	{
		file.open(f, std::ios::in | std::ios::binary);

		if(file.is_open())
		{
			std::string temp;
			std::stringstream builder;

			while(file.good())
			{
				std::getline(file, temp);
				builder << temp;
			}

			this->data = builder.str();
		}
		else
		{
			file.close();
			throw IOException("Error reading file: "+f);
		}
	}
	catch(IOException e)
	{
		throw e;
	}
	catch(...)
	{
		file.close();
		throw IOException("Error opening file: "+f);
	}
	return 0;
 }

 LibLiteXML::~LibLiteXML()
 {
 }

#pragma endregion LibLiteXML Implementation

#pragma region

 std::string LiteXMLException::What()
 {
	return this->why;
 }

 std::string IOException::What()
 {
	return LiteXMLException::What();
 }

#pragma endregion LiteXMLException Implementation

}