//FractionClass.cpp : Uses a class ‘Fraction’ to perform arithmetic(addition, subtraction, division, multiplication) with fractions.
#include <iostream>
using namespace std;
class fraction
{
private:
	int num;
	int den;
	char dummychar; //A variable to hold the “/” character, thrown away at the end
public:
	void getFrac() //Method for obtaining the fraction from the user
	{
		cout << "Enter a fraction :";
		cin >> num >> dummychar >> den;
	}
	fraction addFraction(fraction add) //Method for adding two fractions
	{
		add.num = (num * add.den) + (den * add.num);
		add.den = (den * add.den);
		return add;
	}
	fraction subFraction(fraction sub) //Method for subtracting two fractions
	{
		sub.num = (num * sub.den) - (den * sub.num);
		sub.den = (den * sub.den);
		return sub;
	}
	fraction mulFraction(fraction mul) //Method for multiplying two fractions
	{
		mul.num = (num * mul.num);
		mul.den = (den * mul.den);
		return mul;
	}
	fraction divFraction(fraction div) //Method for dividing two fractions
	{
		div.num = (num * div.den);
		div.den = (den * div.num);
		return div;
	}
	void fraction::lowterms() //Method for reducing the fractions
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num);
		tden = labs(den);
		if (tden == 0)
		{
			cout << "Illegal fraction : Division by 0";
			exit(1);
		}
		else if (tnum == 0)
		{
			num = 0; den = 1; return;
		}
		while (tnum != 0)
		{
			if (tnum < tden)
			{
				temp = tnum; tnum = tden; tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;
		num = num / gcd;
		den = den / gcd;
	}
	void showFrac() const //constructo for displaying the results
	{
		cout << "The result is " << num << " / " << den << endl;
	}
};