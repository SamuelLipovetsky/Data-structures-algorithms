#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    while (true)
    {
        cin >> n >> p;
        if (n == 0 && p == 0)
        {
            break;
        }

        vector<char> cont;
        cont.push_back('P');
        cont.push_back('o');
        cont.push_back('o');
        cont.push_back('d');
        cont.push_back('l');
        cont.push_back('e');
        int control = 1;
        if (n % p == 0)
        {
            control = 0;
        }
        while (cont.size() < floor((n / p) + control) && cont.size() < 20)
        {
            cont.insert(cont.begin() + 1, 'o');
        }
        for (auto i : cont)
        {
            cout << i;
        }

        cout << endl;
    }
}
