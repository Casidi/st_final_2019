#ifndef NSL_VECTOR_H
#define NSL_VECTOR_H

#include <exception>

template <class T>
class NSLVector {
public:
	NSLVector() {
		vectorSize = 0;
		bufferSize = 1;
		buffer = new int[bufferSize];
	}

	~NSLVector() {
		delete[] buffer;
	}

	void pushBack(T n) {
		if(vectorSize == bufferSize) {
			bufferSize *= 2;
			T* oldBuffer = buffer;
			buffer = new T[bufferSize];
			for(int i = 0; i < vectorSize; ++i)
				buffer[i] = oldBuffer[i];
			delete[] oldBuffer;
		}

		buffer[vectorSize] = n;
		vectorSize++;
	}

	int size() {
		return vectorSize;
	}

	int capacity() {
		return bufferSize;
	}

	bool empty() {
		return (vectorSize == 0)? true: false;
	}

	T& operator[](int index) {
		if(index < 0)
			throw std::out_of_range("Negative index");
		if(index > vectorSize-1)
			throw std::out_of_range("Index greater than size");
		return buffer[index];
	}

	void clear() {
		vectorSize = 0;
	}

private:
	int vectorSize;
	int bufferSize;
	T* buffer;
};

#endif
