// C++多态性.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CStudent.h"
#include "CGraudateAtudent.h"
#include "CTutorial.h"
#include "other.h"

float getTuition(CStudent& rs)
{
	return rs.calcTuition();
}

int main(void)
{
	CStudent s;
	CTutorial tu;
	CGraudateAtudent gs;
	cout << getTuition(s) << endl;
	cout << getTuition(gs) << endl;
	

	CComplex a(1, 2), b(3, 4);
	CComplex::showComplex(a + b);
	CComplex::showComplex(a - b);
	double c = double(a + b);
	cout << "c: " << c << endl;
    return 0;
}

