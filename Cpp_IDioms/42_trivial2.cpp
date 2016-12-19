#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "���� �����ڰ� �ϴ��� ����.. " << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "���� ������ �ϴ��� ����. " << endl;
		while (sz--)
		{
			new(dst) T(*src); // ���� ������ ȣ��.
			++dst, ++src;
		}
	}
}

class Point
{
public:
	Point() = default;
	//Point(const Point& p) {}

	Point(const Point& p) = default;
};

int main()
{
//	char s1[10] = "hello";
//	char s2[10];

	Point s1[10];
	Point s2[10];

	//strcpy(s2, s1);
	copy_type(s2, s1, 10);
}