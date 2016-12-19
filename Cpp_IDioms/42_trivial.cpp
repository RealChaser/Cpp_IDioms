// 42_trivial
#include <iostream>
#include <type_traits>
using namespace std;

// 42. trivial 
//		메모리 구조가 아니라 생성자, 소멸자, 복사 생성자를 호출하지 않아도 되는지에
//		대한 개념.


/*
template< class T >
struct is_trivial : std::integral_constant<
	bool,
	std::is_trivially_copyable<T>::value &&
	std::is_trivially_default_constructible<T>::value>
*/

// Trivial default constructor - 생성자가 아무일도 하지 않으면 trivial 하다.
//							    생성자를 호출하지 않아도 사용가능한가 ?

// The default constructor for class T is trivial(i.e.performs no action) if all of the following is true :
// 1. The default constructor is not user - provided(i.e., is implicitly - defined or defaulted)
// 2. T has no virtual member functions
// 3. T has no virtual base classes
// 4. T has no non - static members with default initializers.
// 5. Every direct base of T has a trivial default constructor
// 6. Every non - static member of class type has a trivial default constructor


class Point
{
	int x;
	int y;
public:
//	Point() = default; // C++11,   디폴트 생성자를 만들어 달라

//	Point() {} // 디폴트 생성자가 있지만.. 사용자가 직접 만들었으므로
				// 하는일이 있을수 있다.

//	Point(int a, int b) : x(a), y(b) {}	

	//virtual void foo() {}
};

int main()
{
	cout << boolalpha;
	cout << is_trivially_constructible<Point>::value << endl;
}


/*
class B
{
	int x;
public:
	//virtual void foo() {}
};
int main()
{
	// B는 trivial 한 디폴트 생성자가 있을까요 ? 
	B* p = (B*)malloc(sizeof(B)); // 생성자 호출안함..

	new(p) B; // placement new 로 생성자만 호출..

	p->foo(); // 사용할수 있었다면 B의 디폴트 생성자는 trivial 한것이다.
}
*/





