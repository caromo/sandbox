#include "queue.h"
#include <assert.h>
#include <cstdio>

template <typename T>
Queue<T>::Queue(size_t size) {
	queue = 0;
	queue = new T[size + 1];

	// don't need to do this bc `enqueue` gives us elements to fill the array with.
	/*for (int i = 0; i<=size; i++) {
		queue[i] = 0;
	}*/
	capacity = size;
	head = 0;
	tail = 0;
}

template <typename T>
bool Queue<T>::is_empty() {
	return head == tail;
}

template <typename T>
bool Queue<T>::is_full() {
	return head == get_next_index(tail);
}

template <typename T>
int Queue<T>::get_next_index(int x) {
	if (x + 1 < capacity) {
		return x + 1;
	}
	return 0;
}

template <typename T>
void Queue<T>::enqueue(T x) {
	if (!is_full()) {
		queue[tail] = x;
		tail = get_next_index(tail);
	} else {
		std::cout << "Queue is full\n";
	}
}

template <typename T>
T Queue<T>::dequeue() {
	if (is_empty()) {
		std::cout << "Queue is empty\n";
		return 0;
	}

	T value = queue[head];
	queue[head] = 0;
	head = get_next_index(head);
	return value;
}

template <typename T>
void Queue<T>::print() {
	if (is_empty()) {
		std::cout << "Queue is empty\n";
		return;
	}

	// must print elements in order they were added
	for (size_t i = head; i != tail; i = get_next_index(i)) {
		std::cout << queue[i] << " ";
	}
	std::cout << "\n";
}

template <typename T>
size_t Queue<T>::get_length() {
	if (tail >= head) {
		return tail - head;
	}
	return tail + 1 + (capacity - head); // array size = 1 + capacity
}

template <typename T>
void Queue<T>::print_length() {
	std::cout << get_length() << std::endl;
}

template <typename T>
void Queue<T>::clear() {
	queue = 0;
}

// one other suggestion i might make is to make the "print" methods return 
// strings. that might make the messages easier to test. you could test them
// using `assert` calls similar to those below. 
// alternatively, you could create a method that:
// would return an in-order iterator to the elements in the queue. one thing to
// keep in mind is that this must be a `const` iterator so that the callee
// can't modify the contents of the queue. ALSO, i think some might argue that
// this would break the encapsulation of the queue because you can access
// elements without calling `dequeue`. i do not necessarily agree with this,
// but for dave's sake i would not create such an iterator.

int main() {
	Queue<int> test(3);

	test.enqueue(1);
	test.print();
	test.enqueue(2);
	test.print();
	assert(test.get_length() == 2); // `assert` is useful for unit tests

	assert(test.dequeue() == 1);
	assert(test.get_length() == 1);

	test.print();
	test.enqueue(3);
	test.print();
	test.enqueue(8);
	assert(test.get_length() == 3);

	test.print();
	test.enqueue(69);
	test.print();
	assert(test.get_length() == 3);
	return 0;
}