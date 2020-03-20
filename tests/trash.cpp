#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class dj
{
public:
    int no;
    int dist;
    int pre;

    friend bool operator>(const dj &obj, const dj &obj1)
    {
        return obj.dist > obj1.dist;
    }
    friend bool operator<(const dj &obj, const dj &obj1)
    {
        return obj.dist < obj1.dist;
    }
};
int main(int argc, const char *argv[])
{
    priority_queue<int, vector<dj>, greater<dj>> q;
    dj dj1;
    dj dj2;
    dj dj3;
    dj1.no = 1;
    dj1.dist = 1;
    dj1.pre = 3;

    dj2.no = 2;
    dj2.dist = 2;
    dj2.pre = 3;

    dj3.no = 3;
    dj3.dist = 3;
    dj3.pre = 3;
    q.push(dj1);
    q.push(dj2);
    q.push(dj3);
    while (q.size() > 0)
    {
        cout << q.top().no << " ";
        q.pop();
    }
}