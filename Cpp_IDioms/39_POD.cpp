// cafe.naver.com/cppmaster   ���� "4���� �����ҽ�" �����ø� �˴ϴ�.

#include <iostream>
#include <type_traits>
using namespace std;

// 39_POD(Plain Old Data) : C ���� ȣȯ���� ������ �ִ� �ڷ� ����

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
	// T�� C�� ȣȯ���� ������ ������ �߻��ϰ� �Ѵ�.
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

// since C++11 - POD�� �Ʒ� 4������ ������ �����ؾ� �մϴ�.
// 1. a scalar type;
// 2. a trivial type;
// 3. a standard layout type;
// 4. has no non - static members that are non - POD;

// ��Ÿ.. an array of such type.
