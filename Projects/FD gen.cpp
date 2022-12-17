#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<chrono>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 5

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 10000

// Define the maximum number of edges
#define MAX_EDGES 20000

// Define the maximum weight of edges
#define MAXWEIGHT 1000

#define START 1023
#define END 9023

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	// Uncomment the below line to store
	// the test data in a file
	freopen("Test_Cases_Undirected_Weighted_Graph_1e5.txt",
			 "w", stdout);

	//For random values every time
	srand(time(NULL));

	int NUM; // Number of Vertices
	int NUMEDGE; // Number of Edges

	printf("%d\n", RUN);
	for (int i = 1; i <= RUN; i++)
	{
		//NUM = 1 + rand() % MAX_VERTICES;
		NUM = MAX_VERTICES;

		// Define the maximum number of edges of the graph
		// Since the most dense graph can have N*(N-1)/2 edges
		// where N = number of vertices in the graph
		//NUMEDGE = 1 + rand() % MAX_EDGES;
		NUMEDGE = MAX_EDGES;

		while (NUMEDGE > NUM* (NUM - 1) / 2)
			NUMEDGE = 1 + rand() % MAX_EDGES;

		// First print the number of vertices and edges
		printf("%d %d\n", NUM, NUMEDGE);

		// Then print the edges of the form (a b)
		// where 'a' is connected to 'b'
		for (int j = 1; j <= NUMEDGE; j++)
		{
			int a = rand() % NUM;
			int b = rand() % NUM;
			pair<int, int> p = make_pair(a, b);
			pair<int, int> reverse_p = make_pair(b, a);

			// Search for a random "new" edge everytime
			// Note - In a tree the edge (a, b) is same
			// as the edge (b, a)
			while (container.find(p) != container.end() ||
				container.find(reverse_p) != container.end())
			{
				a = rand() % NUM;
				b = rand() % NUM;
				p = make_pair(a, b);
				reverse_p = make_pair(b, a);
			}
			container.insert(p);
		}

		for (it = container.begin(); it != container.end(); ++it)
		{
			int wt = 1 + rand() % MAXWEIGHT;
			printf("%d %d %d\n", it->first + 1, it->second + 1, wt);
		}

		container.clear();
		printf("\n");
		printf("%d %d", START, END);
		printf("\n");
	}

	// Uncomment the below line to store
	// the test data in a file
	fclose(stdout);
	return(0);
}
