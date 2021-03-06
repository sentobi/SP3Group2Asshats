#ifndef MONSTER_FIRE_BUGS_H
#define MONSTER_FIRE_BUGS_H

#include "../Monster.h"
#include "../../General/SharedData.h"

class Monster_FireBugs : public Monster
{
public:
    Monster_FireBugs(std::string name, const std::vector<int>& stats);
	virtual ~Monster_FireBugs();

	//Monster Movement update
	virtual void Update(double dt);
    virtual void TakeDamage(const int damage);
	virtual void PlaySoundEffect();
};

#endif