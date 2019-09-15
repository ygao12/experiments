#pragma once
#include <iostream>

using namespace std;

class Product {
 public:
  Product(const std::string &product_name, int price) {
    product_name_ = product_name;
    price_ = price;
  }
  virtual ~Product() {}
 public:
  virtual void Sale() = 0;

 public:
  std::string product_name_;
  int price_;
};
