#include <iostream>
using namespace std;

// Member Detect  : 특정 멤버 data가 있는지 확인하는 기술.

template<typename T, T> struct Check;

//Check<int, 10> c;
// 아래 표현은 Test에 x멤버가 있으면 ok.. 없으면 error
//Check<int(Test::*), &Test::x> c2;

class Test
{
private:
	int x;
};

//char  foo( Check<int Test::*, &Test::x>* );
//short foo(...) ;

// 치환 실패는 에러가 아니라 함수 오버로딩에서 제외 된다는 특징을 이용한기술
// private 에 x가 있으면 치환 실패가 아니라.. error..
template<typename T> char  foo( Check<int T::*, &T::x>* );
template<typename T> short foo(...) ;

int main()
{
	cout << sizeof(foo<Test>(0)) << endl;
}



/*
	int Test::*p = &Test::x; // 멤버 data 주소 구하는 법.
					// Test 안에 x의 위치.. offset 0
	Test t;

	t.*p = 10; // t.x = 10
	*/
//}





