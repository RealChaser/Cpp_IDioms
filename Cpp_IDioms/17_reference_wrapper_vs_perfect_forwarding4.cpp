#include <iostream>
#include <thread> // C++11 스레드
using namespace std;

void foo(int& a, int n)
{
	a = 10;
}

int main()
{
	int n = 0;
	thread t(&foo, ref(n), n); // 이 순간 스레드가 생성됩니다. 이순간 n은 값방식으로 전달될까요?
							//							참조 방식으로 전달될까요 ?
						// 값 방식으로 만들었습니다.
						// 그래서 스레드함수 인자가 참조라면 ref()로 묶어서 보내야 합니다..

	t.join();
	cout << n << endl; // 0 ? 10
}





