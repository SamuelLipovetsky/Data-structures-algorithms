#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define infinito 9999999

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << 1 << " " << 100 << endl;
    cout << 1000 << endl;
    for (int i = 0; i < 1000; i++)
    {
        int k = rand() % 10000;
        cout << k << " " << rand() % 10000 + k << endl;
    }
}
