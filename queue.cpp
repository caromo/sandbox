#include "queue.h"

Queue::Queue(int size) {
	queue = 0;
	queue = new int[size+1];
	for (int i = 0; i<=size; i++) {
		queue[i] = 0;
	}
	capacity = size;
	head = 0;
	tail = 0;
}
bool Queue::is_empty() {
	if (head == tail) {
		return true;
	} else return false;
}
bool Queue::is_full() {
	if (head == get_next(tail)) {
		return true;
	} else return false;
}
int Queue::get_next(int x) {
	if (x+1 < capacity) {
		return x+1;
	} else return 0;
}
void Queue::enqueue(int x) {
	if (!is_full()) {
		queue[tail] = x;
		tail = get_next(tail);
	} else std::cout << "Queue is full\n"; 
}
int Queue::dequeue() {
	if (!is_empty()) {
		int value = queue[head];
		queue[head] = 0;
		head = get_next(head);
		return value;
	} else {
		std::cout << "Queue is empty\n";
		return 0;
	}
}
void Queue::print() {
	if (!is_empty()) {
		for (int i = 0; i <= capacity; i++) {
			std::cout << queue[i] << " ";
		}
		std::cout << "\n";
	} else std::cout << "Queue is empty\n";
}
void Queue::print_len(){

}
void Queue::clear() {
	queue = 0;
}

int main() {
	Queue test(3);
	test.enqueue(1);
	test.print();
	test.enqueue(2);
	test.print();
	test.dequeue();
	test.print();
	test.enqueue(3);
	test.print();
	test.enqueue(8);
	test.print();
	test.enqueue(69);
	test.print();
	return 0;
}