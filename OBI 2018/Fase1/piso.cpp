#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int main() {
    int l, c;
    int ans1, ans2;
    cin >> l >> c;

    ans1 = (l * c) + (l - 1) * (c - 1);
    ans2 = (l - 1) * 2;
    ans2 += (c - 1) * 2;

    cout << ans1 << "\n"; 
    cout << ans2 << "\n";
    return 0;
}
