#include <iostream>
#include <cstddef>

using namespace std;

template<class T, class Comp>
class BHeap {
public:
	BHeap(unsigned int = 16);
	~BHeap();
	void insert(T);
	T getTop();
	T extractTop();
	void alterKey(int, T);
	bool isEmpty();
	size_t size();
private:
	void heapify(int);
	int left(int);
	int right(int);
	int parent(int);
	void ensureCapacity();

	size_t _size;
	size_t capacity;
	Comp comp;
	T *data;
};


bool my_comp(const int &a, const int &b) {
	return a > b;
}

template<class T>
struct Max {
	bool operator()(const T &a, const T &b) const {
		return a > b;
	}
};

template<class T>
struct Min {
	bool operator()(const T &a, const T &b) const {
		return a < b;
	}	
};

int main() {
	BHeap<int, Min<int>> mp(4);
	mp.insert(10);
	mp.insert(20);
	mp.insert(1);
	mp.insert(-100);
	mp.insert(400);
	mp.insert(400.1);  
	mp.alterKey(2, 1200);
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;

	mp.insert(98);

	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	cout << mp.extractTop() << endl;
	
	cout << mp.getTop() << endl;

	return 0;
}



/******* DEFINEATION *********/


template<class T, class Comp>
BHeap<T, Comp>::BHeap(unsigned int n) {
	data = new T[n];
	_size = 0;
	capacity = n;
}

template<class T, class Comp>
BHeap<T, Comp>::~BHeap() {
	delete [] data;
}

template<class T, class Comp>
T BHeap<T, Comp>::getTop() {
	if (_size < 1) {
		return -1;
	}
	return data[0];
}

template<class T, class Comp>
void BHeap<T, Comp>::insert(T val) {
	ensureCapacity();
	int valIndx = _size++;
	data[valIndx] = val;
	int p = parent(valIndx);
	while (p >= 0 && comp(data[valIndx], data[p])) {
		swap(data[valIndx], data[p]);
		valIndx = p;
		p = parent(p);
	}
	cout << "insert " << val << endl;
}

template<class T, class Comp>
T BHeap<T, Comp>::extractTop() {
	if (isEmpty()) {
		return -1;
	}
	T extractedVal = data[0];
	swap(data[0], data[_size - 1]);
	_size--;
	heapify(0);
	return extractedVal;
}

template<class T, class Comp>
void BHeap<T, Comp>::heapify(int i) {
	int largest = i;
	int leftChild = left(i);
	int rightChild = right(i);

	if (leftChild < _size && comp(data[leftChild], data[largest])) {
		largest = leftChild;
	}
	if (rightChild < _size && comp(data[rightChild], data[largest])) { // <
		largest = rightChild;
	}
	if (largest != i) {
		swap(data[largest], data[i]);
		heapify(largest);
	}
}


template<class T, class Comp>
void BHeap<T, Comp>::alterKey(int i, T val) {
	if (i < _size && i >= 0 && comp(val, data[i])) {
		data[i] = val;
		int p = parent(i);
		while (i >= 0 && comp(data[i], data[p])) {
			swap(data[i], data[p]);
			i = p;
			p = parent(p);
		}
	}
} 

template<class T, class Comp>
size_t BHeap<T, Comp>::size() {
	return _size;
}

template<class T, class Comp>
bool BHeap<T, Comp>::isEmpty() {
	return _size < 1;
}

template<class T, class Comp>
int BHeap<T, Comp>::left(int i) {
	return (2 * i) + 1;
}

template<class T, class Comp>
int BHeap<T, Comp>::right(int i) {
	return (2 * i) + 2;
} 

template<class T, class Comp>
int BHeap<T, Comp>::parent(int i) {
	return (i - 1) / 2;
}

template<class T, class Comp>
void BHeap<T, Comp>::ensureCapacity() {
	if (_size >= capacity) {
		cout << "Size Full, Increasing Capacity!!!: " <<  "prev - " << capacity << ", now - ";
		capacity *= 2;
		T *newData = new T[capacity];
		copy(data, data + _size, newData);
		delete [] data;
		data = newData;
		cout << capacity << endl;
	}
}
