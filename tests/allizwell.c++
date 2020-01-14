#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <set>
using namespace std;

char arr[103][103];
char nome[12] = "ALLIZZWELL";
int control = 0;
int resolve(array<int, 2> atual, int target, set<array<int, 2>> usados)
{

    int l = atual[0];
    int c = atual[1];
    set<array<int, 2>> u = usados;
    if (target == 10)
    {
        control = 1;
    }
    if (arr[l - 1][c] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l - 1, c};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l + 1][c] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l + 1, c};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l][c - 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l, c - 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l][c + 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l, c + 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l + 1][c + 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l + 1, c + 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l + 1][c - 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l + 1, c - 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l - 1][c - 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l - 1, c - 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }
    u = usados;
    if (arr[l - 1][c + 1] == nome[target] && control == 0)
    {
        array<int, 2> temp = {l - 1, c + 1};
        if (u.count(temp) == 0)
        {
            u.insert(temp);
            resolve(temp, target + 1, u);
        }
    }

    return 0;
}
int main()
{

    int x, y, n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> x;
        cin >> y;

        vector<array<int, 2>> a;
        int size = 0;

        for (int j = 0; j <= x + 1; j++)
        {
            for (int k = 0; k <= y + 1; k++)
            {
                if (j > 0 && k > 0 && j <= x && k <= y)

                {
                    cin >> arr[j][k];
                    if (arr[j][k] == 'A')
                    {
                        array<int, 2> t = {j, k};
                        a.push_back(t);

                        size++;
                    }
                }
                else
                {
                    arr[j][k] = 'O';
                }
            }
        }

        for (int l = 0; l < size; l++)
        {
            set<array<int, 2>> usados;
            array<int, 2> temp = {a[l][0], a[l][1]};
            usados.insert(temp);
            resolve(temp, 1, usados);
        }
        if (!control)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            control = 0;
        }
    }
}
