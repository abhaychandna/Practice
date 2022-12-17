#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz0123456789";
int main()
{
    string s;
    cout << "Enter the string to be encoded: ";
    cin >> s;
    int t = 0, i = 0, j = 0, flag = 0, counter = 0, q = 0;
    char mat[6][6];
    string infer_name = "play";
    int len = infer_name.length();
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (flag < len)
            {
                mat[i][j] = infer_name[t];
            }
            flag++;
            t++;
        }
    }
    char req[36];
    for (i = 0; i < 36; i++)
    {
        counter = 0;
        for (j = 0; j < len; j++)
        {
            if (alpha[i] == infer_name[j])
            {
                counter = 1;
            }
        }
        if (counter == 0)
        {
            req[q++] = alpha[i];
        }
    }

    int len1 = strlen(req);
    flag = 0;
    t = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (flag >= len)
            {
                mat[i][j] = req[t++];

            }
            flag++;
        }
    }
    cout << "The matrix for encryption is:\n";
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    t = 0;
    int len_s = s.length();
    char enc_sec[(len_s / 2)][2];
    for (i = 0; i < len_s; i++)
    {
        if (s[i] == s[i + 1] || (s[i + 1] == '\0' && s[i] == s[i + 1]))
        {
            enc_sec[t][0] = s[i];
            enc_sec[t][1] = 'x';
            t++;

        }
        else
        {
            enc_sec[t][0] = s[i];
            enc_sec[t][1] = s[i + 1];
            t++;
            i++;
        }
    }
    if (strlen(enc_sec[t - 1]) == 1)
    {
        enc_sec[t - 1][1] = 'x';
    }
    cout << endl;
    cout << "Pairing of words are:\n";
    for (i = 0; i < t; i++)
    {
        cout << enc_sec[i][0] << "" << enc_sec[i][1] << " ";
    }
    cout << endl << endl;
    int curr_i1 = 10, curr_j1 = 10, curr_i2 = 10, curr_j2 = 10;
    char encrypted_string[t][2];
    int index = 0, k = 0, col_cond = 0, row_cond = 0;
    for (k = 0; k < t; k++)
    {
        col_cond = 0;
        row_cond = 0;
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (mat[i][j] == enc_sec[k][0])
                {
                    curr_i1 = i;
                    curr_j1 = j;
                    col_cond = 1;
                }
                if (mat[i][j] == enc_sec[k][1])
                {
                    curr_i2 = i;
                    curr_j2 = j;
                    row_cond = 1;
                }
                if (row_cond == 1 && col_cond == 1)
                {
                    if (curr_i1 == curr_i2 && (curr_i1 != 10 && curr_i2 != 10))
                    {
                        encrypted_string[index][0] = mat[curr_i1][(curr_j1 + 1) % 6];
                        encrypted_string[index++][1] = mat[curr_i2][(curr_j2 + 1) % 6];
                        break;
                    }
                    if (curr_j1 == curr_j2 && (curr_j1 != 10 && curr_i2 != 10))
                    {
                        if (curr_i1 == 0)
                        {
                            curr_i1 = 6;
                        }
                        if (curr_i2 == 0)
                        {
                            curr_i2 = 6;
                        }
                        encrypted_string[index][0] = mat[(curr_i1 - 1) % 6][curr_j1];
                        encrypted_string[index++][1] = mat[(curr_i2 - 1) % 6][curr_j2];
                        break;
                    }
                    if (curr_i1 != curr_i2 && curr_j2 != curr_j1)
                    {
                        encrypted_string[index][0] = mat[curr_i1][curr_j2];
                        encrypted_string[index++][1] = mat[curr_i2][curr_j1];
                        break;
                    }
                }
            }
            if (row_cond == 1 && col_cond == 1)
            {
                break;
            }
        }
    }
    cout << "The encrypted pairs are: \n";
    for (i = 0; i < index; i++)
    {
        cout << encrypted_string[i][0] << "" << encrypted_string[i][1] << " ";

    }
    cout << endl << endl;
    char decrypted_string[t][2];
    index = 0;
    for (k = 0; k < t; k++)
    {
        col_cond = 0;
        row_cond = 0;
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (mat[i][j] == encrypted_string[k][0])
                {
                    curr_i1 = i;
                    curr_j1 = j;
                    col_cond = 1;
                }
                if (mat[i][j] == encrypted_string[k][1])
                {
                    curr_i2 = i;
                    curr_j2 = j;
                    row_cond = 1;
                }                if (row_cond == 1 && col_cond == 1)
                {
                    if (curr_i1 == curr_i2 && (curr_i1 != 10 && curr_i2 != 10))
                    {
                        if (curr_j1 == 0)
                        {
                            curr_j1 = 6;
                        }
                        if (curr_j2 == 0)
                        {
                            curr_j2 = 6;
                        }
                        decrypted_string[index][0] = mat[curr_i1][(curr_j1 - 1) % 6];
                        decrypted_string[index++][1] = mat[curr_i2][(curr_j2 - 1) % 6];
                        break;
                    }
                    if (curr_j1 == curr_j2 && (curr_j1 != 10 && curr_i2 != 10))
                    {
                        decrypted_string[index][0] = mat[(curr_i1 + 1) % 6][curr_j1];
                        decrypted_string[index++][1] = mat[(curr_i2 + 1) % 6][curr_j2];
                        break;
                    }
                    if (curr_i1 != curr_i2 && curr_j2 != curr_j1)
                    {
                        decrypted_string[index][0] = mat[curr_i1][curr_j2];
                        decrypted_string[index++][1] = mat[curr_i2][curr_j1];
                        break;
                    }
                }
            }
            if (row_cond == 1 && col_cond == 1)
            {
                break;
            }
        }
    }
    cout << "The decrypted pairs are: \n";
    for (i = 0; i < index; i++)
    {
        cout << decrypted_string[i][0] << "" << decrypted_string[i][1] << " ";

    }
    cout << endl << endl;
    t = 0;
    char final_result[index * 2];
    for (i = 0; i < index; i++)
    {
        final_result[t++] = decrypted_string[i][0];
        final_result[t++] = decrypted_string[i][1];
    }

    cout << "After decryption: ";
    for (i = 0; i < t; i++)
    {
        if (i % 2 == 1 && final_result[i] == 'x')
        {
            continue;
        }
        else
        {
            cout << final_result[i];
        }
    }
    cout << endl;
    return 0;
}