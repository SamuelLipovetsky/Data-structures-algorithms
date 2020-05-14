#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <set>
#include <time.h>
using namespace std;

pair<int, int> cartas[2000] = {};
int soma1 = 0;
int dp[2002][2002] = {};
int teste = 1;
int control = 0;

int knap(int peso[], int valor[], int tamanho, int soma)
{
    int dp[tamanho + 1][soma + 1] = {};
    for (int i = 0; i <= tamanho; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= soma; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= tamanho; i++)
    {
        for (int j = 1; j <= soma; j++)
        {
            if (peso[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], valor[i - 1] + dp[i - 1][j - peso[i - 1]]);
            }
        }
    }
    for (int i = 0; i <= tamanho; i++)
    {
        for (int j = 0; j <= soma; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, const char *argv[])
{
    int peso[] = {1, 2, 4, 3};
    int val[] = {3, 2, 1, 2};
    knap(peso, val, 4, 7);
}
