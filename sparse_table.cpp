#include <bits/stdc++.h>

using namespace std;

const int N = 312345;
const int K = (int)(log2)(N) + 1;

int n, a[N];
int k, table[N][K];

void build() {
	k = (int)(log2(n));
	for (int i = 1; i <= n; i++)
		table[i][0] = a[i];

	for (int j = 1; j <= k; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int len = r - l + 1;
	int x = log2(len);

	return min(table[l][x], table[r - (1 << x) + 1][x]);
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	build();

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}