#include "DevCommands.h"
#include "utilities.h"

namespace DevCom
{

	int SendCommand(std::string c)
	{
		std::vector<std::string> spl = StrSplit(c, ' ');
		std::string com;

		if(spl.size() == 0)
			com = c;
		else
			com = spl[0];

		for(unsigned int i = 0; i < com.size(); i++)
		{
			com.at(i) = toupper(com.at(i));
		}

		short size = spl.size() - 1;
		std::string* p = new std::string[size];

		for(unsigned short g = 1; g < spl.size(); g++)
		{
			p[g - 1] = spl[g];
		}

		if(com == "SPAWN") { Spawn(p, size); }
		else if(com == "SETROOM") { SetRoom(p, size); }
		else if(com == "TRIGGER") { Trigger(p, size); }
		else if(com == "ITEM") { Item(p, size); }
		else if(com == "SETHEALTH") { SetHealth(p, size); }
		else if(com == "KILL") { Kill(p, size); }
		else if(com == "GODMODE") { GodMode(); }
		else if(com == "QUEST") { Quest(p, size); }
		else if(com == "DEBUG") { Debug(); }
		else { delete[] p; return 0; }

		delete[] p;
		return 1;
	}

	void Spawn(std::string* p, short pAm)
	{

	}

	void SetRoom(std::string* p, short pAm)
	{

	}

	void Trigger(std::string* p, short pAm)
	{

	}

	void Item(std::string* p, short pAm)
	{

	}

	void SetHealth(std::string* p, short pAm)
	{

	}

	void Kill(std::string* p, short pAm)
	{

	}

	void Quest(std::string* p, short pAm)
	{

	}

	void GodMode()
	{

	}

	void Debug()
	{

	}
}