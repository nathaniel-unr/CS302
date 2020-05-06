#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <cstddef>

class Customer {
public:
  Customer(size_t time, size_t duration);

  size_t time;
  size_t duration;
};
#endif