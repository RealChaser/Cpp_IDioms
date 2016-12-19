#include <iostream>
#include <type_traits>
using namespace std;

// ������  1. ����
//        2. ���ܾ����� ����
template<typename T> void Swap(T& a, T& b)
{
	cout << "Swap(T,T)" << endl;

	T tmp = a;
	a = b;
	b = tmp; // ���⼭ ���ܰ� ������ ?
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
// String �������� ����ȭ
template<> void Swap(String& a, String& b)
{
	a.swap(b); // ��� �Լ� ���� �ٽ� ȣ��.
}

int main()
{
	String s1;
	String s2;
	Swap(s1, s2);
}