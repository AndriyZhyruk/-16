#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "User.h"

int main()
{
	User user;

	std::cout << "Select action: 1 - sign up, 2 - sign in\n";
	int action;
	std::cin >> action;
	std::cin.ignore();

	if (action == 1)
	{
		char email[100];
		char password[100];
		char user_name[100];

		std::cout << "Enter email\n";
		std::cin.getline(email, 100);
		while (!isValidEmail(email))
		{
			std::cout << "Invalid email. Please enter a valid @gmail.com email:\n";
			std::cin.getline(email, 100);
		}

		std::cout << "Enter password\n";
		std::cin.getline(password, 100);
		while (!isValidPassword(password))
		{
			std::cout << "Password must be at least 6 characters long. Enter password again:\n";
			std::cin.getline(password, 100);
		}

		std::cout << "Enter user name\n";
		std::cin.getline(user_name, 100);
		while (!isValidUsername(user_name))
		{
			std::cout << "User name must be at least 4 characters long. Enter user name again:\n";
			std::cin.getline(user_name, 100);
		}

		user.set_email(email);
		user.set_password(password);
		user.set_user_name(user_name);
		user.SaveUser();

		system("cls");

		std::cout << "Your email is: " << user.get_email() << "\n";
		std::cout << "Your password is: " << user.get_password() << "\n";
		std::cout << "Your user name is: " << user.get_user_name() << "\n";
	}
	else if (action == 2)
	{
		// Sign in logic
	}
	else
	{
		std::cout << "Incorrect action\n";
	}
}