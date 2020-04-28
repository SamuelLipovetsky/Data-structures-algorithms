#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
long long int dp[(1 << 20)];
int arr[20][20];
int main()
{
    int n, tamanho, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tamanho;
        for (int k = 0; k < tamanho; k++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                cin >> arr[k][j];
            }
        }
    }

    return 0;
}