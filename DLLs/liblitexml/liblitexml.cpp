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
				}
		}
		catch(IOException e)
		{
			//close the file - error
			throw e;
		}
		catch(...)
		{
			//close the file - error
			file.close();
			throw IOException("Error opening file: "+f);
		}
	}

	//Way of getting an XML value :D
	std::string LibLiteXML::ReadValue(std::string p)
	{
		//Default return value
		std::string returnV = "0";

		//Strings after split
		std::vector<std::string> spl = split(data, ';');
		std::vector<std::string>::iterator start, end, it;

		start = spl.begin();
		end = spl.end();

		unsigned int f = 0;

		//For each string after the split see if they match the value wanted
		for(it = start; it < end; it++)
		{
			//If they do then great!
			if(*it == p)
			{
				break;
			} else {
				f++;
			}
		}

		//If we've gone through all values of f we haven't found it
		if(f+1 > spl.size())
		{
			throw IOException("Could not find paramater '"+p+"' within file!");
		}

		f++;

		//Use f to find the appropriate string again
		returnV = spl[f];

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