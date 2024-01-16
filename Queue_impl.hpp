#ifndef QUEUE_IMPL_HPP
#define QUEUE_IMPL_HPP

template <class T>
my::Queue<T>::Queue() : m_cap{0}, m_end{0}, m_start{0}, m_ptr{nullptr} {}

template <class T> my::Queue<T>::~Queue() {
  m_cap = 0;
  m_end = 0;
  m_start = 0;
  if (m_ptr != nullptr) {
    delete[] m_ptr;
  }
}

template <class T>
my::Queue<T>::Queue(const Queue &other)
    : m_end{other.m_end}, m_cap{other.m_cap}, m_start{other.m_start},
      m_ptr{new T[m_cap]} {
  for (size_t i = m_start; i < m_end; ++i) {
    this->m_ptr[i] = other.m_ptr[i];
  }
}

template <class T>
my::Queue<T>::Queue(Queue &&other) noexcept
    : m_end{other.m_end}, m_cap{other.m_cap}, m_start{other.m_start},
      m_ptr{other.m_ptr} {
  other.m_end = 0;
  other.m_cap = 0;
  other.m_start = 0;
  other.m_ptr = nullptr;
}

template <class T> void my::Queue<T>::enqueue(T val) {
  if (m_end == m_cap) {
    realloc();
  }

  m_ptr[m_end++] = val;
}

template <class T> T my::Queue<T>::dequeue() {
  T val = m_ptr[m_start];

  ++m_start;

  if (m_start == m_cap / 2 && m_cap > 8) {
    size_t k = 0;

    for (size_t i = m_start; i < m_end; ++i) {
      m_ptr[k] = m_ptr[i];
      ++k;
    }
  }

  return val;
}

template <class T> T my::Queue<T>::front() {
  if (!isEmpty()) {
    return m_ptr[m_start];
  } else {
    std::cout << "for my::Queue<T>::front()\nQueue is Empty" << std::endl;
    exit(0);
  }
}

template <class T> T my::Queue<T>::rear() const {
  if (!isEmpty()) {
    return m_ptr[m_end - 1];
  } else {
    std::cout << "for my::Queue<T>::rear()\nQueue is Empty" << std::endl;
    exit(0);
  }
}

template <class T> bool my::Queue<T>::isEmpty() const {
  return this->size() == 0;
}

template <class T> size_t my::Queue<T>::size() const { return m_end - m_start; }

template <class T> void my::Queue<T>::realloc() {
  m_cap = (m_cap) ? 2 * m_cap : 1;

  T *tmp_ptr = new T[m_cap];

  for (size_t i = m_start; i < m_end; ++i) {
    tmp_ptr[i] = m_ptr[i];
  }

  delete[] m_ptr;
  m_ptr = tmp_ptr;
}

template <class T> void my::Queue<T>::print() {
  for (size_t i = m_start; i < m_end; ++i) {
    std::cout << m_ptr[i] << std::endl;
  }
}

#endif // QUEUE_IMPL_HPP
