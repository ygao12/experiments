#include "product.h"
#include "factory.h"

using namespace std;

int main() {
  Product *a = GET_CREATOR("ProductA")("ProductA", 100);
  Product *b = GET_CREATOR("ProductB")("ProductB", 200);
  Product *c = GET_CREATOR("ProductC")("ProductC", 300);

  a->Sale();
  b->Sale();
  c->Sale();

  delete a;
  a = NULL;
  delete b;
  b = NULL;
  delete c;
  c = NULL;
  return 0;
}
