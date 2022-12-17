#include<iostream>
using namespace std;

string xor1(string a, string b)
{

    string result = "";

    int n = b.length();

    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string calcRem(string divident, string divisor)
{

    int i = divisor.length();

    string tmp = divident.substr(0, i);

    int n = divident.length();

    while (i < n)
    {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp) + divident[i];
        else {
            string k = "";
            for(int j=0;j<)
            tmp = xor1(std::string(i, '0'), tmp) +
                divident[i];
        }
        i += 1;
    }

}

void encodeData(string data, string divisor)
{
    int key_len = divisor.length();

    string divident = data;

    for (int i = 0; i < key_len - 1; i++) divident += '0';
   
    string remainder = calcRem(divident, divisor);

    string codeword = data + remainder;
    cout << "Remainder : "
        << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :"
        << codeword << "\n";
}

int main()
{
    string data = "100100";
    string divisor = "1101";

    encodeData(data, divisor);

    return 0;
}