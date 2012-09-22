#pragma once
#include "stdh.h"

namespace DevCom
{
	enum CommandList { SPAWN, SETROOM, TRIGGER, ITEM, SETHEALTH, KILL, GODMODE, DEBUG, QUEST };

	void Spawn(std::string* p, short pAm);
	void SetRoom(std::string* p, short pAm);
	void Trigger(std::string* p, short pAm);
	void Item(std::string* p, short pAm);
	void SetHealth(std::string* p, short pAm);
	void Kill(std::string* p, short pAm);
	void Quest(std::string* p, short pAm);
	void GodMode();
	void Debug();
	int SendCommand(std::string);
}