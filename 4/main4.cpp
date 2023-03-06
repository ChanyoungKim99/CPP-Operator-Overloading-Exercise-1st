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

	// ���� �� ����
	
	Point2D operator++(int dummy)		// ������ ������ �����ϱ� ���� dummy
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

	pt1.Print();		// ������ pt1 ���� ���´�.
	pt2.Print();		// ���� �� �����̹Ƿ� ���� pt1 ���� ���´�
}