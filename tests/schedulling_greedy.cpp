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

int tamanho;
bool sec(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}
int main(int argc, const char *argv[])
{

    cin >> tamanho;
    int a, b;
    int small = 1000000;
    int ind = 0;
    vector<pair<int, int>> pares;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> a;
        cin >> b;
        pares.push_back(make_pair(a, b));
    }
    sort(pares.begin(), pares.end(), sec);

    int p = 0;
    int prev_finish = -1000000;

    for (auto x : pares)
    {
        if (x.first >= prev_finish)
        {

            p++;
            prev_finish = x.second;
        }
    }

    cout << p;
    return 0;
}
