
// without NRVO
Point foo( Point& temp) // main 이 만들어준 임시객체를 받은후
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p; // temp에 p를 복사 생성자로 복사해준다.
			  // temp.Point::Point(p) 
}

// with NRVO
Point foo(Point& temp)
{
	//Point p;
	p.x = 10;  // 이순간 진짜 p는 없고 main 이 보내준 temp에 넣는다.
	p.y = 20;  //temp.y = 20
	return p;  // return temp
}

int main()
{
	Point p;

	p = foo();   // 임시객체를 메모리만 할당해서 foo의 인자로 전달합니다.
	
	// Point temp; // 생성자 없이 메모리만 할당.
	// foo( temp )

	// p.Point::Point(temp)
	// temp.Point::~Point()
}


