#include<iostream>
using namespace std;
#include"RatNum.h"
//Implementation of RatNum class
RatNum::RatNum(signed*a, signed*b) //constructor, get address
{
	a1 = a;
	b1 = b; //pass by reference
}
void RatNum::getnum()
{
	//get rational number
	bool checkb1 = false;
	cout << "Please input two integers to get the rational number: ";
	do //if b1=0, ask input the rational number again
	{
		cin >> *a1;
		cin >> *b1;
		cin.get();
		if (*b1 == 0)
			cout << "The second number cannot be 0. Input two integers again." << endl;
		else
			checkb1 = true;
	} while (checkb1 == false); //if b1!=0, the do while loop ends

	if (*a1 == 0) //check a1 to adjust display
		cout << "The rational number is 0" << endl; //if a1=0, display 0
	else
		cout << "The rational number is " << *a1 << "/" << *b1 << endl;
}
void RatNum::division()
{
	//get divisor
	bool checka2 = false;
	cout << "Please input two integers to get the divisor: ";
	do   //if a2=0 or b2=0, ask user to input divisor again
	{
		cin >> a2;
		cin >> b2;
		if (b2 == 0)
		{
			cout << "The denominator of the divisor cannot be 0. Please input again!" << endl;
		}
		else if (a2 == 0)
		{
			cout << "The divisor cannot be 0. Please input again!" << endl;
		}
		else
		{
			checka2 = true;
		}
	} while (checka2 == false); //if a2!=0 and b2!=0, do while loop ends

								//cross-multiplication
	*a1 = (*a1)*b2;
	*b1 = (*b1)*a2; //update *a1, *b1 as the division operation
					//reduction begin after this 
}
void RatNum::reduction()
{
	int k; //to store the common factor of |*a1|, |*b1|

		   //get absolute value
	if (*a1 < 0)
		n1 = (-*a1);
	else if (*a1 > 0)
		n1 = *a1; //let n1 store the absolute value of a1
	if (*b1 < 0)
		n2 = (-*b1);
	else if (*b1 > 0)
		n2 = *b1; 
	if (n1 >= n2) //initialize the value of k as the smaller one of n1, n2
	{
		k = n2;
	}
	else
	{
		k = n1;
	}

	//reduction begins here
	while (k > 1) //the smallest value of k should be 2
	{
		if ((*a1%k == 0) && (*b1%k == 0)) //if k is common factor
		{
			*a1 = *a1 / k; //a1 divided by k
			*b1 = *b1 / k; //b1 divided by k
			break;
		}
		k--;
	}
}
void RatNum::result()
{
	//use this function adjust display of result
	if (*a1 == 0) //0 result
		cout << "The result is " << 0 << endl;
	else //result is not 0 or 1
	{
		if (*b1 < 0) //if *b1<0, change the sign of the two integers as display
			cout << "The result is " << 0 - *a1 << "/" << 0 - *b1 << endl;
		else //else, display normal result
			cout << "The result is " << *a1 << "/" << *b1 << endl;
	}
}
void RatNum::current()
{
	//same with function result, display current rational number
	if (*a1 == 0)
		cout << "Current rational number is 0" << endl;
	else
	{
		if (*b1 < 0)
			cout << "Current rational number is " << 0 - *a1 << "/" << 0 - *b1 << endl;
		else
			cout << "Current rational number is " << *a1 << "/" << *b1 << endl;
	}
}
void RatNum::power()
{
	if (*a1 == 0) //the rational number cannot be 0
	{
		do
		{
			cout << "Wrong input, the rational number should not be zero!\n";
			getnum(); //call the getnum() function to input a rational number again
		} while (*a1 == 0); //when the number not 0 do while loop end
	}
	signed reslta = 1, resltb = 1; //store the output for exponential function
	cout << "Please input an integer as the exponent: ";
	cin >> n; //cin the exponent
	if (n == 0)
	{
		reslta = 1;
		resltb = 1; //if n=0, result is 1
	}
	else if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			reslta = reslta*(*a1);
			resltb = resltb*(*b1); //when n>0,do normal exponention
		}
	}
	else
	{
		for (int i = 0; i < (0 - n); i++)
		{
			reslta = reslta*(*b1);
			resltb = resltb*(*a1); //when n<0, the result should be the 
		}                       //reciprocal of the original number
	}
	*a1 = reslta;
	*b1 = resltb; //update the values of *a1, *b1, for futher reduction and display results
}