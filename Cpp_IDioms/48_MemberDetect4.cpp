#include <iostream>
using namespace std;

template<typename T>
class DetectX
{
	struct Fallback { int X; }; // add member name "X"
	struct Derived : T, Fallback { };

	template<typename U, U> struct Check;

	template<typename U>
	static char & func(Check<int Fallback::*, &U::X>*);

	template<typename U>
	static short & func(...);

public:
	typedef DetectX type;
	enum { value = sizeof(func<Derived>(0)) == 2 };
};

struct AA
{
private:
//	int X;
};

int main()
{
	// AA 라는 클래스에 이름이 'X' 라는 멤버가 있는지 확인하는 코드
	cout << DetectX<AA>::value << endl;
}

