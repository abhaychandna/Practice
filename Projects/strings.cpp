#include<iostream>
#include<string>

int main()
{
	std::string name;
	int age;
	std::cin >> name;
	std::cin >> age;
	int a = age/name.length();
	std::cout << a;
	return 0;
}