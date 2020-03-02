#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int tamanho;
    cin >> tamanho;
    char s1[tamanho];
    char s2[tamanho];
    char temp;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> temp;
        s1[i] = temp;
        s2[tamanho - i - 1] = temp;
    }

    int lcs[tamanho + 1][tamanho + 1] = {};
    for (int i = 0; i <= tamanho; i++)
    {
        lcs[i][0] = 0;
        lcs[0][i] = 0;
    }
    for (int i = 1; i <= tamanho; i++)
    {
        for (int j = 1; j <= tamanho; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    int max = lcs[tamanho][tamanho];

    cout << tamanho - max << endl;
}