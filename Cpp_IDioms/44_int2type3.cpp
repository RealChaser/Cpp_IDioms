// 36_int2type
#include <iostream>
#include <type_traits>
using namespace std;

template<int N> struct int2type
{
	enum { value = N };
};
typedef int2type<0> false_type;

template<typename T> void foo_imp(const T& value, false_type) { cout << "포인터가 아닐때 알고리즘" << endl; }
template<typename T> void foo_imp(const T& value, int2type<1>)
{
	cout << "포인터일때 알고리즘" << endl; 
}


template<typename T> void foo(const T& value)
{
	// 포인터와 아닐때에 따라서 분기 하고 싶을때.. 
	//foo_imp(value, is_pointer<T>::value );
					// 1
					// 0

	foo_imp(value, int2type<is_pointer<T>::value>() );
}

int main()
{
	int n = 0;
	foo(&n);
}