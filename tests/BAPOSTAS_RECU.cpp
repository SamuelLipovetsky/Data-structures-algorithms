#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
using namespace std;
//k
int m = 0;
int dp[10000] = {};
int d[10000][10000] = {};
int naive(int a, int b)
{
    int t = 0;
    if (d[a][b] == -1)
    {
        for (int i = a; i <= b; i++)
        {
            t += dp[i];
        }
        if (t > m)
        {
            m = t;
        }
        d[a][b] = t;
    }
    else
    {
    }
}
int main(int argc, const char *argv[])
{
    int tamanho;
    cin >> tamanho;
    while (tamanho)
    {
        for (int i = 0; i < tamanho; i++)
        {
            cin >> dp[i];
        }
        m = 0;

        naive(0, tamanho - 1);

        cout << m << endl;
        cin >> tamanho;
    }
}
