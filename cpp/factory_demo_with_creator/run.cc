#include "product.h"
#include "factory.h"

using namespace std;

int main() {
  Product *a = GET_CREATOR("ProductA")("Apple", 100);
  Product *b = GET_CREATOR("ProductB")("Banana", 200);
  Product *c = GET_CREATOR("ProductC")("Cabbage", 300);
  cout << Factory::get().ShowIns() << endl;
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
