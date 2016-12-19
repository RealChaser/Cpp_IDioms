#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "복사 생성자가 하는일 없음.. " << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자 하는일 있음. " << endl;
		while (sz--)
		{
			new(dst) T(*src); // 복사 생성자 호출.
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