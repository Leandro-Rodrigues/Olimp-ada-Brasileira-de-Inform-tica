#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int main() {
    int n;
    char ans = 'S';
    cin >> n;
    vector<int> vet(n);

    for (int i = 0; i < n; i++)
        cin >> vet[i];
    sort(vet.begin(), vet.end());

    if (vet[0] > 8) cout << "N\n";
    else {
        for (int i = 0; i < n - 1; i++) {
            if (vet[i + 1] - vet[i] > 8) {
                ans = 'N';
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
