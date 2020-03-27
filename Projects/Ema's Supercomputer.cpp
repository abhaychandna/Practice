//DONT fucking ask how i did this 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{

	int n, m;
	cin >> n >> m;

	int arr[15][15] = { (0,0) };
	/*
	for (int i = 0; i < n; i++)
	{
		char c[25];
		char g = 'G';
		cin >> c;
		for (int j = 0; j < m; j++)
		{
			///string c;
			//cin >> c;
			if (c[j] == 71)
				arr[i][j] == 1;
		}
	}

	*/
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			char c[20][20];
			cin >> c[i][j];
			if (c[i][j] == (int)'G')
				arr[i][j] = 0;
			else
				arr[i][j] = -1;
		}
	}


	int num[2] = { 1,1 };
	int length[15][15] = { (-1,-1) };
	//int k=0;
	int count = 0,less;
	int square = min(n, m);
	int flag = 0;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			length[i][j] = arr[i][j];
		}


	if (square%2==0)
		square--; 

	while (square > 0)
	{
		for (int row = square/2; row + square/2 < n ; row++)
		{
			for (int col = square/2; col + square/2 < m ; col++)
			{
				//less = min(row, col) + 1 ;
				if (arr[row][col] == 0)
				{
					flag = 1;
					for (int check = 1; check <= (square - 1) / 2; check++)
					{
						if (arr[row][col + check] == 0 && arr[row + check][col] == 0 && arr[row][col - check] == 0 && arr[row - check][col] == 0)
							continue;
						else
						{
							flag = 0;
							break;
							
						}
					}
				}
				else
					continue;
				if (flag==1)
				{
					//num[count] = (2 * square) - 1;
					//count++;
					//flag = 0;
					if(square!=1 && length[row][col]==0)
						length[row][col] = (square-1)/2;

				}
			}
		}
		square -= 2;
	}

	int max = 1;
	int one = 0,two=0;
	int temp[15][15] = { (0,0) };
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			int mlength = length[i][j];
			int originalLength = length[i][j];
			for (int z = 1; z <= mlength; z++)
			{
				one = 1; two = 1;
				if (mlength != -1 && mlength != 0) // may not be needed
				{
					one = mlength;

					int l1 = (4 * one) + 1;
					if (max < l1 * two)
						max = l1 * two;

					flag = 1;

					temp[i][j] = one;
					length[i][j] = -1;
					for (int t = 1; t <= one; t++)
					{
						temp[i + t][j] = length[i + t][j];
						temp[i - t][j] = length[i - t][j];
						temp[i][j - t] = length[i][j - t];
						temp[i][j + t] = length[i][j + t];

						length[i + t][j] = -1;
						length[i - t][j] = -1;
						length[i][j + t] = -1;
						length[i][j - t] = -1;
					}

					for (int i2 = i; i2 < n - 1; i2++)
					{
						for (int j2 = 0; j2 < m - 1; j2++)
						{
							flag = 1;

							if (length[i2][j2] != -1 && length[i2][j2] != 0)
							{
								int dlength = length[i2][j2];
								for (int k = 1; k <= dlength; k++)
								{
									if (length[i2 + k][j2] < 0 || length[i2 - k][j2] < 0 || length[i2][j2 + k] < 0 || length[i2][j2 - k] < 0)
									{
										if (dlength > 0)
										{
											k = 0;
											dlength--;
											continue;
										}
										flag = 0;
										break;
									}
								}
								if (flag == 0)
								{
									continue;
								}
								//if (flag == 1)

								two = dlength;
								int l2 = (4 * two) + 1;
								if (max < (l1 * l2))
									max = l1 * l2;

							}
						}
					}

					length[i][j] = originalLength;
					temp[i][j] = 0;

					for (int t = 1; t <= one; t++)
					{
						length[i + t][j] = temp[i + t][j];
						length[i - t][j] = temp[i - t][j];
						length[i][j + t] = temp[i][j + t];
						length[i][j - t] = temp[i][j - t];

						temp[i + t][j] = 0;
						temp[i - t][j] = 0;
						temp[i][j + t] = 0;
						temp[i][j - t] = 0;
					}

					
				}
			
				mlength--;

			}
		}
	}


	cout << max;
	return 0;

}