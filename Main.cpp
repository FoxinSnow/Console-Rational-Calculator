#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include"RatNum.h"
#include"User.h"

//function prototypes to be used in main()
bool mainmenu(RatNum*p);
int loginin();

//main function
int main()
{
	signed num1 = 1; signed num2 = 1; //the two numbers to store the rational number
	bool a = true; bool b = true;
	cout << "Welcome to Rational Number Calculator!" << endl;
	if (loginin() == -1) //if input 3 wrong password, program ends
	{
		cout << "Program ends!" << endl;
		return 0;
	}
	RatNum*pRat = new RatNum(&num1, &num2); //else create the object in heap
	while (b == true)
	{
		b = mainmenu(pRat);
	}
	delete pRat; //release the memory
	pRat = 0; //let pRat points 0
	return 0;
}

//implementation of functions used in main()
bool mainmenu(RatNum*p)
{
	//menu of this calculator
	cout << endl;
	cout << "===Main Menu of Rational Calculator===" << endl;
	cout << "a. Input a rational number" << endl;
	cout << "b. Division" << endl;
	cout << "c. Exponential" << endl;
	cout << "d. Current Number" << endl;
	cout << "q. Quit" << endl;
	cout << "Please input your choice: " << endl;
	char choice;
	cin >> choice;
	cin.get(); //empty the buffer
	switch (choice) //switch choice begin
	{
	case'a':
		p->getnum(); //assign a value to num1 and num2
		break;
	case'b':
		p->division();//ask for input of the divisor and do division operation
		p->reduction(); //reduction operation for *a1/*b1
		p->result(); //display the final result
		break;
	case'c':
		p->power(); //find the rational number (input in case 'a') to the power of n
		p->reduction(); //reduction operation for *a1/*b1
		p->result(); //display the final result
		break;
	case 'd':
		p->current(); //show the current number
		break;
	case'q':
		cout << "Goodbye!" << endl; //the application ends if user chooses q
		return false;
	default:
		cout << "Invalid input! Please try again." << endl; //mainmenu will be prompted out again
		break;                                                   //if it is the invalid input
	}
	cout << endl;
	return true;
}
int loginin()
{
	user*puse = new user[60]; //create array in the heap
	char inputname[20];
	char password[20];
	ofstream users0("users.txt", ios::app); //create the file if it doesnt exist
	users0.close();
	ifstream users("users.txt", ios::in); //open the file to input
	for (int i = 0; i < 60; i++) //input the content of file
	{
		char n1[20];
		char n2[20];
		users >> n1;
		users.get(); //get space
		users.getline(n2, 20);
		puse[i].initial(n1, n2); //store the content in the array
	}
	users.close(); //close file
	cout << "User: ";
	cin.getline(inputname, 20); //ask user to input the user name
	for (int i = 0; i < 60; i++) //check if user exists
	{
		if (strcmp(puse[i].nam(), inputname) == 0) //if user exists
		{
			cout << "Password: "; //ask user to input the password
			int checkpass = 0;
			while (checkpass<3) //3 wrong input will lead to program end
			{
				cin.getline(password, 20);
				if (strcmp(puse[i].pas(), password) == 0) //check password
				{
					cout << "Welcome, " << inputname << "!" << endl; //if password is correct
					return 0;
				}
				cout << "Invalid password! " << 2 - checkpass << " chances left." << endl;
				checkpass++; //if password is not correct
			}
			return -1;
		}
	}
	cout << "Welcome, new user! Please enter a password: "; //if user is new one
	char newpass[20]; //get new password
	cin >> newpass;
	cin.get();
	ofstream users1("users.txt", ios::app); //open file to output new user and password
	users1 << endl << inputname << " " << newpass << endl;
	users1.close(); //close file
	delete[] puse; //release memory
	puse = 0; //let puse points 0
	return 1;
}
