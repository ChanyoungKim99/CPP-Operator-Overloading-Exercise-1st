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
	}		// ������ ��Ģ�� ���� ���� ���� ǥ��� ����

	// ���⼭�� call by value�̹Ƿ� ����ü ��� ����
};


int main()
{
	Point2D pt1(2, 3);
	Point2D pt2(4, 5);
	Point2D pt3;
	pt3 = pt2 - pt1;

	pt3.Print();
}

// ��¿��� �� �� �ֵ���, ����Լ��� �����Լ��� �� �� �����Ұ��,
// ����Լ��� ȣ��ȴ�!