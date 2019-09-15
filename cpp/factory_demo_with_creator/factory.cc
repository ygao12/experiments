#include "factory.h"

Factory &Factory::get() {
  static Factory instance;
  return instance;
}

bool Factory::AddIns(const std::string &product_name, const CFunc &cfunc) {
  if (all_products_.find(product_name) != all_products_.end()) {
    return false;
  }
  all_products_.insert(std::make_pair(product_name, cfunc));
  return true;
}

CFunc Factory::GetIns(const std::string &product_name) {
  if (all_products_.find(product_name) != all_products_.end()) {
    return all_products_[product_name];
  }
  Product *pd = NULL;
  auto cfunc = [pd](const std::string &, int) { return pd; };
  return cfunc;
}
