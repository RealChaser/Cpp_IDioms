// 42_trivial
#include <iostream>
#include <type_traits>
using namespace std;

// 42. trivial 
//		�޸� ������ �ƴ϶� ������, �Ҹ���, ���� �����ڸ� ȣ������ �ʾƵ� �Ǵ�����
//		���� ����.


/*
template< class T >
struct is_trivial : std::integral_constant<
	bool,
	std::is_trivially_copyable<T>::value &&
	std::is_trivially_default_constructible<T>::value>
*/

// Trivial default constructor - �����ڰ� �ƹ��ϵ� ���� ������ trivial �ϴ�.
//							    �����ڸ� ȣ������ �ʾƵ� ��밡���Ѱ� ?

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
//	Point() = default; // C++11,   ����Ʈ �����ڸ� ����� �޶�

//	Point() {} // ����Ʈ �����ڰ� ������.. ����ڰ� ���� ��������Ƿ�
				// �ϴ����� ������ �ִ�.

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
	// B�� trivial �� ����Ʈ �����ڰ� ������� ? 
	B* p = (B*)malloc(sizeof(B)); // ������ ȣ�����..

	new(p) B; // placement new �� �����ڸ� ȣ��..

	p->foo(); // ����Ҽ� �־��ٸ� B�� ����Ʈ �����ڴ� trivial �Ѱ��̴�.
}
*/





