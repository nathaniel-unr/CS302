#include "Customer.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void load_inputs(PriorityQueue<Event> &queue) {
  std::ifstream input_file("input.txt");
  std::string text;
  while (std::getline(input_file, text)) {
    std::istringstream ss(text);
    size_t time = 0;
    size_t duration = 0;
    ss >> time;
    ss >> duration;
    queue.enqueue(Event(EventType::Arrival, time, duration));
  }
}

int main() {
  PriorityQueue<Event> event_queue;
  Queue<Customer> bank_line;
  bool teller_available = true;
  size_t current_time = 0;
  size_t total_processed = 0;
  size_t total_wait_time = 0;

  load_inputs(event_queue);

  std::cout << "Simulation Begins" << std::endl;

  while (!event_queue.is_empty()) {
    Event e = event_queue.dequeue();
    current_time = e.time;

    switch (e.type) {
    case EventType::Arrival:
      std::cout << "Processing an arrival event at time: " << e.time
                << std::endl;
      if (teller_available && bank_line.is_empty()) {
        size_t time = e.time + e.duration;
        event_queue.enqueue(Event(EventType::Departure, time, 0));
        teller_available = false;
      } else {
        bank_line.enqueue(Customer(e.time, e.duration));
      }

      break;
    case EventType::Departure:
      std::cout << "Processing a departure event at time: " << e.time
                << std::endl;

      total_processed++;

      if (!bank_line.is_empty()) {
        Customer c = bank_line.dequeue();
        total_wait_time += current_time - c.time;
        size_t time = current_time + c.duration;
        event_queue.enqueue(Event(EventType::Departure, time, 0));
      } else {
        teller_available = true;
      }
      break;
    }
  }

  std::cout << "Simulation Ends" << std::endl << std::endl;

  std::cout << "Final Statistics: " << std::endl;
  std::cout << "    "
            << "Total number of people processed: " << total_processed
            << std::endl;
  std::cout << "    "
            << "Average amount of time spent waiting: "
            << ((float)total_wait_time / (float)total_processed) << std::endl;

  return 0;
}