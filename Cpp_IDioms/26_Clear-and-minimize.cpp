#include <iostream>
#include <vector>
using namespace std;

// Clear-and-minimize : vector���� �����̳��� capacity�� ���̴� ���
// "swap with temporary" ��� �Ҹ��� ���

int main()
{
	vector<int> v1(10);

	v1.resize(7);

	cout << v1.size() << endl;  // 7
	cout << v1.capacity() << endl; // 10

	//------------------------
	vector<int> v2 = v1;

	cout << v2.size() << endl; // 7
	cout << v2.capacity() << endl; // 7

	// v1�� capacity�� ���̴� ���
	
	vector<int>(v1).swap(v1);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl; // 7



	// C++11 : shrink_to_fit()
	v1.shrink_to_fit();

}


