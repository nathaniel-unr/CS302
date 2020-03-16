#include "LinkedList.h"
#include <iostream>
#include <limits>

void display_menu() {
  std::cout << "Menu\n"
            << "a) Add a new item\n"
            << "b) Delete an item\n"
            << "c) Show the number of items\n"
            << "d) Show all items\n"
            << "e) Exit\n"
            << std::endl;
}

char read_letter() {
  char c = 0;
  std::cin >> c;
  return c;
}

int read_num() {
  int n = 0;
  std::cin >> n;
  if (!std::cin) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return n;
}

template <typename T> void display_list(LinkedList<T> &list) {
  LinkedListIter<T> iter = list.iter();
  std::cout << "Linked List\n";
  for (int i = 0; iter.is_valid(); i++, iter.advance())
    std::cout << i << ") " << iter.current()->data() << "\n";
  std::cout << std::endl;
}

int main() {
  bool exit = false;
  LinkedList<int> list = LinkedList<int>();
  char option;
  while (!exit) {
    display_menu();
    option = read_letter();
    std::cout << std::endl;

    int val;
    int pos;

    switch (option) {
    case 'a':
      std::cout << "Value: " << std::endl;
      val = read_num();
      if (val != -1) {
        std::cout << "Position: " << std::endl;
        pos = read_num();
        if (pos > -1) {
          if (!list.insert(pos, val)) {
            std::cout << "Failed to insert value." << std::endl;
          } else {
            std::cout << "Inserted value." << std::endl;
          }
        } else {
          std::cout << "Invalid Index: " << pos << std::endl;
        }
      } else {
        std::cout << "Invalid input." << std::endl;
      }

      break;
    case 'b':
      std::cout << "Position: " << std::endl;
      pos = read_num();
      if (pos > -1) {
        Node<int> *ret = list.remove(pos);
        if (ret == NULL) {
          std::cout << "Failed to remove element." << std::endl;
        } else {
          std::cout << "Removed element." << std::endl;
          delete ret;
        }
      } else {
        std::cout << "Invalid Index: " << pos << std::endl;
      }
      break;
    case 'c':
      std::cout << "Size: " << list.size() << std::endl;
      break;
    case 'd':
      display_list(list);
      break;
    case 'e':
      exit = true;
      std::cout << "Goodbye." << std::endl;
      break;
    default:
      std::cout << "Unrecognized option: " << option << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}