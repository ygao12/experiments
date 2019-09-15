#include "product_impl.h"

Product *RegisterProductA(const std::string &product_name, int price) {
  Product *p = new ProductA(product_name, price);
  return p;
}

REG_PRODUCT_ADV(ProductA, RegisterProductA);
REG_PRODUCT(ProductB);
REG_PRODUCT(ProductC);
