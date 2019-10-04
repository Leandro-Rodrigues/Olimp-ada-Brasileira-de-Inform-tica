#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3fLL
#define pb push_back

const int t = 505;
bool vis[t];
int idades[t], id[t];
int ans;
vector<int> grafo[t];

void dfs(int x) {
    vis[x] = 1;
    for (auto v: grafo[x]) {
        if (!vis[v]) {
            vis[v] = 1;
            ans = min(ans, idades[v]);
            dfs(v);
        }
    }
}

void troca(int a, int b) {
    swap(idades[id[a]], idades[id[b]]);
    swap(id[a], id[b]);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, in;
    int a, b;
    int e, x, y;
    char op;
    
    while (cin >> n >> m >> in) {
        for (int i = 1; i <= n; i++) {
            cin >> idades[i];
            id[i] = i;
        }
        while (m--) {
            cin >> x >> y;
            grafo[y].pb(x);
        }
        while (in--) {
            ans = INF;
            cin >> op;
            if (op == 'T') {
                cin >> a >> b;
                troca(a, b);
            }
            else {
                cin >> e;
                if (grafo[id[e]].size() == 0)
                    cout << "*\n";
                else {
                    memset(vis, 0, sizeof vis);
                    dfs(id[e]);
                    cout << ans << "\n";
                }
            }
        }
        for (int i = 1; i <= n; i++) 
            grafo[i].clear();
    }
    return 0;
}
