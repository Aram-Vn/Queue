# My Queue Library

---

## Overview

`my::Queue` is a C++ template class that provides a basic implementation of a queue data structure. This queue supports fundamental queue operations such as enqueue, dequeue, front, rear, isEmpty, and size. It is designed to be easy to use and flexible with any data type.

---

## Features

### Constructors and Destructors

- **Default Constructor**: Creates an empty queue.
- **Destructor**: Releases resources and cleans up the queue.
- **Copy Constructor**: Creates a new queue with the same elements as an existing one.
- **Move Constructor**: Efficiently transfers ownership of resources from another queue.

### Modifiers

- `enqueue(T val)`: Inserts an element at the end of the queue (rear).
- `dequeue()`: Removes and returns the element at the front of the queue.
- `front()`: Returns the element at the front of the queue without removing it.
- `rear()`: Returns the element at the rear of the queue without removing it.
- `isEmpty()`: Returns true if the queue is empty; otherwise, returns false.
- `size()`: Returns the current size of the queue.

### Print Elements

- `print()`: Displays all elements in the queue.

---

## Implementation Details

- The queue dynamically allocates memory for its elements and automatically reallocates when the capacity is reached.
- Memory reallocation strategy involves doubling the capacity.

---

## Usage

To use the `my::Queue` class, copy both Queue_declaration.hpp and Queue_impl.hpp files into your project directory. Include the "Queue_declaration.h" header file in your C++ project.

```cpp
#include "Queue_declaration.h"
```

## Compiling:

``bash
g++ -o <your_program_name> main.cpp
``

Once the queue is integrated into your project, you can use the provided functions to work with the queue.

```cpp
#include <iostream>
#include "Queue_declaration.h"

int main() {
    // Create a queue of integers
    my::Queue<int> intQueue;

    // Enqueue elements into the queue
    intQueue.enqueue(42);
    intQueue.enqueue(17);
    intQueue.enqueue(8);

    // Display the front and rear elements
    std::cout << "Front element: " << intQueue.front() << std::endl;
    std::cout << "Rear element: " << intQueue.rear() << std::endl;

    // Dequeue an element
    intQueue.dequeue();

    // Display the size of the queue
    std::cout << "Queue size: " << intQueue.size() << std::endl;

    // Print all elements in the queue
    intQueue.print();

    return 0;
}
```
