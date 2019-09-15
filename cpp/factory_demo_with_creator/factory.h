#pragma once
#include <iostream>
#include <functional>
#include <unordered_map>
#include "product.h"

using namespace std;

typedef std::function<Product*(const std::string &, int)> CFunc;
typedef std::unordered_map<std::string, CFunc> ProductMap;

class Factory {
 public:
  Factory() {}
  ~Factory() {}

 public:
  static Factory &get();

 public:
  bool AddIns(const std::string &product_name, const CFunc &cfunc);
  CFunc GetIns(const std::string &product_name);
  inline void ShowIns() {
    std::string all_ins = "\n++++++++++\n";
    for (auto itd : all_products_) {
      all_ins.append("I have product " + itd.first);
    }
    if (all_products_.empty()) {
      all_ins.append("I have no product");
    }
  }
  inline bool IsIns(const std::string &product_name) {
    return (all_products_.find(product_name) != all_products_.end());
  }
 private:
  ProductMap all_products_;
};

template <class T>
struct VirtualTag {};

class RegisterProduct {
 public:
  RegisterProduct(const std::string &product_name, const CFunc &cfunc) {
    Factory::get().AddIns(product_name, cfunc);
  }
  template <class T>
  RegisterProduct(VirtualTag<T>, const std::string &product_name) {
    auto cfunc = [](const string &pname, int price) {
      return static_cast<Product *>(new T(pname, price));
    };
    Factory::get().AddIns(product_name, cfunc);
  }
};

#define REG_PRODUCT(CLS_N) \
  RegisterProduct _##CLS_N(VirtualTag<CLS_N>(), #CLS_N);

#define REG_PRODUCT_ADV(CLS_N, CFUNC) \
  RegisterProduct _##CLS_N(#CLS_N, CFUNC);

#define GET_CREATOR(PNAME) \
  Factory::get().GetIns(PNAME)
