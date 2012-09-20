#pragma once

#include "liblitexml.h"

//Start of the dll
namespace LiteXML
{
	//Start of important stuff
	#pragma region

	//Utils... just making sure they get loaded right.
	std::vector<std::string> split(const std::string& strValue, char separator)
	{
		std::vector<std::string> vecstrResult;
		int startpos=0;
		int endpos=0;

		endpos = strValue.find_first_of(separator, startpos);
		while (endpos != -1)
		{       
			vecstrResult.push_back(strValue.substr(startpos, endpos-startpos));
			startpos = endpos+1;
			endpos = strValue.find_first_of(separator, startpos);
			if(endpos==-1)
			{
				vecstrResult.push_back(strValue.substr(startpos));
			}
		}
		
		return vecstrResult;
	}

	//Constructor - generic doodad
	LibLiteXML::LibLiteXML() 
	{ }

	//Important part, opening file into string data - returns 1 if win 0 if fail
	int LibLiteXML::Open(std::string f)
	{
		//define file
		std::fstream file;

		//try opening
		try
		{
			file.open(f, std::ios::in | std::ios::binary);

			if(file.is_open())
			{
				//setup our string builder
				std::string temp;
				std::stringstream builder;

				while(file.good())
				{
					//make our string
					std::getline(file, temp);
					builder << temp;
				}

				//set it into data
				this->data = builder.str();
				return 1;
			}
			else
			{
				//close the file - error
				file.close();
				throw IOException("Error reading file: "+f);
				return 0;
				}
		}
		catch(IOException e)
		{
			//close the file - error
			throw e;
			return 0;
		}
		catch(...)
		{
			//close the file - error
			file.close();
			throw IOException("Error opening file: "+f);
			return 0;
		}
	}

	//Way of getting an XML value :D
	std::string LibLiteXML::ReadValue(std::string p)
	{
		std::string returnV = NULL;

		std::vector<std::string> spl = LibLiteXML::split(data, ';');

		int f = 0;
		
		for_each(spl.begin(), spl.end())
		{

			f++;
		}

		return returnV;
	}

	//Destructor!
	LibLiteXML::~LibLiteXML()
	{ }

	#pragma endregion LibLiteXML Implementation
	
	//Exception area
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