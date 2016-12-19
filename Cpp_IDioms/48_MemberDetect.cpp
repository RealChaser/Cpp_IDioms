#include <iostream>
using namespace std;

// 1. sizeof(함수호출모양) : 진짜 함수 호출아님.. 어느 함수인지 조사하는것
// 2. ... 함수는 마지막 선택됨..
//    암시적 변환이 우선시 됨..

//char  foo(int); // { return 0; }
short foo(int*);// { return 0; }
int   foo(...); // { return 0; }

int main()
{
	// 아래 표현은 함수의 호출이 아닌.
	// 어느 함수가 선택되는지만 조사하는 것 입니다.
	cout << sizeof( foo(0) ) << endl;
	
}
