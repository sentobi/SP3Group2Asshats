#include "GL\glew.h"
//#include "../../shader.hpp"

#include "SceneSP3.h"
#include "../../General/Application.h"
//#include "../../Graphics/LoadTGA.h"
//#include "../../Mesh/MeshBuilder.h"

#include <sstream>

SceneSP3::SceneSP3()
{
}

SceneSP3::~SceneSP3()
{
}

void SceneSP3::Init()
{
    bLButtonState = false;
}

void SceneSP3::Update(double dt)
{
    //Calculating aspect ratio
    m_worldHeight = 100.f;
    m_worldWidth = m_worldHeight * (float)Application::GetWindowWidth() / Application::GetWindowHeight();

    double x, y;
    Application::GetCursorPos(&x, &y);
    x = x / Application::GetWindowWidth();
    y = 1.f - y / Application::GetWindowHeight();

    if (!bLButtonState && Application::IsMousePressed(0))
    {
        bLButtonState = true;
    }
    else if (bLButtonState && !Application::IsMousePressed(0))
    {
        bLButtonState = false;
        // do stuff
    }

}

void SceneSP3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Projection matrix : Orthographic Projection
    Mtx44 projection;
    projection.SetToOrtho(0, m_worldWidth, 0, m_worldHeight, -10, 10);
    projectionStack.LoadMatrix(projection);

    // Camera matrix
    viewStack.LoadIdentity();
    // Model matrix : an identity matrix (model will be at the origin)
    modelStack.LoadIdentity();

    //RenderStuff();
}

void SceneSP3::Exit()
{
}

//========================
// == OBJECTS TO RENDER
//========================
