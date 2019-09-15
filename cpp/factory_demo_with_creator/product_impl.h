#include "product.h"
#include "factory.h"

class ProductA : public Product {
 public :
  ProductA(const std::string &product_name, int price) : Product(product_name, price) {}

 public:
  void Sale() {
    std::cout << product_name_ << " on sale at " << price_ << " price, with A" << std::endl;
  }
};

class ProductB : public Product {
 public :
  ProductB(const std::string &product_name, int price) : Product(product_name, price) {}

 public:
  void Sale() {
    std::cout << product_name_ << " on sale at " << price_ << " price, with B" << std::endl;
  }
};

class ProductC : public Product {
 public :
  ProductC(const std::string &product_name, int price) : Product(product_name, price) {}

 public:
  void Sale() {
    std::cout << product_name_ << " on sale at " << price_ << " price, with C" << std::endl;
  }
};

Product *RegisterProductA(const std::string &product_name, int price);
