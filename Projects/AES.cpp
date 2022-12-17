#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

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


vector<vector<string>> sbox_string = 
{
	{"63", "7c", "77", "7b", "f2", "6b", "6f", "c5", "30", "01", "67", "2b", "fe", "d7", "ab", "76"},
	{ "ca", "82", "c9", "7d", "fa", "59", "47", "f0", "ad", "d4", "a2", "af", "9c", "a4", "72", "c0" },
	{ "b7", "fd", "93", "26", "36", "3f", "f7", "cc", "34", "a5", "e5", "f1", "71", "d8", "31", "15" },
	{ "04", "c7", "23", "c3", "18", "96", "05", "9a", "07", "12", "80", "e2", "eb", "27", "b2", "75" },
	{ "09", "83", "2c", "1a", "1b", "6e", "5a", "a0", "52", "3b", "d6", "b3", "29", "e3", "2f", "84" },
	{ "53", "d1", "00", "ed", "20", "fc", "b1", "5b", "6a", "cb", "be", "39", "4a", "4c", "58", "cf" },
	{ "d0", "ef", "aa", "fb", "43", "4d", "33", "85", "45", "f9", "02", "7f", "50", "3c", "9f", "a8" },
	{ "51", "a3", "40", "8f", "92", "9d", "38", "f5", "bc", "b6", "da", "21", "10", "ff", "f3", "d2" },
	{ "cd", "0c", "13", "ec", "5f", "97", "44", "17", "c4", "a7", "7e", "3d", "64", "5d", "19", "73" },
	{ "60", "81", "4f", "dc", "22", "2a", "90", "88", "46", "ee", "b8", "14", "de", "5e", "0b", "db" },
	{ "e0", "32", "3a", "0a", "49", "06", "24", "5c", "c2", "d3", "ac", "62", "91", "95", "e4", "79" },
	{ "e7", "c8", "37", "6d", "8d", "d5", "4e", "a9", "6c", "56", "f4", "ea", "65", "7a", "ae", "08" },
	{ "ba", "78", "25", "2e", "1c", "a6", "b4", "c6", "e8", "dd", "74", "1f", "4b", "bd", "8b", "8a" },
	{ "70", "3e", "b5", "66", "48", "03", "f6", "0e", "61", "35", "57", "b9", "86", "c1", "1d", "9e" },
	{ "e1", "f8", "98", "11", "69", "d9", "8e", "94", "9b", "1e", "87", "e9", "ce", "55", "28", "df" },
	{ "8c", "a1", "89", "0d", "bf", "e6", "42", "68", "41", "99", "2d", "0f", "b0", "54", "bb", "16" },
};

vector<vector<int>> sbox = {
	{99,124,119,123,242,107,111,197,48,1,103,43,254,215,171,118},
	{202,130,201,125,250,89,71,240,173,212,162,175,156,164,114,192},
	{183,253,147,38,54,63,247,204,52,165,229,241,113,216,49,21},
	{4,199,35,195,24,150,5,154,7,18,128,226,235,39,178,117},
	{9,131,44,26,27,110,90,160,82,59,214,179,41,227,47,132},
	{83,209,0,237,32,252,177,91,106,203,190,57,74,76,88,207},
	{208,239,170,251,67,77,51,133,69,249,2,127,80,60,159,168},
	{81,163,64,143,146,157,56,245,188,182,218,33,16,255,243,210},
	{205,12,19,236,95,151,68,23,196,167,126,61,100,93,25,115},
	{96,129,79,220,34,42,144,136,70,238,184,20,222,94,11,219},
	{224,50,58,10,73,6,36,92,194,211,172,98,145,149,228,121},
	{231,200,55,109,141,213,78,169,108,86,244,234,101,122,174,8},
	{186,120,37,46,28,166,180,198,232,221,116,31,75,189,139,138},
	{112,62,181,102,72,3,246,14,97,53,87,185,134,193,29,158},
	{225,248,152,17,105,217,142,148,155,30,135},
};

void prar(vector<vector<int>> stateArray) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << std::hex << stateArray[i][j] << " ";
		}
		cout << endl;
	}
}
ll Ynot()
{
	ll ans = 0;

	string plaintext = "abhay";
	string key = "aryan";

	vector<vector<int>> keyMatrix(4, vector<int>(4, 0));
	vector<vector<int>> plainMatrix(4, vector<int>(4, 0));
	
	vector<vector<int>> stateArray(4, vector<int>(4, 0));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			stateArray[i][j] = keyMatrix[i][j] xor plainMatrix[i][j];
		}
	}

	// Convert stateArray to S-Box
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int row = stateArray[i][j] / 16;
			int col = stateArray[i][j] % 16;
			stateArray[i][j] = sbox[row][col];
		}
	}
	
	// shift rows
	for(int i=0;i<4;i++){
		for (int j = 0; j < i; j++) {
			int temp = stateArray[i][0];
			for (int k = 0; k < 3; k++) {
				stateArray[i][k] = stateArray[i][k + 1];
			}
			stateArray[i][3] = temp;
		}
	}
	
	//mix columns
	for(int i=0;i<4;i++)
	{
		int a0 = stateArray[0][i];
		int a1 = stateArray[1][i];
		int a2 = stateArray[2][i];
		int a3 = stateArray[3][i];
		
		stateArray[0][i] = (a0 * 2) xor (a1 * 3) xor (a2 * 1) xor (a3 * 1);
		stateArray[1][i] = (a0 * 1) xor (a1 * 2) xor (a2 * 3) xor (a3 * 1);
		stateArray[2][i] = (a0 * 1) xor (a1 * 1) xor (a2 * 2) xor (a3 * 3);
		stateArray[3][i] = (a0 * 3) xor (a1 * 1) xor (a2 * 1) xor (a3 * 2);
	}
	
	vector<vector<int>> roundKey = {
		{ 0x2b, 0x28, 0xab, 0x09 },
		{ 0x7e, 0xae, 0xf7, 0xcf },
		{ 0x15, 0xd2, 0x15, 0x4f },
		{ 0x16, 0xa6, 0x88, 0x3c }
	};
	
	// round 1 key
	
	
	// add round key
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			stateArray[i][j] = stateArray[i][j] xor roundKey[i][j];
		}
	}
	
	// print state array
	prar(stateArray);
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}