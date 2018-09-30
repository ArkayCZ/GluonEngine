//
// Created by vesel on 30.09.2018.
//

#ifndef GLUONENGINE_KEYBOARDINPUTMANAGER_H
#define GLUONENGINE_KEYBOARDINPUTMANAGER_H

#include "InputManager.h"
#include "../Graphics/Window.h"
#include "../Game.h"

namespace ge { namespace input {
    class KeyboardInputManager : public InputManager
    {
    private:
        InputStatus* m_Status;
        static bool s_Keys[1024];
    public:
        KeyboardInputManager() = default;
        ~KeyboardInputManager() = default;

        void OnInit(ge::Game* game, InputStatus* inputStatus) override;
        void OnUpdate() override;
        void OnDestroy() override;

        /* Needs to be static beacuse GLFW cannot accept a member function pointer. */
        static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (action == GLFW_PRESS)
            {
                KeyboardInputManager::s_Keys[key] = true;
            }
            else if (action == GLFW_RELEASE)
            {
                KeyboardInputManager::s_Keys[key] = false;
            }

        }
    };
}}


#endif //GLUONENGINE_KEYBOARDINPUTMANAGER_H
