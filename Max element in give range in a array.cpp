/*Given an integer array of elements and q queries. In each query, [l,r] will be given and you have
to find max element in [l,r] range.
n <= 10^4
arr[i] <= 1e9
q <= 10^5 */
#include<iostream>
using namespace std;
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 10002
ll arr[MAX];
ll used[MAX][MAX];
ll n, q;

void preCalc() {
	ll mx;
	for (int i = 0; i < n; i++) {
		mx = -1;
		for (int j = i; j <= n; j++) {
			mx = max(mx, arr[j]);
			used[i][j] = mx;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	preCalc();
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		l--;
		r--;
		cout << used[l][r] << "\n";
	}
	return 0;
}

/*
i/p

10 5
1 4 3 2 7 5 13 6 23 2
1 3
3 7
6 9
8 8
1 10

o/p
4
13
23
6
23

*/