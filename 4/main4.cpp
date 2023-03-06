#include <iostream>

// postfix

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

	// 대입 후 증가
	
	Point2D operator++(int dummy)		// 전위와 후위를 구분하기 위한 dummy
	{
		Point2D temp(mX, mY);

		mX++;
		mY++;
		return temp;
	}

	//friend Point2D operator++ (Point2D& operand, int dummy)
	//{
	//	Point2D temp(operand.mX, operand.mY);

	//	operand.mX++;
	//	operand.mY++;

	//	return temp;
	//}
};

int main()
{
	Point2D pt1(2, 3);
	Point2D pt2;
	pt2 = pt1++;

	pt1.Print();		// 증가한 pt1 값이 나온다.
	pt2.Print();		// 대입 후 증가이므로 원래 pt1 값이 나온다
}