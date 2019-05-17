# Software-Testing-2019-Final-Project

[![Build Status](https://travis-ci.org/Casidi/st_final_2019.svg?branch=master)](https://travis-ci.org/Casidi/st_final_2019)
[![codecov](https://codecov.io/gh/Casidi/st_final_2019/branch/master/graph/badge.svg)](https://codecov.io/gh/Casidi/st_final_2019)

The final project of the software testing course in NCTU.

## Useful commands
```bash=
make
make test
make show_cov
```

## Interfaces to implement:

- Constructors/Destructors
	- [x] vector()

- Capacity
	- [x] int size()
	- [ ] void resize(int)
	- [x] int capacity()
	- [x] bool empty()
	- [ ] void reserve(int n)

- Element access
	- [x] int operator[](int index)

- Modifiers:
	- [x] void pushBack(int element)
	- [ ] void popBack()
	- [ ] void insert(int position, int element)
	- [ ] int erase(int position)
	- [x] void clear()
	- [ ] void sort()

## Features under consideration
- ~~CI by using Travis CI~~
- ~~Coverage by Codecov~~
- ~~[Reference repo](https://github.com/bast/gtest-demo)~~
- Generic types (templates)
- Compatibility with C++ STL
