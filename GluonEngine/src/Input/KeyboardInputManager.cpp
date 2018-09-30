//
// Created by vesel on 30.09.2018.
//

#include "KeyboardInputManager.h"

void ge::input::KeyboardInputManager::OnInit(ge::Game* game, ge::input::InputStatus* inputStatus)
{
    m_Status = inputStatus;
    game->GetWindow()->RegisterKeyCallback(&KeyboardInputManager::GLFWKeyCallback);
}

void ge::input::KeyboardInputManager::OnDestroy()
{
    // delete s_Keys;
}

void ge::input::KeyboardInputManager::OnUpdate()
{
    m_Status->SetKeyStatus(KeyboardInputManager::s_Keys);
}

bool ge::input::KeyboardInputManager::s_Keys[1024];
