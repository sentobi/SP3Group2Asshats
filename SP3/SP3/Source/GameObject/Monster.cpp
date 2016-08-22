/******************************************************************************/
/*!
\file	Monster.cpp
\author Foo Jing Ting
\par	email: 152856H@mymail.nyp.edu.sg
\brief
Class that defines a monster's variables and statistics
*/
/******************************************************************************/
#include "Monster.h"

Monster::Monster()
{
    // idea: Monster(std::string name);
    // based on name, retrieve stats from a struct/array that already initialised with the stats from the text files
}

Monster::~Monster()
{
}

std::string Monster::GetName()
{
    return m_name;
}

int Monster::GetHealthStat()
{
    return m_healthStat;
}

int Monster::GetCaptureRateStat()
{
    return m_captureRateStat;
}

int Monster::GetAggressionStat()
{
    return m_aggressionStat;
}

int Monster::GetFearStat()
{
    return m_fearStat;
}

bool Monster::CheckCapture()
{
    return false;
}

void Monster::SetPosition(Vector3 m_position)
{
	this->m_position = m_position;
}

Vector3 Monster::GetPosition()
{
	return m_position;
}

void Monster::move()
{
    m_position += m_velocity;   // * dt
}

void Monster::changeHealthStat(const int damage)
{
    m_healthStat -= damage;
}

void Monster::changeAggressionStat(const int aggression)
{
    m_aggressionStat += aggression;
}

void Monster::changeFearStat(const int fear)
{
    m_fearStat += fear;
}

void Monster::changeCaptureRateStat(const int captureRate)
{
    m_captureRateStat += captureRate;
}