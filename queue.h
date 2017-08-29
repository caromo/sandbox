#ifndef _queue_h_
#define _queue_h_
#include <iostream>


class Queue{
public:
	Queue(int size);
	bool is_full();
	bool is_empty();
	void enqueue(int x);
	int dequeue();
	int get_next(int x);
	void print();
	void print_len();
	void clear();


private:
	int* queue;
	int capacity;
	int head;
	int tail;

};

#endif