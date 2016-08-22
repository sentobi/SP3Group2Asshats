/******************************************************************************/
/*!
\file	AI_Strategy.cpp
\author Muhammad Amirul Bin Zaol-kefli
\par	email: 150509T@mymail.nyp.edu.sg
\brief
Class that Updates the strategy of monster
*/
/******************************************************************************/
#include "AI_Strategy.h"

AI_Strategy::AI_Strategy()
{
}
AI_Strategy::~AI_Strategy()
{
}

AI_Strategy::STRATEGY_MODE AI_Strategy::GetCurrentStrategy()
{
	return currentState;
}
void AI_Strategy::SetState(AI_Strategy::STRATEGY_MODE currentState)
{
	this->currentState = currentState;
}

int AI_Strategy::CalculateDistance(Vector3 MonsterPos, Vector3 Destination)
{
	return int((Destination - MonsterPos).LengthSquared());
}

void AI_Strategy::Update()
{
	float AggressionLevel = monster->GetAggressionStat();
	float FearLevel = monster->GetFearStat();

	if (AggressionLevel > 60 && FearLevel < 50)
	{
		SetState(ATTACK);
	}
	else if (AggressionLevel < 40 && FearLevel > 50)
	{
		SetState(RUN);
	}
	//if (monster collide with trap)
	//{
	//	SetState(TRAPPED);
	//	if(timer > 5)
	//	SetState(Prev State);
	//}
	else
	{
		SetState(IDLE);
	}

}