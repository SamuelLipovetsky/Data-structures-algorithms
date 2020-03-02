#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{

    cout << 2000 << " " << 2000 << " ";
    for (int i = 0; i < 2000; i++)
    {
        cout << rand() % 2000 << " " << rand() % 2000 << " " << rand() % 2 + 1 << " ";
    }
    cout << 0;
}
