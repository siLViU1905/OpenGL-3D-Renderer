#ifndef __EVENT_H__
#define __EVENT_H__

#include "Keyboard.h"
#include "Mouse.h"


enum class EventType
{
   NaN,
   Keyboard,
   Mouse,
   WindowGainedFocus,
   WindowLostFocus,
   WindowResized,
   WindowMoved,
   WindowMaximized,
   WindowClosed
};

class Event
{
  public:
  Event();

  EventType type;

  Keyboard keyboard;

  Mouse mouse;

  bool focused;
};
#endif // __EVENT_H__