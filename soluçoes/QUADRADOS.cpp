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

unsigned long long a_mask[61];
unsigned long long q_mask[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int inst = 1;
    unsigned long long um = 1;
    while (1)
    {

        int n, m;
        cin >> n >> m;
        if (!cin)
        {
            break;
        }
        unsigned long long mo = (um << m - 1);
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            unsigned long long mask = 0;
            int j = 0;
            int index = 0;

            while (j < n)
            {
                if (j == 0)
                {
                    string sub = temp.substr(0, n);
                    while (j < m)
                    {
                        if (sub[j] == '|')
                        {
                            mask = mask | (um << (j));
                        }
                        j++;
                    }
                    q_mask[0][i] = mask;
                    index++;
                }
                else
                {
                    mask = mask >> 1;

                    if (temp[j] == '|')
                    {
                        mask |= (um << (m - 1));
                    }
                    q_mask[index][i] = mask;
                    index++;
                    j++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            string temp;
            cin >> temp;
            a_mask[i] = 0;
            //a_mask[i] representa uma mascara em que cada "|" Ã© um bit setado no index j da string da coluna i da assinatura
            for (int j = 0; j < m; j++)
            {
                if (temp[j] == '|')
                {

                    a_mask[i] = a_mask[i] | (um << j);
                }
            }
        }
        cout << "Instancia " << inst << endl;
        vector<pair<int, int>> pares;
        int flag = 0;
        for (int j = 0; j <= n - m; j++)
        {
            for (int i = 0; i < n; i++)
            {

                int count = 0;
                for (int k = 0; k < m; k++)
                {

                    if (i + k < n)
                    {
                        if (q_mask[j][i + k] == a_mask[k])
                        {
                            count++;
                            if (count == m)
                            {
                                flag = 1;
                                cout << i << " " << j << endl;
                            }
                        }
                        else
                        {
                            count = 0;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (!flag)
        {
            cout << "nenhuma ocorrencia" << endl;
        }
        cout << endl;
        inst++;
    }
}