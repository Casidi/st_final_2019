all: gtest
	g++ -std=c++11 -O0 -fprofile-arcs -ftest-coverage -isystem ./googletest-release-1.8.1/googletest/include -pthread testMyVector.cpp gtest_main.a -o gtest_main

gtest:
	wget -O - https://github.com/google/googletest/archive/release-1.8.1.tar.gz | tar -xz
	make -C googletest-release-1.8.1/googletest/make
	cp googletest-release-1.8.1/googletest/make/gtest_main.a .

test:
	./gtest_main
	gcov testMyVector.cpp > /dev/null

clean:
	rm -rf googletest* gtest_main gtest_main.a 
	rm -f *.gcov *.gcno *.gcda
