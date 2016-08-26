#include "FireBugs.h"
#include "../AI_Strategy.h"

Monster_FireBugs::Monster_FireBugs(std::string name, const std::vector<int>& stats) : Monster(name, stats)
{
    m_strategy = NULL;
}

Monster_FireBugs::~Monster_FireBugs()
{
    if (m_strategy != NULL)
    {
        delete m_strategy;
        m_strategy = NULL;
    }
}

void Monster_FireBugs::Update(double dt)
{
    if ((m_position - SharedData::GetInstance()->player->GetPositionVector()).LengthSquared() > 24)
	{
		//reInit AggressionStat && FearStat
		ResetAggression();
		ResetFear();
	}
	//If near Player, increase aggro
    if ((m_position - SharedData::GetInstance()->player->GetPositionVector()).LengthSquared() < 16)
	{
		AggressionLevel = 25;
		changeAggressionStat(m_aggressionStat + AggressionLevel);
		if (AggressionLevel >= 100)
		{
			AggressionLevel = 100;
		}
	}
	//If health < 25, decrease aggro, increase fear 
	if (GetHealthStat() < 25)
	{
		AggressionLevel = -5;
		FearLevel = 15;
		changeAggressionStat(m_aggressionStat + AggressionLevel);
		changeFearStat(m_fearStat + FearLevel);
		if (AggressionLevel <= 0)
		{
			AggressionLevel = 0;
		}
		if (FearLevel >= 100)
		{
			FearLevel = 100;
		}
	}

	//Get Aggression Stat and Fear Stat
	GetAggressionStat();
	GetFearStat();

	//Update Strategy accordingly
	m_strategy->Update();
}

void Monster_FireBugs::TakeDamage(const int damage)
{
    changeHealthStat(m_healthStat - damage);
}