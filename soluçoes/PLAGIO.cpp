#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
int suf[10100];
vector<string> musica;
vector<string> trecho;
vector<int> intervalos_m;
vector<int> intervalos_t;
//https://br.spoj.com/problems/PLAGIO/
char kmp()
{
    int m = intervalos_m.size();
    int t = intervalos_t.size();
    int i = 0, j = 1;
    suf[0] = 0;
    while (j < t)
    {
        if (intervalos_t[i] == intervalos_t[j])
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
    i = 0;
    j = 0;

    while (i < m)
    {
        if (intervalos_m[i] == intervalos_t[j])
        {
            i++;
            j++;
        }
        if (j == t)
        {

            return 'S';
        }
        else if (i < m && intervalos_t[j] != intervalos_m[i])
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

    return 'N';
}

int main(int argc, const char **argv)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m = 0, t = 0;
    unordered_map<string, int> val;

    val["Ab"] = 0;
    val["A"] = 1;
    val["A#"] = 2;

    val["Bb"] = 2;
    val["B"] = 3;
    val["B#"] = 4;

    val["Cb"] = 3;
    val["C"] = 4;
    val["C#"] = 5;

    val["Db"] = 5;
    val["D"] = 6;
    val["D#"] = 7;

    val["Eb"] = 7;
    val["E"] = 8;
    val["E#"] = 9;

    val["Fb"] = 8;
    val["F"] = 9;
    val["F#"] = 10;

    val["Gb"] = 10;
    val["G"] = 11;
    val["G#"] = 0;

    while (1)
    {
        string temp;
        cin >> m >> t;
        if (m == 0 && t == 0)
        {
            break;
        }

        musica.resize(m);
        trecho.resize(t);
        intervalos_t.resize(t - 1);
        intervalos_m.resize(m - 1);
        for (int i = 0; i < m; i++)
        {
            cin >> musica[i];
        }
        for (int i = 0; i < t; i++)
        {
            cin >> trecho[i];
        }

        for (int i = 0; i < m - 1; i++)
        {
            intervalos_m[i] = (val[musica[i]] - val[musica[i + 1]]);
            if (intervalos_m[i] < 0)
            {
                intervalos_m[i] += 12;
            }
        }
        for (int i = 0; i < t - 1; i++)

        {
            intervalos_t[i] = (val[trecho[i]] - val[trecho[i + 1]]);
            if (intervalos_t[i] < 0)
            {
                intervalos_t[i] += 12;
            }
        }
        cout << kmp() << endl;
    }
    return 0;
}