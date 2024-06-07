#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

int len(char* str)
{
	int size = 0;
	if (str == nullptr)
	{
		return 0;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}

	return size;
}

int len(const char* str)
{
	int size = 0;
	if (str == nullptr)
	{
		return 0;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}

	return size;
}

bool isValidEmail(const char* email)
{
	const char* domain = "@gmail.com";
	int email_len = len(email);
	int domain_len = len(domain);

	if (email_len <= domain_len)
	{
		return false;
	}

	return strcmp(email + email_len - domain_len, domain) == 0;
}

bool isValidPassword(const char* password)
{
	return len(password) >= 6;
}

bool isValidUsername(const char* user_name)
{
	return len(user_name) >= 4;
}

struct User
{
	char* email;
	char* password;
	char* user_name;

	User()
	{
		email = new char[1000];
		password = new char[1000];
		user_name = new char[1000];
	}

	~User()
	{
		delete[] email;
		delete[] password;
		delete[] user_name;
	}

	void set_email(const char* email)
	{
		strncpy(this->email, email, len(email));
		this->email[len(email)] = '\0';
	}

	char* get_email()
	{
		return email;
	}

	void set_password(const char* password)
	{
		strncpy(this->password, password, len(password));
		this->password[len(password)] = '\0';
	}

	char* get_password()
	{
		return password;
	}

	void set_user_name(const char* user_name)
	{
		strncpy(this->user_name, user_name, len(user_name));
		this->user_name[len(user_name)] = '\0';
	}

	char* get_user_name()
	{
		return user_name;
	}

	void SaveUser()
	{
		std::fstream fs;

		fs.open(email, std::fstream::in | std::fstream::app);

		if (fs.is_open())
		{
			fs << email << "\n";
		}
		else
		{
			std::cout << "Couldn`t open file\n";
		}

		fs.close();

		fs.open("passwords.txt", std::fstream::in | std::fstream::app);

		if (fs.is_open())
		{
			fs << password << "\n";
		}
		else
		{
			std::cout << "Couldn`t open file\n";
		}

		fs.close();

		fs.open("usernames.txt", std::fstream::in | std::fstream::app);

		if (fs.is_open())
		{
			fs << user_name << "\n";
		}
		else
		{
			std::cout << "Couldn`t open file\n";
		}

		fs.close();
	}
};
