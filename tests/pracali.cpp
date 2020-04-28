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
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
typedef pair<int, char> par;
typedef vector<par> struc;
int convert(char arr[9])
{
    int total = 0;
    //horas para segundos
    total += (arr[0] - '0') * 600 * 60 + (arr[1] - '0') * 60 * 60;
    //minutos para segundos
    total += (arr[3] - '0') * 10 * 60 + (arr[4] - '0') * 60;
    //segundos
    total += (arr[6] - '0') * 10 + (arr[7] - '0');
    return total;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struc g;
    char t[9];
    char temp;
    int n;
    while (true)
    {

        cin >> n;
        if (n == 0)
        {
            break;
        }
        g.clear();
        g.resize(n);
        int e_count = 1, xcount = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                cin >> temp;
                t[j] = temp;
            }
            cin >> temp;
            if (temp == 'E' && i != 0)
                e_count++;
            g[i].second = temp;
            g[i].first = convert(t);
        }

        sort(g.begin(), g.end());
        g[0].second = 'E';
        g[n - 1].second = 'X';
        int score = 0, int e_colocados = 0, int m = 0;

        for (int i = 0; i < n; i++)
        {
            if (g[i] == 'E')
            {
                score++;
                e_colocados++;
                e_count--;
            }
            if (g[i] == 'X')
            {
                score--;
            }
            else
            {
                if (score == 0)
                {
                    score++;
                    e_count++
                }
                else if (e + numE < n / 2)
            }
        }

        cout << ml << endl;
    }
}