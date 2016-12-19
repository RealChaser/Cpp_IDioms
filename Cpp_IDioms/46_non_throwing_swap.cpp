#include <iostream>
#include <type_traits>
using namespace std;

// 문제점  1. 성능
//        2. 예외안정성 문제
template<typename T> void Swap(T& a, T& b)
{
	cout << "Swap(T,T)" << endl;

	T tmp = a;
	a = b;
	b = tmp; // 여기서 예외가 나오면 ?
}

class String
{
	char * str;
public:
	void swap(String &s) noexcept
	{
		cout << "String Swap" << endl;
		Swap(this->str, s.str);
	}
};
// String 버전으로 전문화
template<> void Swap(String& a, String& b)
{
	a.swap(b); // 멤버 함수 버전 다시 호출.
}

int main()
{
	String s1;
	String s2;
	Swap(s1, s2);
}