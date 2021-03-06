/******************************************************************************/
/*!
\file	Player.h
\author Foo Jing Ting
\par	email: 152856H@mymail.nyp.edu.sg
\brief
Player class that stores the game's player variables
*/
/******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "Vector3.h"
#include "Items.h"
#include "../GameObject/AABB.h"
#include <vector>
#include <string>

/******************************************************************************/
/*!
Class Player:
\brief	A class that represents the player of the game
*/
/******************************************************************************/
class Player
{
public:
	enum MOVEMENT_STATE
	{
        MOVEMENT_STATE_IDLE,
        MOVEMENT_STATE_CROUCH,
        MOVEMENT_STATE_PRONE,
		MOVEMENT_STATE_WALK,
		MOVEMENT_STATE_RUN,
	};

    enum HEIGHT_STATE
    {
        HEIGHT_STATE_STANDING,
        HEIGHT_STATE_CROUCH,
        HEIGHT_STATE_PRONE,
        HEIGHT_STATE_JUMP,
        HEIGHT_STATE_TOTAL
    };

    Item inventory[Item::NUM_TYPE];

    std::vector<std::string> monsterList;
    std::vector<std::string> capturedMonstersList;

    void ClearCapturedMonsters();

private:
    Vector3 m_position;
    Vector3 m_view;
    Vector3 m_up;
    Vector3 m_velocity;
            
    Vector3 m_prevVelocity;

    float m_eyeLevel;
    float m_speed;
    float m_jumpSpeed;
    float m_gravity;
    float m_jumpHeight;

    float m_health;
    bool b_dead;

    double d_damageTimer;
    const double d_invulnerabilityTime;

    MOVEMENT_STATE m_movementState;
    HEIGHT_STATE m_heightState;

    void pitch(const double dt);
    void yaw(const double dt);

    void crouch();
    void prone();
    void standUp();
    void jump();

    void updateStandUp(const double dt);
    void updateCrouch(const double dt);
    void updateProne(const double dt);
    void updateJump(const double dt);

public:
	Player();
	~Player();

    void ResetPlayer();

    Vector3 GetPositionVector();
    Vector3 GetViewVector();
    Vector3 GetUpVector();
    Vector3 GetVelocityVector();

    float m_noiseFactor;
    bool m_bHiding;

    void Move(const double dt);

    void MoveX(const double dt);
    void MoveZ(const double dt);

    void UpdatePlayerHeight(const double dt);
    void UpdateNoiseFactor();

    float GetNoiseFactor();
    //void SetToHiding();

    bool IsJumping();
    void SetMudSlow();
	void SetLavaDamage();

    bool IsInvulnerable();
    bool IsDead();

    void Update(double dt);
	AABB PlayerHitBox;

    // Health matters
    float GetHealth();
    void TakeDamage(const int damage);

    // possessions
    int m_currency;
    int GetCapturedQuantity(std::string name);
};

#endif