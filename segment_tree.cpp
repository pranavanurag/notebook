#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

struct node {
	// node def
	int val, lazy;
	node(int x = 0, int y = 0) {
		val = x; lazy = y;
	}
};

node tree[4*N];

void propogate_lazy(int i, int tx1, int tx2) {
	// propgate laziness
}

void merge(node &ans, node &left, node &right) {
	// merge operation
}

void build(int i, int tx1, int tx2) {
	if (tx1 > tx2)
		return;

	if (tx1 == tx2) {
		// set leaf node
		return;
	}

	int txm = (tx1 + tx2)/2;
	build(2*i, tx1, txm);
	build(2*i + 1, txm + 1, tx2);
	merge(tree[i], tree[2*i], tree[2*i + 1]);
}

void update(int i, int tx1, int tx2, int x1, int x2, int V, int P) {
	propogate_lazy(i, tx1, tx2);

	if (tx1 > tx2 || x1 > x2 || tx1 > x2 || tx2 < x1)
		return;

	if (tx1 >= x1 && tx2 <= x2) {
		// update current node 'i' and propogate laziness down if (tx1 != tx2)
		return;
	}

	int txm = (tx1 + tx2)/2;
	update(2*i, tx1, txm, x1, x2, V, P);
	update(2*i + 1, txm + 1, tx2, x1, x2, V, P);
	merge(tree[i], tree[2*i], tree[2*i + 1]);
}

node query(int i, int tx1, int tx2, int x1, int x2) {
	propogate_lazy(i, tx1, tx2);

	if (tx1 > tx2 || x1 > x2 || tx1 > x2 || tx2 < x1)
		return node();

	if (tx1 >= x1 && tx2 <= x2)
		return tree[i];

	int txm = (tx1 + tx2)/2;
	node ans,
		left = query(2*i, tx1, txm, x1, x2),
		right = query(2*i + 1, txm + 1, tx2, x1, x2);

	merge(ans, left, right);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	
	return 0;
}