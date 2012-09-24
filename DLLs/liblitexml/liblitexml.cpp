#include "liblitexml.h"
#include "libenc.h"

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
				LibEnc::DecString(&this->data, 2);
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
			if(f % 2 == 0) {
				if(*it == p)
				{
					break;
				}
			}

			f++;
		}

		//If we've gone through all values of f we haven't found it
		if(f+1 > spl.size())
		{
			//throw IOException("Could not find identifier '"+p+"' within file!");
			return returnV;
		}

		f++;

		//Use f to find the appropriate string again
		returnV = spl[f];

		return returnV;
	}

	//Simply append to our data
	void LibLiteXML::WriteValue(std::string i, std::string v)
	{
		if(this->ReadValue(i) != "0")
			this->DeleteValue(i);

		this->data += i+";"+v+";";
	}

	int LibLiteXML::DeleteValue(std::string i)
	{
		//Default return value
		int returnV = 0;

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
			if(f % 2 == 0) {
				if(*it == i)
				{
					break;
				}
			}

			f++;
		}

		//If we've gone through all values of f we haven't found it
		if(f+1 > spl.size())
		{
			//throw IOException("Could not find identifier '"+p+"' within file!");
			return returnV;
		}

		//Use f to find the appropriate string again

		this->data = "";

		unsigned int j = 0;
		std::vector<std::string>::iterator it2;

		for(it2 = start; it2 < end-1; it2++)
		{
			if(j != f && j != (f+1))
			{
				this->data += *it2 + ";";
			}
			j++;
		}

		return returnV = 1;
	}

	int LibLiteXML::SaveFile(std::string f)
	{
		//define file
		std::ofstream file (f);

		//try writing
		try
		{
			if(file.is_open())
			{
				LibEnc::EncString(&this->data, 2);
				char *fileData = (char*)this->data.c_str();
				file.write(fileData, this->data.size());
				file.close();
				LibEnc::DecString(&this->data, 2);

				return 1;
			}
			else
			{
				//close the file - error
				file.close();
				throw IOException("Error writing file: "+f);
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

		return 0;
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