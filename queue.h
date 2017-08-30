#ifndef _queue_h_
#define _queue_h_

#include <iostream>

template <typename T>
class Queue {
public:
	Queue(size_t size);
	bool is_full();
	bool is_empty();
	void enqueue(T x);
	T dequeue();
	int get_next_index(int x);
	void print();
	size_t get_length();
	void print_length();
	void clear();

private:
	T* queue;
	size_t capacity;
	int head;
	int tail;
};

#endif