#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
//OBS * : MUITO JUMENTO
bool got_it(float a, float b, float hip)
{

    float aa = a * a;
    float bb = b * b;
    float hipp = hip * hip;
    if (abs(aa + bb) > hipp - 0.16 && abs(aa + bb) < hipp + 0.16)
    {
        if (a != 0 && b != 0 and hip != 0)
        {

            return true;
        }
    }

    return false;
}
int main()
{
    array<int, 6> arr;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    float a = sqrt(pow((arr[0] - arr[2]), 2) + pow((arr[1] - arr[3]), 2));
    float b = sqrt(pow((arr[0] - arr[4]), 2) + pow((arr[1] - arr[5]), 2));
    float c = sqrt(pow((arr[2] - arr[4]), 2) + pow((arr[3] - arr[5]), 2));

    array<float, 3> cord = {a, b, c};
    sort(begin(cord), end(cord));

    if (got_it(cord[0], cord[1], cord[2]))
    {
        cout << "RIGHT";
        return 0;
    }
    else
    {

        for (int i = 0; i < 6; i++)
        {
            array<float, 3> l;
            array<int, 6> temp = arr;
            temp[i] += 1;
            a = sqrt(pow((temp[0] - temp[2]), 2) + pow((temp[1] - temp[3]), 2));
            b = sqrt(pow((temp[0] - temp[4]), 2) + pow((temp[1] - temp[5]), 2));
            c = sqrt(pow((temp[2] - temp[4]), 2) + pow((temp[3] - temp[5]), 2));
            l = {a, b, c};
            sort(begin(l), end(l));
            if (got_it(l[0], l[1], l[2]))
            {
                cout << "ALMOST";
                return 0;
            }
            temp[i] -= 2;
            a = sqrt(pow((temp[0] - temp[2]), 2) + pow((temp[1] - temp[3]), 2));
            b = sqrt(pow((temp[0] - temp[4]), 2) + pow((temp[1] - temp[5]), 2));
            c = sqrt(pow((temp[2] - temp[4]), 2) + pow((temp[3] - temp[5]), 2));
            l = {a, b, c};
            sort(begin(l), end(l));
            if (got_it(l[0], l[1], l[2]))
            {
                cout << "ALMOST";
                return 0;
            }
        }
    }

    cout << "NEITHER";
    return 0;
}
