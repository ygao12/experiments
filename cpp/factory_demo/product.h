#pragma once
#include <iostream>

class Product {
 public:
  Product() {}
  virtual ~Product() {}

 public:
  virtual void Say() = 0;
};
