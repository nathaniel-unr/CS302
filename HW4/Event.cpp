#include "Event.h"

Event::Event(EventType type, size_t time, size_t duration)
    : type(type), time(time), duration(duration) {}
Event::Event(EventType type, size_t time)
    : type(type), time(time), duration(0) {}

bool Event::operator<(const Event &b) const { return time < b.time; }