class RatNum
{
public:
	RatNum(signed*a, signed*b); //get address, pass by reference
	void division(); //ask for the input of a rational number as the divisor and do division
	void getnum(); //ask for the input of a rational number and check its validity
	void reduction(); //reduction used n1 n2 as absolute value
	void result(); //show result according to different situation
	void current(); //show current rational number
	void power(); //exponential calculation, if original rational number is 0, ask input again

private:
	signed*a1; //store the first address
	signed*b1; //store the second address
	int n1; //store absolute value
	int n2; //store absolute value
	signed a2; //the first number of divisor
	signed b2; //the second number of divisor
	signed n = 1; //the power to the rational number, initialize as 1
};

