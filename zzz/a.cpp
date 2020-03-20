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
    for (int i = 0; i < x; i++)
    {
        control = 0;
        int biggest = 0;
        cin >> y;

        for (int j = 0; j < y; j++)
        {

            cin >> temp;
            if (temp > biggest)
            {
                biggest = temp;
            }
            arr[j] = temp;
        }
        for (int k = 0; k < y; k++)
        {

            if ((biggest - arr[k]) % 2 == 1)
            {
                control = 1;
                break;
            }
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
