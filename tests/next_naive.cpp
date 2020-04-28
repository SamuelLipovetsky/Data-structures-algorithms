#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999

bool pali(string a)
{
    if (a.size() == 1)
        return true;
    int i = 0;
    int j = a.size() - 1;
    if (a[i] != a[j])
    {
        return false;
    }
    if (a.size() == 2)
    {
        if (a[i] == a[j])
        {
            return true;
        }
        return false;
    }
    if (a.size() % 2 == 0)
    {
        while (a[i] == a[j])
        {
            i++;
            j--;
            if (i == j - 1 && a[i] == a[j])
                return true;
        }
        return false;
    }
    else
    {
        while (a[i] == a[j])
        {
            i++;
            j--;
            if (i == j && a[i] == a[j])
                return true;
        }
        return false;
    }
}
int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<string> strings;
    vector<int> ints;
    cin >> n;
    strings.resize(n);
    ints.resize(n);
    int biggest = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp > biggest)
            biggest = temp;
        strings[i] = to_string(temp);
        ints[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        int i_atual = ints[i];
        // int s_atual = strings[i];
        int prox = i_atual + 1;
        while (1)
        {

            if (pali(to_string(prox)))
            {
                cout << prox << endl;
                break;
            }
            else
            {
                prox++;
            }
        }
    }
}