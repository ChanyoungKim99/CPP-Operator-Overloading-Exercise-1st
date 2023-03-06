#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D() : mX{ 0 }, mY{ 0 }
	{
	}

	Point2D(int x, int y) : mX{ x }, mY{ y }
	{
	}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;
	}

	Point2D operator-(const Point2D& right)
	{
		Point2D pt;
		pt.mX = mX - right.mX;
		pt.mY = mY - right.mY;

		std::cout << "Member!" << std::endl;
		return pt;
	}

	friend Point2D operator- (const Point2D& left, const Point2D& right)
	{
		std::cout << "Not Member!" << std::endl;
		return Point2D(left.mX - right.mX, left.mY - right.mY);
	}		// 생성자 규칙에 의해 위와 같은 표기법 가능

	// 여기서는 call by value이므로 무명객체 사용 가능
};


int main()
{
	Point2D pt1(2, 3);
	Point2D pt2(4, 5);
	Point2D pt3;
	pt3 = pt2 - pt1;

	pt3.Print();
}

// 출력에서 알 수 있듯이, 멤버함수와 전역함수가 둘 다 존재할경우,
// 멤버함수가 호출된다!