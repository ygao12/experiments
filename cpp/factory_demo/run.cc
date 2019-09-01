#include "factory.h"

int main() {
  Factory::ShowAllIns();
  Factory::GetIns("ProductA")->Say();
  Factory::GetIns("ProductB")->Say();
  Factory::GetIns("ProductC")->Say();
  Factory::Destroy();
  Factory::ShowAllIns();
}
