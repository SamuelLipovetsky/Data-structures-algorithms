#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999

vector<int> all;
void kmp(string needle, string haystack)
{
    vector<int> all;
    //helper
    int m = needle.size();
    int t = haystack.size();
    int i = 0, j = 1;

    vector<int> helper;
    helper.resize(m);
    while (j < m)
    {
        if (needle[i] == needle[j])
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

    //search
    i = 0;
    j = 0;
    while (i < t)
    {

        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            all.push_back(i - m);
            j = helper[j - 1];
        }
        if (i < t && haystack[i] != needle[j])
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
    if (all.size() > 0)
    {
        for (auto i : all)
        {
            cout << i << endl;
        }
    }
    else
    {
        cout << endl;
    }
}

int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    int control = 0;
    while (1)
    {
        cin >> n;
        string needle;
        string haystack;
        cin.ignore();
        getline(cin, needle);
        getline(cin, haystack);
        kmp(needle, haystack);

        if (!cin)
            break;
    }
}