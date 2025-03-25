#include "Event.h"

Event::Event()
{
    keyboard.key=keyboard.action=keyboard.scancode=keyboard.mode=0;
    mouse.button=mouse.action=mouse.button=0;
    type=EventType::NaN;
    focused=true;
}
