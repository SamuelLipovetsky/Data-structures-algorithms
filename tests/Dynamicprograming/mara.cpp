#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <string>
#include <math.h>
#include <set>
using namespace std;

int main()
{
    int n, qm, temp, small;
    cin >> n;
    while (n)
    {
        int arr[n + 1] = {};
        for (int i = 0; i < n + 1; i++)
        {
            arr[i] = INT16_MAX;
        }

        arr[0] = 0;
        cin >> qm;
        set<int> moedas;
        for (int i = 0; i < qm; i++)
        {
            cin >> temp;
            moedas.insert(temp);
        }

        for (int i = 1; i <= n; i++)
        {
            for (auto x : moedas)
            {
                if (x <= i)
                {
                    int sub = arr[i - x];

                    if (sub != INT16_MAX && sub + 1 < arr[i])
                    {
                        arr[i] = sub + 1;
                    }
                }
            }
        }

        if (arr[n] != INT16_MAX)
        {
            cout << arr[n] << endl;
        }
        else
        {
            cout << "Impossivel" << endl;
        }
        cin >> n;
    }
}
