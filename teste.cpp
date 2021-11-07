#include <bits/stdc++.h>

using namespace std;

#define N 1000005
#define mod 1000000007
#define ll long long int

int solve(int n, vector<int> v) {
    ll mask = 0LL;
    for (int i = 0; i <= n; i++) {
        if (mask & (1LL << v[i]))
            return v[i];
        mask |= (1LL << v[i]);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> v[i];
    cout << solve(n, v) << "\n";

    return 0;
}