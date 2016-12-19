#include <iostream>
using namespace std;

// ��Ÿ �Լ� : �����Ͻð��� ����Ǵ� �Լ�
// Ư¡ : ������ �ð� ��� ���
//		  ��͸� ���� �ϱ� ���� TEMPLATE ����ȭ ������ ����Ѵ�.

template<int N> struct Factorial
{
	//int value = 10;
	enum { value = N * Factorial<N-1>::value }; //"enum hack"

	//static const int value = 10;// ok.. 2000��� �ʹ�.. �����ϴ� ����.
	
	// C++11
	static constexpr int value = N * Factorial<N - 1>::value
};;
};

template<> struct Factorial<1>
{
	enum { value = 1 };
};


int main()
{
	int n = Factorial<5>::value;
			// 5 * F<4>::v 
			//	   4 * F<3>::v
			//			3 * F<2>::v
			//				2 * F<1>::v
			//						1

	cout << n << endl;
}




// C++11 style
constexpr int factorial(int n)
{
	return n == 1 ? 1 : n* factorial(n - 1);
}

factorial(4);