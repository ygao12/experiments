#pragma once
#include "product.h"
#include "factory.h"

class ProductA : public Product {
 public:
  void Say() {
    std::cout << "This is ProductA speaking" << std::endl;
  }
};

class ProductB : public Product {
 public:
  void Say() {
    std::cout << "This is ProductB speaking" << std::endl;
  }
};

class ProductC : public Product {
 public:
  void Say() {
    std::cout << "This is ProductC speaking" << std::endl;
  }
};

inline Product *RegA() {
  Product *product = new ProductA();
  return product;
}

REGISTER_PRODUCT_ADV(ProductA, RegA());
REGISTER_PRODUCT(ProductB);
REGISTER_PRODUCT(ProductC);
