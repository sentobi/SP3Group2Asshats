#ifndef MONSTER_GRIMEJAM_H
#define MONSTER_GRIMEJAM_H

#include "../Monster.h"
#include "../../General/SharedData.h"

class Monster_Grimejam : public Monster
{
public:
    Monster_Grimejam(std::string name, const std::vector<int>& stats);
	virtual ~Monster_Grimejam();

	//Monster Movement update
	virtual void Update(double dt);
    virtual void TakeDamage(const int damage);
	virtual void PlaySoundEffect();
};

#endif