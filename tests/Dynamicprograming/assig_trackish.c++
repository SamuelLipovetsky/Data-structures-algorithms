#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
//to do
using namespace std;
int total = 0;
//k= linha
//j=coluna
array<set<int>, 20> arr;
int problem(set<int> usados, int k, int n)
{
    if (k < n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (arr[k + 1].count(i) == 1 && usados.count(i) == 0)
            {
                usados.insert(i);
                problem(usados, k + 1, n);
                usados.erase(i);
            }
        }
    }
    if (usados.size() == n)
    {
        total += 1;
    }
    return 0;
}
int main()
{
    int n, tamanho, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tamanho;
        for (int k = 0; k < tamanho; k++)
        {
            arr[k].clear();
            for (int j = 0; j < tamanho; j++)
            {
                cin >> temp;
                if (temp)
                {
                    arr[k].insert(j + 1);
                }
            }
        }
        total = 0;
        set<int> t;
        for (auto x : arr[0])
        {

            t.insert(x);
            problem(t, 0, tamanho);
            t.erase(x);
        }
        cout << total << endl;
    }
    return 0;
}