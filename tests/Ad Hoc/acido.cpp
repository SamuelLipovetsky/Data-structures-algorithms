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
bool compativel(char a, char b)
{
    if (a == 'B' && b == 'S')
        return true;
    if (a == 'C' && b == 'F')
        return true;
    if (a == 'S' && b == 'B')
        return true;
    if (a == 'F' && b == 'C')
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string all;
    vector<pair<char, int>> letras;
    while (getline(cin, all))
    {
        if (!cin)
        {
            break;
        }
        stack<int> pilha;
        int count = 0;
        pilha.emplace(all[0]);
        if (all.size() < 2)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 1; i < all.size(); i++)
            {
                if (pilha.empty())
                {
                    pilha.emplace(all[i]);
                }
                else if (!compativel(all[i], pilha.top()))
                {
                    pilha.emplace(all[i]);
                }
                else
                {
                    pilha.pop();
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}