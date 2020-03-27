// SortUsingSwap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int length(9);
int t = -1;
void sort(int a[])
{
	int g;
	for (int i = 0; i < 4; i++)            // doesnt work due to aray length
	{
		g = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (a[j] > a[g])
				g = j;
		}
		std::swap(a[i], a[g]);
	}

}
void bubblesort(int a[])
{
	int k = length, check = 0;
	for (int i = 0; i < 8; i++)
	{
		check = 0;
		for (int j = 1; j < k-1; j++)
		{
			if (a[j] < a[j - 1])
			{
				std::swap(a[j], a[j - 1]); check = 1;
			}
		}
		k--;
		if(check==0)
		{
			t = i;
			break;
		}
	}
}

int main()
{
	
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	
	
	//sort(a);
	bubblesort(array);

	std::cout << t;

	for (int i = 0; i < 9; i++)
		std::cout << array[i];

	

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
