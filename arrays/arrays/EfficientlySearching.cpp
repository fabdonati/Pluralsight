#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array {
private:
  T* m_ptr;
  int m_size;

  bool IsValidIndex(int index) const {
    return (index>=0) && (index<m_size);
  }
public:
};

constexpr int kNotFound = -1; // use whenever a const integer is required (at compile time and not at runtime)

template <typename T>
int Search(T element, const T v, int size) {
  for (int = 0; i < size; i++) {
    if (v[i] == element) {
      return i;
    }
  }
  return kNotFound;
}

template <typename T>
void Print(const vector<T>& v) {
  cout << " [";
  for (T x : v) {
    cout << x << ' ';
  }
  cout << " ]\n";
}