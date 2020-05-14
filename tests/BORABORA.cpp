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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, m, n;
    vector<pair<int, int>> cartas;
    cin >> p >> m >> n;
    cartas.resize(n);
    int a;
    char b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cartas[i] = make_pair(a, (int)b);
    }
    vector<priority_queue<pair<int, int>>> jogadores;
    jogadores.resize(p);
    for (int i = 0; i < p; i++)
    {
        int base = i * m;
        for (int k = 0; k < m; k++)
        {
            jogadores[i].emplace(cartas[base + k]);
        }
    }
    int topo = p * m + 1;
}