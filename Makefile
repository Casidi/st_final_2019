CPP_FLAGS = -std=c++11 -O0 -fprofile-arcs -ftest-coverage -pthread
INC = -isystem ./googletest-release-1.8.1/googletest/include
OBJS = TestNSLVector.o TestNSLForwardList.o TestNSLDeque.cpp

all: gtest_main

gtest_main: gtest_main.a $(OBJS)
	g++ $(CPP_FLAGS) $(OBJS) $(INC) gtest_main.a -o $@

%.o: %.cpp
	g++ -c $(CPP_FLAGS) $(INC) $<

gtest_main.a:
	wget -O - https://github.com/google/googletest/archive/release-1.8.1.tar.gz | tar -xz
	make -C googletest-release-1.8.1/googletest/make
	cp googletest-release-1.8.1/googletest/make/gtest_main.a .

test: gtest_main
	./gtest_main
	gcov TestNSLVector.cpp > /dev/null
	gcov TestNSLDeque.cpp > /dev/null
	gcov TestNSLForwardList.cpp > /dev/null

show_cov: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory html	
	python3 -m webbrowser html/index.html

clean:
	rm -rf  *.o
	rm -f *.gcov *.gcno *.gcda
	rm -rf *.info html
