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
int Search(T element, const T* v, int size) {
  for (int i = 0; i < size; i++) {
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

int main() {
  vector<int> v{33, 44, 55, 11, 22};
  Print(v);

  cout << "Element to search? ";
  int x;
  cin >> x;
  cout << "\n";

  int pos = Search(x, v.data(), v.size());
  if (pos == kNotFound) {
    cout << "element not found!";
  }
  else {
    cout << "element found at index " << pos << endl;
  }
}