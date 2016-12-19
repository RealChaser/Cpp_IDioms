// cafe.naver.com/cppmaster   에서 "4일차 사전소스" 받으시면 됩니다.

#include <iostream>
#include <type_traits>
using namespace std;

// 39_POD(Plain Old Data) : C 언어와 호환성을 가질수 있는 자료 구조

class Test
{
private:
	int a;
	char* p;
//public:
	int x;

//	Test() {} //  { p = new char[10]; }
//	virtual void goo() {}
};

template<typename T> void foo(T& obj)
{
	// T가 C와 호환성이 없으면 에러를 발생하게 한다.
	static_assert(is_pod<T>::value, "error, T is not POD");
		
	memset(&obj, 0, sizeof(T));
}

int main()
{
	Test t;
	foo(t);
}





// until C++11
// 1. a scalar type;
// 2. a class type(class or struct or union) that is :
//    an aggregate type;
//	  has no non - static members that are non - POD;
//    has no members of reference type;
//    has no user - defined copy constructor;
//    has no user - defined destructor;
// 3. an array of such type.

// since C++11 - POD는 아래 4가지의 조건을 만족해야 합니다.
// 1. a scalar type;
// 2. a trivial type;
// 3. a standard layout type;
// 4. has no non - static members that are non - POD;

// 기타.. an array of such type.
