#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

const int t = 105;
vector< pair<int, int> > grafo[t];
int distancia[t];
bool vis[t];

void dj(int s) {
    memset(distancia, INF, sizeof distancia);
    distancia[s] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > fila;
    fila.push(make_pair(0, s));

    while (true) {
        int atual = -1;

        while (!fila.empty()) {
            int v = fila.top(). second;
            fila.pop();

            if (!vis[v]) {
                atual = v;
                break;
            }
        }

        if (atual == -1) break;
        vis[atual] = 1;

        for (int i = 0; i < grafo[atual].size(); i++) {
            int v = grafo[atual][i].second;
            int d = grafo[atual][i].first;

            if (distancia[v] > distancia[atual] + d) {
                distancia[v] = distancia[atual] + d;
                fila.push(make_pair(distancia[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int a, b, dist;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b >> dist;
        grafo[a].push_back(make_pair(dist, b));
        grafo[b].push_back(make_pair(dist, a));
    }

    dj(1);
    cout << distancia[n] << "\n";

    return 0;
}
