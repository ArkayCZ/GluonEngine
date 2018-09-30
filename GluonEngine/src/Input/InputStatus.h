//
// Created by vesel on 30.09.2018.
//

#ifndef GLUONENGINE_KEYSTATUS_H
#define GLUONENGINE_KEYSTATUS_H

#include <map>
#include "Keys.h"

namespace ge { namespace input {

    class InputStatus
    {
    public:
        InputStatus();
        ~InputStatus();

        bool IsPressed(Key key);
        void SetKeyStatus(bool* keys);
    private:
        bool* m_Keys;
    };
}}


#endif //GLUONENGINE_KEYSTATUS_H
