// PhysicsPracTableStefan'sLaw.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
//#define float r0=1.42f;

struct Value
{
	float current;
	float voltage;
	float resistance;
	float power;
	float temp;
	float ltemp;
};

int main()
{
	int n;
	std::cout << "\nHow many values? : ";
	std::cin >> n;
	double a = 1;

	float r0 = 1.42f;

	struct Value v[30];

	for (int i = 0; i < n;i++)
	{
		std::cout << "\nCurrent(A) : ";
		std::cin >> v[i].current;
		std::cout << "\nVoltage(V) : ";
		std::cin >> v[i].voltage;

		std::cout << "\n-------------";

		v[i].resistance = v[i].current / v[i].voltage;
		v[i].power = v[i].current * v[i].voltage;
		v[i].temp = (static_cast<double>((v[i].resistance / r0)) - a) / 5.2e-4;
		v[i].ltemp = log(v[i].temp);

	}

	std::cout << "\n\n\t ******* Displaying table **********\n\n" << " ";
	std::cout << "\nCurrent\t\tVoltage\t\tResistance\tPower\t\tTemp\t\tLogtemp\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << v[i].current << "\t\t";
		std::cout << v[i].voltage << "\t\t";
		std::cout << v[i].resistance << "\t\t";
		std::cout << v[i].power << "\t\t";
		std::cout << v[i].temp << "\t\t";
		std::cout << v[i].ltemp << "\t\t\n";
	}
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
