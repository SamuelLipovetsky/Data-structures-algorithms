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
vector<vector<int>> table;

char lcs(vector<int> b, vector<int> a)
{
    int co = 0;
    for (int i = 0; i < b.size(); i++)
    {
        cout << a[i] << " " << b[co] << endl;

        if (co == b.size())
            return 'S';
        if (a[i] == b[co])
        {
            co++;
        }
        else
        {
            co = 0;
        }
    }
    return 'N';
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, t;
    map<string, int> val;
    val["C"] = 0;
    val["B#"] = 0;
    val["C#"] = 1;
    val["Db"] = 1;
    val["D"] = 2;
    val["D#"] = 3;
    val["Eb"] = 3;
    val["E"] = 4;
    val["Fb"] = 4;
    val["F"] = 5;
    val["E#"] = 5;
    val["F#"] = 6;
    val["Gb"] = 6;
    val["G"] = 7;
    val["G#"] = 8;
    val["Ab"] = 8;
    val["A"] = 9;
    val["A#"] = 10;
    val["Bb"] = 10;
    val["B"] = 11;
    val["Cb"] = 11;

    string temp;
    vector<string> v;
    cin >> m >> t;
    cin.ignore();
    getline(cin, temp);

    for (int i = 0; i < temp.size(); i++)
    {
        string a, b;
        if (i == '#' || i == 'b' || i == ' ')
            continue;
        if (i + 1 < temp.size())
        {

            if (temp[i + 1] == '#' || temp[i + 1] == 'b')
            {
                a = temp[i];
                a += temp[i + 1];
                i += 1;
                if (a != " ")

                    v.push_back(a);
            }
            else
            {
                a = temp[i];
                if (a != " ")

                    v.push_back(a);
            }
        }
        else
        {
            if (temp[i + 1] != '#' || temp[i + 1] != 'b')
            {
                a = temp[i];
                if (a != " ")

                    v.push_back(a);
            }
        }
    }
    // int intervalos[m - 1];
    vector<int> intervalos;
    intervalos.resize(m - 1);
    for (int i = 0; i < m; i++)
    {
        if (i + 1 < m)
        {

            intervalos[i] = val[v[i + 1]] - val[v[i]];
        }
    }
    // for (int i = 0; i < m - 1; i++)
    // {
    //     cout << intervalos[i] << " ";
    // }
    vector<string> v2;

    string tempt;
    getline(cin, tempt);

    for (int i = 0; i < tempt.size(); i++)
    {
        string a, b;
        if (i == '#' || i == 'b' || i == ' ')
            continue;
        if (i + 1 < tempt.size())
        {

            if (tempt[i + 1] == '#' || tempt[i + 1] == 'b')
            {
                a = tempt[i];
                a += tempt[i + 1];
                i += 1;
                if (a != " ")

                    v2.push_back(a);
            }
            else
            {
                a = tempt[i];
                if (a != " ")

                    v2.push_back(a);
            }
        }
        else
        {
            if (tempt[i + 1] != '#' || tempt[i + 1] != 'b')
            {
                a = tempt[i];
                if (a != " ")

                    v2.push_back(a);
            }
        }
    }
    vector<int> intervalost;
    intervalost.resize(m - 1);
    for (int i = 0; i < t; i++)
    {
        if (i + 1 < t)
        {
            intervalost[i] = val[v2[i + 1]] - val[v2[i]];
        }
    }
    cout << lcs(intervalost, intervalos);
}
