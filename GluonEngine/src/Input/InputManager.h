//
// Created by vesel on 30.09.2018.
//

#ifndef GLUONENGINE_INPUTMANAGER_H
#define GLUONENGINE_INPUTMANAGER_H

#include "InputStatus.h"

namespace ge { class Game; }

namespace ge { namespace input {

    class InputManager
    {
    public:
        virtual void OnInit(ge::Game* game, InputStatus* inputStatus) = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDestroy() = 0;
    };
}}



#endif //GLUONENGINE_INPUTMANAGER_H
