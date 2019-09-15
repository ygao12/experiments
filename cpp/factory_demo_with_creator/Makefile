objects = factory.o product.o product_impl.o
main : $(objects)
	g++ -std=c++11 -fPIC -o run $(objects) run.cc

factory.o : factory.h factory.cc product.o
	g++ -std=c++11 -c factory.cc
product.o : product.h product.cc
	g++ -std=c++11 -c product.cc
product_impl.o : product_impl.h product_impl.cc product.o factory.o
	g++ -std=c++11 -c product_impl.cc

.PHONY : clean
clean :
	rm -f run $(objects)
