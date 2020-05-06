#ifndef _EVENT_H_
#define _EVENT_H_
#include <cstddef>

enum EventType {
  Arrival,
  Departure,
};

class Event {
public:
  Event(EventType type, size_t time, size_t duration);
  Event(EventType type, size_t time);

  bool operator<(const Event &b) const;

  EventType type;
  size_t time;
  size_t duration;
};
#endif