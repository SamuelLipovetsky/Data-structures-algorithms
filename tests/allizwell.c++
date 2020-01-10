#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    int n_testes;
    int x, y, n;
    char control;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> y;
        char arr[x][y] = {0};
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++)
            {
                cin >> arr[j][k];
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
        int adj[x * y y][x * y];
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < 0 y; k++)
            {
                for (int c = min(0, ))
            }
        }
    }
    return 0;
}
