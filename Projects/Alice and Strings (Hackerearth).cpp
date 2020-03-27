/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	int k = 0;
	cin >> a >> b;
	if (a.length() != b.length() || a[a.length() - 1] != b[b.length() - 1])
		k = 1;//cout<<"NO\n";
	else
	{
		for (int i = a.length() - 2; i >= 0; i--)
		{
			char aa = a[i], bb = b[i];
			int p = aa, q = bb;
			if (p < q)
			{
				int r = q - p;
				for (int j = 0; j <= i; j++)
				{
					if (a[j] + r <= 'z')
						a[j] = a[j] + r;
					else
						goto lbl;
				}
			}
			else if (p == q)
				continue;
			else
			{lbl:
				break;
			}

			//if(i==0)
			  //  cout<<"YES\n";
		}
		if (a == b)
			cout << "YES";
		else
			cout << "NO\n";
	}

}