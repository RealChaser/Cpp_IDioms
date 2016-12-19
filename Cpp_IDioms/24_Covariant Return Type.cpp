// 23. Covariant Return Types

#include <iostream>
using namespace std;

class Shape
{
public:
	virtual Shape* Clone() = 0;
};
class Rect : public Shape
{
public:
	// 가상함수를 재정의 할때 리턴타입을 변경할수 있다.
	// 단, 상속 계층의 타입으로만 가능하다.  int등으로는 할수 없다.
	// 공변 반환의 법칙(covariant return type)
	virtual Rect* Clone() { return new Rect; }
};

int main()
{

}


