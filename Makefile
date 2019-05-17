all: gtest_main.a
	g++ -std=c++11 -O0 -fprofile-arcs -ftest-coverage -isystem ./googletest-release-1.8.1/googletest/include -pthread TestNSLVector.cpp gtest_main.a -o gtest_main

gtest_main.a:
	wget -O - https://github.com/google/googletest/archive/release-1.8.1.tar.gz | tar -xz
	make -C googletest-release-1.8.1/googletest/make
	cp googletest-release-1.8.1/googletest/make/gtest_main.a .

test:
	./gtest_main
	gcov TestNSLVector.cpp > /dev/null

show_cov: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory html	
	python3 -m webbrowser html/index.html

clean:
	rm -rf googletest* gtest_main gtest_main.a 
	rm -f *.gcov *.gcno *.gcda
	rm -rf *.info html
