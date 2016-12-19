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
	// �����Լ��� ������ �Ҷ� ����Ÿ���� �����Ҽ� �ִ�.
	// ��, ��� ������ Ÿ�����θ� �����ϴ�.  int�����δ� �Ҽ� ����.
	// ���� ��ȯ�� ��Ģ(covariant return type)
	virtual Rect* Clone() { return new Rect; }
};

int main()
{

}


