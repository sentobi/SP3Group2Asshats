/****************************************************************************/
/*!
\file SceneManager.cpp
\author Bek Kunta
\par email: xiaobek\@gmail.com
\brief
A Class that handles the different scenes
*/
/****************************************************************************/
#include "Application.h"
#include "SceneManager.h"
//#include "../Scene/MainMenu/MenuScene.h"

#include "../Scene/Zone 1/SceneGrass.h"
#include "../Scene/Zone 2/SceneSwamp.h"
#include "../Scene/Zone 3/SceneRock.h"
#include "../Scene/Zone 4/SceneLava.h"
#include "../Scene/Zoo/SceneZoo.h"
#include "../Scene//mainMenu.h"
#include "../General/SharedData.h"

SceneManager::SceneManager() : m_gamestate(GAMESTATE_MAINMENU), m_scene(0)
{
    switch (m_gamestate)
    {
    case GAMESTATE_MAINMENU:
        Application::SetNormalCursor();
        break;
        
    case GAMESTATE_GAMEPLAY:
        Application::SetDisabledCursor();
        break;

    case GAMESTATE_PAUSE:
        Application::SetNormalCursor();
        break;

	case GAMESTATE_FAINT:
		Application::SetNormalCursor();
		break;
    }

    m_mainMenu = new MainMenu();
    m_mainMenu->Init();

    m_pause = new Pause();
    m_pause->Init();

	m_faint = new Faint();
	m_faint->Init();
}

SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(short id)
{
	if (m_scene)
	{
		m_scene->Exit();
		delete m_scene;
	}

	SharedData::GetInstance()->sound->StopAllSounds();

	if (id == 1)
	{
        m_scene = new SceneGrass("Grass");
		Application::SetDisabledCursor();
	}
	else if (id == 2)
	{
		m_scene = new SceneSwamp("Swamp");
		Application::SetDisabledCursor();
	}
    else if (id == 3)
    {
        m_scene = new SceneRock("Rock");
		Application::SetDisabledCursor();
    }
    else if (id == 4)
    {
        m_scene = new SceneLava("Lava");
		Application::SetDisabledCursor();
    }
    else if (id == 5)
    {
        m_scene = new SceneZoo("Zoo");
        Application::SetNormalCursor();
    }

	if (m_scene)
	{
		m_scene->Init();
        m_mainMenu->scene = m_scene;
        m_pause->scene = m_scene;
		m_faint->scene = m_scene;
	}

    if (m_gamestate == GAMESTATE_MAINMENU)
    {
        Application::SetNormalCursor();
    }

    SharedData::GetInstance()->player->ResetPlayer();

    SharedData::GetInstance()->sound->PlayBGM();
}

SceneManager::GAME_STATE SceneManager::GetGameState()
{
    return m_gamestate;
}

void SceneManager::SetMainMenuState()
{
    m_gamestate = GAMESTATE_MAINMENU;
    Application::SetNormalCursor();
}

void SceneManager::SetGameState()
{
    m_gamestate = GAMESTATE_GAMEPLAY;
    //Application::SetDisabledCursor();
}

void SceneManager::SetPauseState()
{
    m_gamestate = GAMESTATE_PAUSE;
    Application::SetNormalCursor();
}

void SceneManager::SetFaintState()
{
	m_gamestate = GAMESTATE_FAINT;
	Application::SetNormalCursor();
}

void SceneManager::SetToExit()
{
    m_gamestate = GAMESTATE_EXIT;
}

void SceneManager::Update(double dt)
{
    switch (m_gamestate)
    {
    case GAMESTATE_MAINMENU:
        m_mainMenu->scene->camera.UpdateForMenu(dt);
        m_mainMenu->Update(dt);
        break;

    case GAMESTATE_GAMEPLAY:
        if (m_scene)
        {
            m_scene->Update(dt);
        }
        break;

	case GAMESTATE_FAINT:
			m_faint->Update(dt);
		break;

    case GAMESTATE_PAUSE:
        m_pause->Update(dt);
        break;
    }

    if (SharedData::GetInstance()->player->IsDead())
    {
		SetFaintState();
    }
}

void SceneManager::Render()
{
    if (m_scene)
	{
		m_scene->Render();
	}

    if (m_gamestate == GAMESTATE_MAINMENU)
    {
        m_mainMenu->Render();
    }
    else if (m_gamestate == GAMESTATE_PAUSE)
    {
        m_pause->Render();
    }
	else if (m_gamestate == GAMESTATE_FAINT)
	{
		m_faint->Render();
	}
}

void SceneManager::Exit()
{
	if (m_scene)
	{
		m_scene->Exit();
		delete m_scene;
	}

    if (m_mainMenu)
    {
        m_mainMenu->Exit();
        delete m_mainMenu;
    }

    if (m_pause)
    {
        m_pause->Exit();
        delete m_pause;
    }

	if (m_faint)
	{
		m_faint->Exit();
		delete m_faint;
	}
}