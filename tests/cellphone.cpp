#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
//trie
class trie_node
{
public:
    map<char, trie_node *> prox;
    bool end;
};
trie_node *get_node()
{
    trie_node *a = new trie_node;
    a->end = false;
    return a;
}
void insert(trie_node *root, string s)
{

    trie_node *head = root;
    int i = 0;
    int t = s.size();

    while (i < t)
    {

        if ((head->prox).count(s[i]))
        {
            head = (head->prox)[s[i]];

            i++;
        }
        else
        {
            trie_node *idk;
            trie_node b;
            idk = &b;
            (head->prox)[s[i]] = get_node();
            head = (head->prox)[s[i]];
            i++;
        }
    }

    (head->end) = true;
}

int count(trie_node *root, string g)
{
    trie_node *head = root;
    int t = g.size();
    int i = 1;
    int c = 1;
    //never guess the first letter
    head = (head->prox)[g[0]];
    // cout << g << endl;
    while (i < t)
    {
        // if ((head->end) == true && i < t)
        // {

        //     c++;
        // }

        if ((head->prox).size() == 1 && (head->prox).count(g[i]) == 1 && (head->end) == false)
        {

            head = (head->prox)[g[i]];
            i++;
            // continue;
        }
        else
        {
            // if ((head->prox).size() > 1)
            // {
            c++;
            head = (head->prox)[g[i]];
            i++;
            // }
        }
    }
    // cout << c << endl;
    return min(c, t);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> vec;
    cout << fixed << setprecision(2);
    while (1)
    {
        trie_node *root = get_node();
        int n = 0;
        cin >> n;

        if (cin.eof())
            break;
        vec.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            insert(root, vec[i]);
        }
        float d = 0;
        for (int i = 0; i < n; i++)
        {
            d += count(root, vec[i]);
        }
        // delete root;
        cout << d / n << endl;
    }
}
