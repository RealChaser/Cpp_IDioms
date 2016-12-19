// 36_int2type
#include <iostream>
using namespace std;

// 컴파일 시간 상수를 다른 타입으로 만드는 시스템..
// 함수 오버로딩에 사용.
template<int N> struct int2type
{
	enum { value = N };
};

void foo(int n) {}
void foo(int2type<0>) { cout << "0" << endl; }
void foo(int2type<1>) { cout << "1" << endl; }

int main()
{
	foo(0);
	foo(1); // 0,1 은 같은 타입.. foo(0), foo(1)  같은 함수 호출

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1은 다른 타입. foo(t0), foo(t1) 다른 함수 호출.
}