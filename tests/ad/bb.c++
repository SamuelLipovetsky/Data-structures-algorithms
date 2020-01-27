#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int total = 0;
        vector<int> lista;
        lista.push_back(arr[0]);
        lista.push_back(arr[1]);
        if (arr[0] > arr[1])
        {
            total++;
        }
        sort(lista.begin(), lista.end());
        for (int i = 2; i < n; i++)
        {

            vector<int>::iterator it;
            it = lista.end();
            int j = i;
            if (arr[i] > (*it))
            {
                lista.push_back(arr[i]);
            }
            else
            {

                cout << total << endl;
                vector<int>::iterator it;
                it = lista.end();
                while (arr[i] < (*it) && j != 0)
                {
                    it--;
                    total++;
                    j--;
                }
                total--;
                cout << total << endl;
                lista.push_back(arr[i]);
            }

            sort(lista.begin(), lista.end());
        }

        if (total % 2 == 0)
        {
            cout << "Carlos" << endl;
        }

        else
        {

            cout << "Marcelo" << endl;
        }
    }
}