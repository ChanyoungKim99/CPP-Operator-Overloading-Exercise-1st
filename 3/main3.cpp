#include <iostream>

// prefix

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

	Point2D operator++()		// ���� �� ����
	{
		++mX;
		++mY;

		//return Point2D(mX, mY);
		return *this;		// �� �ڽ��� �ǵ����� = this�� ������!
	}


		// const�� ����ϸ�, ���� ���ٲ۴�!!
	//friend Point2D operator++ (Point2D& operand)
	//{
	//	
	//	return Point2D(++operand.mX, ++operand.mY);
	//}
};


int main()
{
	Point2D pt1(2, 3);
	Point2D pt2;
	pt2 = ++pt1;

	pt1.Print();
	pt2.Print();
}