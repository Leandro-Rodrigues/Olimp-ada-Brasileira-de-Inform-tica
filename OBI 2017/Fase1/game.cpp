#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ulli unsigned long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>

int main() {
    int n, d, a;
    int cont = 0;
    cin >> n >> d >> a;

    while (true) {
        if(a > n) a = 1;
        if (a == d) break;
        cont++;
        a++;
    }
    cout << cont << "\n";
    return 0;
}
