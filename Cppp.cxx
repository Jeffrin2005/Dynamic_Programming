#include <bits/stdc++.h>

#define large 1000000007
#define BITS 32
#define For(t, i, n) for (t i = 0; i < n; i++)
#define Forr(t, i, a, b) for (t i = a; i <= b; i++)
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;

struct Node
{
    char move;
    int left;
    int right;
};

int DFS(Node nodes[], int root)
{
    Node node = nodes[root];
    if (node.left == 0)
    {
        if (node.right == 0)
            return 0;
        int op = DFS(nodes, node.right);
        if (node.move != 'R')
            return 1 + op;
        else
            return op;
    }
    if (node.right == 0)
    {
        int op = DFS(nodes, node.left);
        if (node.move != 'L')
            return 1 + op;
        else
            return op;
    }
    int opl = DFS(nodes, node.left), opr = DFS(nodes, node.right);
    if (node.move != 'L')
        opl++;
    if (node.move != 'R')
        opr++;
    return min(opl, opr);
}

void test_case()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    Node nodes[n + 1];

    For(int, i, n)
    {
        nodes[i + 1].move = s[i];
    }

    For(int, i, n)
    {
        int u, v;
        cin >> u >> v;
        nodes[i + 1].left = u;
        nodes[i + 1].right = v;
    }

    cout << DFS(nodes, 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    // t = 1;

    while (t--)
    {
        test_case();
    }
    return 0;
}
