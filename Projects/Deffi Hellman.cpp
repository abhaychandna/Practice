#include <iostream>
#include<vector>
using namespace std;

#define ll long long int

int modular_exponentiation(int base, int expo, int mod)
{
	int result = 1;
	while (expo > 0)
	{
		if (expo & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		expo = expo >> 1;
	}
	return result;
}

int getPrimitive(int p)
{
	for (int i = 2; i < p; i++)
	{
		bool isPrimitive = true;
		for (int j = p - 2; j > 0; j--)
		{
			if (modular_exponentiation(i, j, p) == 1)
			{
				isPrimitive = false;
				break;
			}
		}
		if (isPrimitive)return i;
	}
	return -1;
}

int main()
{
	cout << "SERVER\n";
	
	int p, e, a, b;
	cout << "Enter large prime number p : " << endl;
	cin >> p;

	e = getPrimitive(p);
	//cout << "G : ";
	//cin >> e;
	
	cout << "primitive element = " << e << endl;

	//cout << "Enter private keys of Alice and Bob " << endl;
	cout << "Enter private key" << endl;
	cin >> a;

	int Xa, Xb;
	Xa = modular_exponentiation(e, a, p);
	cout << "Xa : " << Xa << endl;
	//Xb = modular_exponentiation(e, b, p);
	cout << "Xb : ";
	cin >> Xb;
	
	int Ka, Kb;

	Ka = modular_exponentiation(Xb, a, p);
	//Kb = modular_exponentiation(Xa, b, p);

	cout << "Ka = " << Ka << endl;
	int K = Ka;
	cout << "Common Key exchanged = Ka = Kb = K = " << K << endl;


	return 0;
}
