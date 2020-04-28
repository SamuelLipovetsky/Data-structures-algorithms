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

long long a_mask[60];
long long q_mask[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // vector<string> q;
    // vector<string> a;
    // q.resize(n);
    // a.resize(m);
    long long mo = (1 << m - 1);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        long long mask = 0;
        int j = 0;
        int index = 0;
        int control = 1;
        while (j < n)
        {

            if (j == 0)
            {
                string sub = temp.substr(0, n - 1);
                while (j < m)
                {

                    if (sub[j] == '|')
                    {
                        mask = mask | (1 << (j));
                    }
                    j++;
                }
                q_mask[i][0] = mask;
                index++;
            }

            else
            {
                mask = mask >> 1;
                // cout << mask << " ";
                if (temp[j] == '|')
                {

                    mask |= (1 << control);
                }
                // cout << mask << endl;
                q_mask[i][index] = mask;
                index++;
                j++;
                control += 1;
                control %= m;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        a_mask[i] = 0;
        //a_mask[i] representa uma mascara em que cada "|" é um bit setado no index j da string da coluna i da assinatura
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '|')
            {

                a_mask[i] = a_mask[i] | (1 << j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            cout << q_mask[i][j] << " ";
        }
        cout << endl;
    }
}