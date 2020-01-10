#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{

    int n, m;
    int a, b, c;
    //n =numero de pessoas
    //m = pares possiveis
    cin >> n;
    cin >> m;

    int arr[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;

        arr[a - 1][b - 1] = c;
        arr[b - 1][a - 1] = c;
    }
    int sum = 0;
    int temp = 0;
    int ar[3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k && j != k)
                {
                    temp = arr[i][k] + arr[j][k] + arr[i][j];
                    if (temp > sum)
                    {
                        ar[0] = i + 1;
                        ar[1] = k + 1;
                        ar[2] = j + 1;
                        sum = temp;
                    }
                }
            }
        }
    }
    cout << ar[0] << " " << ar[1] << " " << ar[2];
    return 0;
}
