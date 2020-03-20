#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, temp;

    cin >> x;
    int count = 0;
    int control = 0;
    int biggest = 0;
    int arr[100] = {};
    //at least 3;
    int adj[5000][5000] = {};
    for (int i = 0; i < 5000; i++)
    {
        adj[i][i] = 1;
    }

    for (int i = 0; i < x; i++)
    {
        //1 2 ,2 3, 3 4 ,4 5
        //1 3,2 4,
        cin >> y;

        for (int j = 0; j < y; j++)
        {
            cin >> arr[j];
        }
        for (int k = 0; k < y; k++)
        {
                }

        if (control == 1)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n";
        }
    }
}
