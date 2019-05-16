#ifndef MY_VECTOR_H
#define MY_VECTOR_H

// TODO: move the definition of the methods to a .cpp file

class MyVector {
public:
	MyVector() {
		numElements = 0;
	}

	void pushBack(int n) {
		numElements++;
	}

	int size() {
		return numElements;
	}

	int capacity() {
		return 77;
	}

	int operator[](int index) {
		if(index == 0)
			return 77;
		else
			return 88;
	}

private:
	int numElements;
};

#endif
