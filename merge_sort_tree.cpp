#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int a[N], n;
vector <int> tree[N];

vector <int> merge(vector <int> &x, vector <int> &y) {
	vector <int> ans;
	int i = 0, n = x.size(), j = 0, m = y.size();

	while (i < n && j < m)
		if (x[i] < y[j])
			ans.push_back(x[i++]);
		else
			ans.push_back(y[j++]);

	while (i < n)
		ans.push_back(x[i++]);
	while (j < m)
		ans.push_back(y[j++]);

	return ans;
}

void build(int i = 1, int x1 = 1, int x2 = n) {
	if (x1 > x2)
		return;
	if (x1 == x2)
		tree[i].push_back(a[x1]);
	else {
		int mx = (x1 + x2)/2;
		build(2*i, x1, mx);
		build(2*i + 1, mx + 1, x2);
		tree[i] = merge(tree[2*i], tree[2*i + 1]);
	}
}

vector <int> query(int i, int tx1, int tx2, int x1, int x2) {
	if (x1 > x2 || tx1 > tx2 || tx1 > x2 || tx2 < x1)
		return vector <int> ();
	else if (tx1 >= x1 && tx2 <= x2)
		return tree[i];
	else {
		int txm = (tx1 + tx2)/2;
		auto left = query(2*i, tx1, txm, x1, x2);
		auto right = query(2*i + 1, txm + 1, tx2, x1, x2);
		return merge(left, right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	build();
	int q;
	cin>>q;
	while (q--) {
		int l, r;
		cin>>l>>r;
		for (auto x: query(1, 1, n, l, r))
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}