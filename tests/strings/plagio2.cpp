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
int suf[10100];
char kmp(vector<int> trecho, vector<int> musica, int maior, int menor)
{
    int m = musica.size();
    int t = trecho.size();

    int i = 0, j = 1;
    suf[0] = 0;

    while (j < t)
    {
        if (trecho[i] == trecho[j])
        {
            suf[j] = i + 1;

            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = suf[i - 1];
            }
            else
            {
                suf[j] = 0;

                j++;
            }
        }
    }

    int pra_cima = 11 - maior;
    int pra_baixo = menor;
    for (int l = 0; l <= pra_baixo; l++)
    {
        i = 0;
        j = 0;

        while (i < m)
        {
            if (musica[i] == trecho[j] - l)
            {
                i++;
                j++;
            }
            if (j == t)
            {

                return 'S';
            }
            else if (i < m && trecho[j] - l != musica[i])
            {
                if (j != 0)
                {
                    j = suf[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }

    for (int l = 0; l <= pra_cima; l++)
    {
        i = 0;
        j = 0;

        while (i < m)
        {

            if (musica[i] == trecho[j] + l)
            {
                i++;
                j++;
            }
            if (j == t)
            {

                return 'S';
            }
            else if (i < m && trecho[j] + l != musica[i])
            {
                if (j != 0)
                {
                    j = suf[j - 1];
                }
                else
                {
                    i++;
                }
            }
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
    while (1)
    {

        string temp;
        vector<string> v;
        cin >> m >> t;
        if (m == 0 && t == 0)
            break;
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
        intervalos.resize(m);
        for (int i = 0; i < m; i++)
        {

            intervalos[i] = val[v[i]];
        }

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
        intervalost.resize(t);
        int maio = 0, meno = infinito;
        for (int i = 0; i < t; i++)
        {

            intervalost[i] = val[v2[i]];
            if (intervalost[i] > maio)
            {
                maio = intervalost[i];
            }
            if (intervalost[i] < meno)
            {
                meno = intervalost[i];
            }
        }
        int control = 0;
        if (t == 1)
        {

            cout << "S" << endl;
        }
        else
            cout << kmp(intervalost, intervalos, maio, meno) << endl;
    }
}
