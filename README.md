# Software-Testing-2019-Final-Project

[![Build Status](https://travis-ci.org/Casidi/st_final_2019.svg?branch=master)](https://travis-ci.org/Casidi/st_final_2019)
[![codecov](https://codecov.io/gh/Casidi/st_final_2019/branch/master/graph/badge.svg)](https://codecov.io/gh/Casidi/st_final_2019)

The final project of the software testing course in NCTU.

## Interfaces to implement:

- Constructors/Destructors
	- [ ] vector()

- Capacity
	- [ ] int size()
	- [ ] void resize(int)
	- [ ] int capacity()
	- [ ] bool empty()
	- [ ] void reserve(int n)

- Element access
	- [ ] int operator[](int index)

- Modifiers:
	- [ ] void push_back(int element)
	- [ ] void pop_back()
	- [ ] void insert(int position, int element)
	- [ ] int erase(int position)
	- [ ] void clear()

## Features under consideration
- CI by using Travis CI
- Coverage by Coveralls
- [Reference repo](https://github.com/bast/gtest-demo)
- Generic types (templates)
- Compatibility with C++ STL
