#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void foo(int a, int& b) { cout << "foo" << endl; b = 100; }

int main()
{
	int n1 = 10;

	function<void(int)> f;

	// bind는 인자를 고정할때 복사본, 즉 값으로 보관하고 있게 된다...
	// 참조로 보관할수 없었다.
	//f = bind(&foo, _1, n1); // foo의 2번째인자를 n1으로 고정한다.
	
//	f = bind(&foo, _1, &n1); // n1의 주소를 보관한다. 하지만 원본으로 보낼때는
								// 주소가 다시 참조로 변해야 한다. error

	//reference_wrapper<int> r1 = n1;
	//f = bind(&foo, _1, r1); // 결국 r1은 n1의 주소를 담고 있다.
							// 그리고 r1은 int& 로 변환 가능하다.

	//f = bind(&foo, _1, reference_wrapper<int>(n1) );
	f = bind(&foo, _1, ref(n1)); // ref()가 결국 reference_wrapper<>를 생성해 줍니다.


	f(5); // foo( 5, n1);

	cout << n1 << endl;
}




