
// without NRVO
Point foo( Point& temp) // main �� ������� �ӽð�ü�� ������
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p; // temp�� p�� ���� �����ڷ� �������ش�.
			  // temp.Point::Point(p) 
}

// with NRVO
Point foo(Point& temp)
{
	//Point p;
	p.x = 10;  // �̼��� ��¥ p�� ���� main �� ������ temp�� �ִ´�.
	p.y = 20;  //temp.y = 20
	return p;  // return temp
}

int main()
{
	Point p;

	p = foo();   // �ӽð�ü�� �޸𸮸� �Ҵ��ؼ� foo�� ���ڷ� �����մϴ�.
	
	// Point temp; // ������ ���� �޸𸮸� �Ҵ�.
	// foo( temp )

	// p.Point::Point(temp)
	// temp.Point::~Point()
}


