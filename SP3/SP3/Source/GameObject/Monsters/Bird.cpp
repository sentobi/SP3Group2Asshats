#include "Bird.h"
#include "../AI_Strategy.h"

Monster_Bird::Monster_Bird(std::string name, int stats[]) : Monster(name, stats)
{
    m_strategy = new AI_Strategy();
    m_strategy->Init(this);
}

Monster_Bird::~Monster_Bird()
{
    if (m_strategy)
    {
        delete m_strategy;
        m_strategy = NULL;
    }
}

void Monster_Bird::Update(double dt)
{
    std::cout << " BIRD UPDATE ";
	if ((GetPosition() - SharedData::GetInstance()->player->GetPositionVector()).LengthSquared() > 24)
	{
		//reInit AggressionStat && FearStat
		ResetAggression();
		ResetFear();
	}
	//If near Player, increase aggro
    if ((m_position - SharedData::GetInstance()->player->GetPositionVector()).LengthSquared() < 10)
    {
        std::cout << m_position << std::endl;
        std::cout << "increasing aggression...";
        AggressionLevel = 10;
        changeAggressionStat(m_aggressionStat + AggressionLevel);
        if (AggressionLevel >= 100)
        {
            AggressionLevel = 100;
        }
    }
	//If health < 25, decrease aggro, increase fear
    if (GetHealthStat() < 25)
    {
        AggressionLevel = -20;
        FearLevel = 50;
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
