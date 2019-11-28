#include <iostream>
using namespace std;

//#include <string>


// cout is an object std::ostream (output stream)
class IndexOutOfBoundsException : public exception {
private:
  int m_index{ 0 };
public:
  IndexOutOfBoundsException(int index) {
    cout << "Index " << index << " is out of bounds!" << endl;
  }
};

class IntArray {

private: // shield from external access, part of the internal mechanics
  int* m_ptr{ nullptr };
  int  m_size{ 0 };

  bool IsValidIndex(int index) const {
    return (index >= 0) && (index < m_size);
  }

public:
  IntArray() = default; // default constructor

  explicit IntArray(int size) { // important to prevent conversion from int to IntArray (only for one-argument constructors)
    if (size != 0) {
      m_ptr = new int[size] {}; // on the heap initialized to 0 with the braces
      m_size = size;
    }
  }

  // make deep copy, duplicate the elements, such as every element has its own block of memory
  IntArray(const IntArray& source) {
    if (!source.IsEmpty()) {
      m_size = source.m_size;
      m_ptr = source.m_ptr;

      for (int i = 0; i < source.Size(); i++) {
        m_ptr[i] = source.m_ptr[i];
      }
    }
  }

  ~IntArray() {} // destructor.

  int Size() const { // array content is not modified
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  int& operator[](int index) {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{index};
    }
    return m_ptr[index];
  }

  int operator[](int index) const {
    return m_ptr[index];
  }

  // assignment operator overload
  IntArray& operator=(IntArray source) { // source because passed by value
    swap(*this, source);
    return *this;
  } // destructor at the end


  friend void swap(IntArray& a, IntArray& b) { // not member function, but have access to the members of the class
    using std::swap;
    swap(a.m_ptr, b.m_ptr);
    swap(a.m_size, b.m_size);
  }

  // move constructor
  IntArray(IntArray&& source) { // r-value reference to source array, concretely means that source is a temporary object
    m_ptr = source.m_ptr;
    m_size = source.m_size;

    source.m_ptr = nullptr;
    source.m_size = 0;
  }

  friend ostream& operator<<(ostream& os, const IntArray& a) noexcept { // operator word is (1) print target (2) object to print, const makes sure we don't have duplicates and work on the original data
    // how to print the array
    os << "[ ";
    for (int i = 0; i < a.Size(); i++) {
      os << a[i] << ' ';
    }
    os << " ]";
    return os;
  }
};

int main() {

  try {
    IntArray a{10};
    for (int i = 0; i < a.Size(); i++) {
      a[i] = (i+1)*10;
    }

    cout << "Array elements:" << a << endl;
    cout << " Array size is " << a.Size() << "\n";

    cout << " Please enter an index: ";

    int index{};
    cin >> index;

    cout << " The element at index " << index << " is " << a[index] << '\n';
  }
  catch (const IndexOutOfBoundsException&) {}
  return 0;
};