#include <iostream>
using namespace std;
#include "fraction.h"

int main()
{
	fraction f1, f2, f3, f4, f5, f6;
	cout << "The results displayed will be the sum, difference, product and quotient.\n " << endl;
	f1 = getFrac();
	f2 = getFrac();
	f3 = f1.addFraction(f2); //Adds the two fractions;
	f3.lowterms(); //Takes the result and reduces it
	f3.print();
	f4 = f1.subFraction(f2); //Subtracts the two fractions
	f4.lowterms(); //Takes the result and reduces it
	f4.print();
	f5 = f1.mulFraction(f2); //Multiplies the two fractions
	f5.lowterms(); //Takes the result and reduces it
	f5.print();
	f6 = f1.divFraction(f2); //Divides the two fractions
	f6.lowterms(); //Takes the result and reduces it
	system("pause");
	return 0;
}