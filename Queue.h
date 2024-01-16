#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

namespace my {
    template <class T>
    class Queue
    {
    public:
        Queue();  // defolt constructor
        ~Queue(); // destructor

        Queue(const Queue& other);     // copy constructor
        Queue(Queue&& other) noexcept; // move constructor

    public:
        void enqueue(T val);  // Inserts an element at the end of the queue i.e. at the rear end.
        T dequeue();          // This operation removes and returns an element that is at the front end of the queue.
        T front();            // This operation returns the element at the front end without removing it.
        T rear() const;       // This operation returns the element at the rear end without removing it.
        bool isEmpty() const; // This operation indicates whether the queue is empty or not.
        size_t size() const;  // This operation returns the size of the queue i.e. the total number of elements it contains.
        void print();         // prints elements

    private:
        void realloc(); // reallocates memory by doubling it

    private:
        size_t m_cap;   // queu capasity
        size_t m_end;   // current size
        size_t m_start; // starting index
        T* m_ptr;       // our queu
    };

} // namespace my

#include "Queue_impl.hpp"

#endif // QUEUE_H
