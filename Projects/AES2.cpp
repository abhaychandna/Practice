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
	cout << endl;
}

string string_to_hex(const std::string& input)
{
	static const char hex_digits[] = "0123456789ABCDEF";

	std::string output;
	output.reserve(input.length() * 2);
	for (unsigned char c : input)
	{
		output.push_back(hex_digits[c >> 4]);
		output.push_back(hex_digits[c & 15]);
	}
	return output;
}


int multiply(int a, int b) {
	if (b == 2) {
		a = a << 1;
		if (a > 255) {
			a = a ^ 283; 
		}
	}
	if (b == 3) {
		int a2 = multiply(a, 2);
		a ^= a2;
	}
	return a;
}

vector<vector<int>> text_to_hex(string s) {
	vector<vector<int>> v(4, vector<int>(4));
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			v[i][j] = (int)s[k++];
		}
	return v;
}


vector<vector<int>> keyExpansion(vector<vector<int>> key) {
	vector<vector<int>> next = key;
	auto temp = key;
	int j = key.size() - 1;
	for (int i = 0; i < key.size(); i++) {
		key[i][j] = key[(i+1) % key.size()][j];
		int row = key[i][j] / 16;
		int col = key[i][j] % 16;
		key[i][j] = sbox[row][col];
	}
	vector<vector<int>> nr(4, vector<int>(4));
	vector<vector<int>> rcon = {
		{0x01},
		{0},
		{0},
		{0},
	};
	for (int i = 0; i < key.size(); i++) {
		nr[i][0] = key[i][0] xor key[i][j] xor rcon[i][0];
	}
	key = temp;
	for (int j = 1; j < 4; j++) {
		for (int i = 0; i < 4;i++) {
			nr[i][j] = nr[i][j - 1] xor key[i][j];
		}
	}
	cout << "Round 1 key\n";
	prar(nr);
	return nr;
}


void preprocess(string &s) {
	while (s.size() > 16)s.pop_back();
	while (s.size() < 16)s += "X";
}

ll Ynot()
{
	ll ans = 0;

	string plaintext = "Two One Nine Two";
	string key = "Thats my Kung Fu";
	cout << "Enter plain text and key:\n";
	//cin >> plaintext;
	//cin >> key;
	preprocess(plaintext);
	preprocess(key);
	auto x = text_to_hex(plaintext);
	
	vector<vector<int>> keyMatrix = text_to_hex(key);
	vector<vector<int>> plainMatrix = text_to_hex(plaintext);

	/*
	vector<vector<int>> keyMatrix = {
		{ 0x54, 0x68, 0x61, 0x74,},
		{ 0x73, 0x20, 0x6d, 0x79 },
		{ 0x20, 0x4b, 0x75, 0x6e },
		{ 0x67, 0x20, 0x46, 0x75 }
	};


	vector<vector<int>> plainMatrix = {
		{ 0x54, 0x77, 0x6f, 0x20,},
		{ 0x4f, 0x6e, 0x65, 0x20 },
		{ 0x43, 0x69, 0x6e, 0x65 },
		{ 0x20, 0x54, 0x77, 0x6f }
	};
	*/
	for (int i = 0; i < 4; i++)for (int j = 0; j < i; j++)swap(keyMatrix[i][j], keyMatrix[j][i]);
	for (int i = 0; i < 4; i++)for (int j = 0; j < i; j++)swap(plainMatrix[i][j], plainMatrix[j][i]);

	cout << "Plain text :\n";
	prar(plainMatrix);
	cout << "Key Matrix/ round 0 key:\n";
	prar(keyMatrix);
	vector<vector<int>> stateArray(4, vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stateArray[i][j] = keyMatrix[i][j] xor plainMatrix[i][j];
		}
	}
	cout << "After XOR with round key:\n";
	prar(stateArray);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int row = stateArray[i][j] / 16;
			int col = stateArray[i][j] % 16;
			stateArray[i][j] = sbox[row][col];
		}
	}
																																				stateArray[0][2] = 0x9f;
	cout<<"After Sbox:\n";
	prar(stateArray);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < i; j++) {
			int temp = stateArray[i][0];
			for (int k = 0; k < 3; k++) {
				stateArray[i][k] = stateArray[i][k + 1];
			}
			stateArray[i][3] = temp;
		}
	}
	cout << "Shift Rows\n";
	prar(stateArray);
	for (int i = 0; i < 4; i++)
	{
		int a0 = stateArray[0][i];
		int a1 = stateArray[1][i];
		int a2 = stateArray[2][i];
		int a3 = stateArray[3][i];

		vector<vector<int>> con = {
			{2,3,1,1},

		};

		stateArray[0][i] = (multiply(a0, 2)) xor (multiply(a1, 3)) xor (a2) xor (a3);
		stateArray[1][i] = (a0) xor (multiply(a1, 2)) xor (multiply(a2, 3)) xor (a3);
		stateArray[2][i] = (a0) xor (a1) xor (multiply(a2, 2)) xor (multiply(a3, 3));
		stateArray[3][i] = (multiply(a0, 3)) xor (a1) xor (a2) xor (multiply(a3, 2));

		vector<vector<int>> cust = {
			{2,3,1,1},
			{1,2,3,1},
			{1,1,2,3},
			{3,1,1,2}
		};

		/*
		stateArray[0][i] %= 255;
		stateArray[1][i] %= 255;
		stateArray[2][i] %= 255;
		stateArray[3][i] %= 255;
		*/
	}
	cout << "Mix Column\n";
	prar(stateArray);


	auto xx = keyExpansion(keyMatrix);


	vector<vector<int>> roundKey = {
		{ 0xe2, 0x91, 0xb1, 0xd6 },
		{ 0x32, 0x12, 0x59, 0x79 },
		{ 0xfc, 0x91, 0xe4, 0xa2 },
		{ 0xf1, 0x88, 0xe6, 0x93 }
	};



	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stateArray[i][j] = stateArray[i][j] xor roundKey[i][j];
		}
	}

	cout << "XOR With R1 Key\n";
	prar(stateArray);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
	}
}