class user
{
public:
	void initial(char* a, char *b); //store information in a element
	char *nam(); //return name
	char *pas(); //return password
private:
	char name[20]; //store the name from file
	char password[20]; //store the password from file
};

