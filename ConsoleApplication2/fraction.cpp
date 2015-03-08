//Uses a class ‘Fraction’ to perform arithmetic(addition, subtraction, division, multiplication) with fractions.
#include <iostream>
#include < math.h>
#include "fraction.h"
using namespace std;

fraction::fraction(int numerator, int denominator) //constructor of the class
{
	num = numerator;
	den = denominator;
}

// No need for implementing here.
fraction::~fraction() {
	// do nothing.
}

fraction getFrac() //Method for obtaining the fraction from the user
{
	int mixed, num, den;
	cout << "Number entry\n\n";
	cout << "Enter the whole number:";
	cin >> mixed;
	cout << "Enter the numerator:";
	cin >> num;
	cout << "Enter the denominator:";
	cin >> den;
	return fraction(mixed * den + num, den);
}

fraction fraction::addFraction(fraction add) //Method for adding two fractions
{
	add.num = (num * add.den) + (den * add.num);
	add.den = (den * add.den);
	return add;
}
fraction fraction::subFraction(fraction sub) //Method for subtracting two fractions
{
	sub.num = (num * sub.den) - (den * sub.num);
	sub.den = (den * sub.den);
	return sub;
}
fraction fraction::mulFraction(fraction mul) //Method for multiplying two fractions
{
	mul.num = (num * mul.num);
	mul.den = (den * mul.den);
	return mul;
}
fraction fraction::divFraction(fraction div) //Method for dividing two fractions
{
	div.num = (num * div.den);
	div.den = (den * div.num);
	return div; // return result
}
void fraction::lowterms() //Method for reducing the fractions
{
	long tnum, tden, temp, gcd;
	tnum = labs(num);
	tden = labs(den);
	if (tden == 0)
	{
		cout << "Illegal fraction : Division by 0, the solution is undefined";
		exit(1);
	}
	else if (tnum == 0)
	{
		num = 0; den = 1;
		return;
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
void fraction::print() //function for displaying the results a mixed fraction and/or fraction
{
	int x, y;
	if (num > den)
	{
		x = num / den;
		y = num % den;

		cout << "The result is " << x << "   " << y << " / " << den << endl;
	}
	else
		cout << "The result is" << num << "/" << den << endl;
}
fraction fraction::operator+(fraction add) //the operator which impliment addition as a member of function
{
	add.num = (num * add.den) + (den * add.num);
	add.den = (den * add.den);
	return add;
}
fraction fraction::operator-(fraction sub) //the operator which impliments subrection as a member of function
{
	sub.num = (num * sub.den) - (den * sub.num);
	sub.den = (den * sub.den);
	return sub;
}
fraction fraction::operator*(fraction mul) //the operator which impliment multiplication as a member of function
{
	mul.num = (num * mul.num);
	mul.den = (den * mul.den);
	return mul;
}
fraction fraction::operator/(fraction div) //the operator which impliment division as a member of function
{
	div.num = (num * div.den);
	div.den = (den * div.num);
	return div;
}