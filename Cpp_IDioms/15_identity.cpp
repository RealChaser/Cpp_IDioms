#include <iostream>
using namespace std;

/*
// �Լ� ���ø��� ����� �ν��Ͻ�ȭ�θ� ����ϰ� �ϴ� ���.
// C++11 ǥ���Դϴ�.
template<typename T> struct identity  
{
	typedef T type;
};
*/
//template<typename T> void foo(T a)
template<typename T> void foo( typename identity<T>::type a) // �� �̷��� ������� ?
{
}

int main()
{
//	foo<int>(3); // ����� �ν��Ͻ�ȭ
//	foo(3);      // �Ͻ��� �ν��Ͻ�ȭ

	// C++11 �� �Ϻ��� �����ڿ� ����ϴ� �Լ�
	//forward(3);
	forward<int>(3);
	//list<int> s(10, 3);
}