#include <iostream>
#include "Queue.h"

int main(){
	my::Queue<int> q;

	std::cout << q.size() << " SIZE" << std::endl;

	for(int i = 0; i < 15; ++i){
		q.enqueue(i);
	}

	q.print();
	std::cout << q.size() << " SIZE" << std::endl;

	for(int i = 0; i < 5; ++i){
		std::cout << q.dequeue() << std::endl;
	}

	std::cout << q.size() << " SIZE" << std::endl;
	q.print();
}
