#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ini;
vector<int> fim;

int dp[10000] = {0};
int tamanho;
int p = 0;
int to_ret = 0;
int m(int d)
{
    if (d > to_ret)
    {
        to_ret = d;
    }
}
int find(int i, int count, vector<int> usados)
{
    if (p < ini.size())
    {
        vector<int>::iterator x = lower_bound(ini.begin(), ini.end(), fim[i]);
        if (dp[i] == 0)
        {
            if (i < ini.size())
            {
                usados.push_back(i);
                find(x - ini.begin(), count + 1, usados);
            }
            else
            {
                int d = count;
                for (auto x : usados)
                {
                    d--;
                    m(d);
                    dp[x] = d;
                }
                usados.clear();
                p++;
                find(p, 1, usados);
            }
        }
        else
        {
            int d = dp[i];

            for (int x = usados.size() - 1; x >= 0; x--)
            {
                d++;
                dp[usados[x]] = d;
                m(d);
            }
            usados.clear();
            p++;
            find(p, 1, usados);
        }
    }
}

int main(int argc, const char *argv[])
{

    cin >> tamanho;
    int a, b;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> a;
        cin >> b;
        ini.push_back(a);
        fim.push_back(b);
    }
    vector<int> usados;

    find(0, 1, usados);

    cout << to_ret;
}
