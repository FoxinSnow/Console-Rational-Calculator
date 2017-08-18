#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include"User.h"
void user::initial(char*a, char *b)
{
	strncpy(name, a, 20); //store the name
	strncpy(password, b, 20); //store the password
}
char*user::nam()
{
	return name; //return name store in this object
}
char*user::pas()
{
	return password; //return password store in this object
}