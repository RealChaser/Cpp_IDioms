#include <iostream>
using namespace std;

// 메타 함수 : 컴파일시간에 수행되는 함수
// 특징 : 컴파일 시간 재귀 사용
//		  재귀를 종료 하기 위해 TEMPLATE 전문화 문법을 사용한다.

template<int N> struct Factorial
{
	//int value = 10;
	enum { value = N * Factorial<N-1>::value }; //"enum hack"

	//static const int value = 10;// ok.. 2000년대 초반.. 등장하는 문법.
	
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