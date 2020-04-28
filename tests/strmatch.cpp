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
string s;
string p;
void kmp()
{

    int tamanho = p.size();
    int helper[tamanho];
    helper[0] = 0;
    int i = 0;
    int j = 1;
    while (j < tamanho)
    {
        //match
        if (p[i] == p[j])
        {
            helper[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = helper[i - 1];
            }
            else
            {
                helper[j] = 0;
                j++;
            }
        }
    }
    i = 0;
    j = 0;
    int count = 0;
    while (i < s.size())
    {

        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == tamanho)
        {
            count++;
            j = helper[j - 1];
        }
        else if (i < s.size() && s[i] != p[j])
        {
            if (j != 0)
            {
                j = helper[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    cin.ignore();
    cin >> s;
    // getline(cin, s);
    for (int i = 0; i < q; i++)
    {
        // getline(cin, p);
        cin >> p;
        kmp();
    }
}
