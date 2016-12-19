#include <iostream>
#include <type_traits>
using namespace std;


// C++ 표준 enable_if

// enable_if<bool값, T>::type  => bool값이 참이면 type은 T가 된다.
//							      bool값이 거짓이면 type은 없다. 치환 실패..
//									=> 함수가 생성되지 않게 할수 있다.

template<bool, typename T = void> struct xenable_if {};

template<typename T> struct xenable_if<true, T>
{
	typedef T type;
};

// 정수형을 처리하는 함수를 만들고 싶다.
template<typename T> typename xenable_if<is_integral<T>::value, T>::type  square( T a)
{
	return a * a;
}

// T가 정수 일 때만 만들어 지게 하고 싶다.
//template<typename T> void foo(T a) {}

template<typename T> typename xenable_if<is_integral<T>::value>::type  foo(T a) {}


// 아래 코드는 어떨까요 ?
// enable_if를 함수 인자의 타입으로 사용 ??
template<typename T> void goo( typename enable_if<is_integral<T>::value, T>::type a)

int main()
{
	//square(3.3);
	square(3);
}





