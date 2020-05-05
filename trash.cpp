#include <iostream>
#include <set>
#include <stdio.h>  /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
using namespace std;
int main()
{
    cout << 100 << endl;
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        cout << rand() % 2000000 << " " << rand() % 20000000 << endl;
    }
}
