//
// Created by vesel on 30.09.2018.
//

#include "InputStatus.h"

ge::input::InputStatus::InputStatus()
{
}

ge::input::InputStatus::~InputStatus()
{
    delete m_Keys;
}

bool ge::input::InputStatus::IsPressed(Key key)
{
    return m_Keys[(int) key];
}

void ge::input::InputStatus::SetKeyStatus(bool* keys)
{
    m_Keys = keys;
}
