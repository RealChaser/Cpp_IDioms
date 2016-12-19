#include <iostream>
#include <string>
using namespace std;

void foo(int& r)  { cout << "int&" << endl; }
void foo(int&& r) { cout << "int&&" << endl; }

int main()
{
	string s1;

	s1 = "hello"; // s1      : lvalue, 왼쪽에 있다. 이름이 있다
				  // "hello" : rvalue, 오른쪽에 있다. 이름이 없다.

	foo(s1);		// lvalue reference
	foo("hello"s);	// rvalue reference
	foo(move(s1));  // rvalue reference 호출, 하지만 이름이 있다!!
					// xvalue ( eXpire value )
					// 이름이 있지만, rvalue 로 연결된다.

	string s2 = s1; // 복사 생성자
	string s3 = string("hello"); // move 생성자 호출
	string s4 = move(s1); //  이름이 있지만 move 생성자 호출.

	cout << s2 << endl;
}
	
//  lvalue(s1)      xvalue(move(s1))      prvalue ("hello", string("a"))
//			 glvalue( 이름이 있다)     rvalue(move호출. 수식의 오른쪽)



