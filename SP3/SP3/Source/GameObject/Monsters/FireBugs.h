#ifndef MONSTER_FIRE_BUGS_H
#define MONSTER_FIRE_BUGS_H

#include "../Monster.h"
#include "../AI_Strategy.h"

class Monster_FireBugs : public Monster
{
public:
	Monster_FireBugs()
	{
		Strategy = NULL;
	}
	virtual ~Monster_FireBugs()
	{
		if (Strategy != NULL)
		{
			delete Strategy;
			Strategy = NULL;
		}
	}

	void ChangeStrategy(AI_Strategy* newAI, bool bDelete)
	{
		if (bDelete == true)
		{
			if (Strategy != NULL)
			{
				delete Strategy;
				Strategy = NULL;
			}
		}
		Strategy = newAI;
	}

	//Monster Movement update
	virtual void Update(double dt)
	{

	}
private:
	AI_Strategy* Strategy;
};

#endif