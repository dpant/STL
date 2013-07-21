/* 
  Big picture:: 
  We will take each of the topic and expand on it.
  Excerpts are taken from the Excellent Video.
  Thank you "Stephan T. Lavavej"


=========================================================== PART 8 ==================================================================



*/
#define TEST1
/*	
	rvalue reference
	std::move()
*/

#include <algorithm>
#include <iostream>
#include <ostream>
#include <utility>
using namespace std;
 
class remote_integer {
public:
    remote_integer() {
        m_p = nullptr;
    }
 
    explicit remote_integer(const int n) {
        m_p = new int(n);
    }
 
    remote_integer(const remote_integer& other) {
        if (other.m_p) {
            m_p = new int(*other.m_p);
        } else {
            m_p = nullptr;
        }
    }
 
    remote_integer(remote_integer&& other) {
        m_p = other.m_p;
        other.m_p = nullptr;
    }
 
 
    remote_integer& operator=(const remote_integer& other) {
        remote_integer(other).swap(*this);
        return *this;
    }
 
    remote_integer& operator=(remote_integer&& other) {
        remote_integer(move(other)).swap(*this);
        return *this;
    }
 
 
#if 0
    remote_integer& operator=(remote_integer other) {
        other.swap(*this);
        return *this;
    }
#endif
 
 
    ~remote_integer() {
        delete m_p;
    }
 
    int get() const {
        return m_p ? *m_p : 0;
    }
 
    void swap(remote_integer& other) {
        std::swap(m_p, other.m_p);
    }
 
private:
    int * m_p;
};
 
remote_integer square(const remote_integer& r) {
    const int i = r.get();
 
    return remote_integer(i * i);
}
 
 
class remote_point {
public:
    remote_point(const int x_arg, const int y_arg)
        : m_x(x_arg), m_y(y_arg) { }
 
    remote_point(remote_point&& other)
        : m_x(move(other.m_x)),
          m_y(move(other.m_y)) { }
 
    remote_point& operator=(remote_point&& other) {
        m_x = move(other.m_x);
        m_y = move(other.m_y);
        return *this;
    }
 
    int x() const { return m_x.get(); }
    int y() const { return m_y.get(); }
 
private:
    remote_integer m_x;
    remote_integer m_y;
};
 
remote_point five_by_five() {
    return remote_point(5, 5);
}
 
remote_point taxicab() {
    remote_point ret(729, 1000);
 
    return ret;
}
 
 
int main() {
    remote_integer a(8);
 
    cout << a.get() << endl;
 
    remote_integer b(10);
 
    cout << b.get() << endl;
 
    b = square(a);
 
    cout << b.get() << endl;
 
 
    remote_point p = five_by_five();
 
    cout << "(" << p.x() << ", " << p.y() << ")" << endl;
 
    p = taxicab();
 
    cout << "(" << p.x() << ", " << p.y() << ")" << endl;
}
