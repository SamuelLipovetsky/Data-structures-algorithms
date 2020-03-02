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

int tamanho;
int find(int index, int tam)
{

    auto c = lower_bound(ini.begin(), ini.end(), fim[index]);
    if (c != ini.end())
    {
        return find(c - ini.begin(), tam + 1);
    }
    else
    {
        return tam;
    }
}

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    int a, b;
    int small = 1000000;
    int ind = 0;
    cin >> tamanho;
    for (int j = 0; j < n; j++)
    {
        ini.clear();
        fim.clear();
        for (int i = 0; i < tamanho; i++)
        {
            cin >> a;
            cin >> b;
            ini.push_back(a);
            fim.push_back(b);
            if (b < small)
            {
                small = b;
                ind = i;
            }
        }
        int p = find(ind, 1);
        cout << p << endl;

        cin >> tamanho;
    }
    return 0;
}
