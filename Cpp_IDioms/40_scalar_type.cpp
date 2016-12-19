#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// scalar Ÿ�� : ����� ���� Ÿ���� �ƴ� �͵�..
/*
template< class T >
struct is_scalar : std::integral_constant<bool,
	std::is_arithmetic<T>::value ||     // int, double �迭 Ÿ��.
	std::is_enum<T>::value ||
	std::is_pointer<T>::value ||
	std::is_member_pointer<T>::value ||
	std::is_null_pointer<T>::value> {};   // nullptr
*/

class Point {};

int main()
{
	cout << boolalpha;

	cout << is_scalar<int>::value << endl;
	cout << is_scalar<void(*)()>::value << endl;
	cout << is_scalar<Point>::value << endl;
}



