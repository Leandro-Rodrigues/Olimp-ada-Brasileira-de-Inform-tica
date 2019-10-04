#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int main() {
    int n;
    int conserto = 0, subst = 0;
    cin >> n;

    int poste;
    for (int i = 0; i < n; i++) {
        cin >> poste;
        if (poste < 50)
            subst++;
        else if (poste >= 50 && poste < 85)
            conserto++;
    }
    cout << subst << " " << conserto << endl;
    return 0;
}
