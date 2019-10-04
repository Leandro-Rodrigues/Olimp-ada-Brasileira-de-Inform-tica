#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int mat[15][15];
int cont = 0, ans = 0;
int n, m;
int xe, ye, xs, ys;   

bool pode(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= m && !mat[i][j];
}

void solve(int x, int y) {
    mat[x][y] = 1;
    cont++;
    
    if (x == xs && y == ys) ans = max(ans, cont);
    else {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int l = x + dx[i];
            int c = y + dy[i];

            if (pode(l, c)) 
                solve(l, c);
        }
    }

    mat[x][y] = 0;
    cont--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> xe >> ye >> xs >> ys;

    for (int i = 2; i <= n; i+=2)
        for (int j = 2; j <= m; j+=2)
            mat[i][j] = 1;
    solve(xe, ye);
    cout << ans << "\n";

    return 0;
}
