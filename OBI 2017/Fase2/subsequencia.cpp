#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n, x, ant;
	int ans = 1, cont = 1;
	int diff[10005];
	
	cin >> n;
	cin >> ant;
	for (int i = 1; i < n; i++) {
		cin >> x;
		diff[i] = abs(x - ant);
		ant = x;
		if (n == 2 && x == ant)
			ans = 2;
	}
	
	for (int i = 1; i < n; i++) {
		if (diff[i] <= 1)
			cont++;
		else {
			ans = max(ans, cont);
			cont = 1;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
