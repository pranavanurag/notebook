#include <bits/stdc++.h>

using namespace std;

#define INF 123456789

vector <int> pq;

void max_heapify(int i) {
	int n = pq.size() - 1;

	int l = i << 1, r = l + 1, idx = i;
	if (l <= n && pq[l] > pq[i])
		idx = l;
	if (r <= n && pq[r] > pq[idx])
		idx = r;

	if (idx != i) {
		swap(pq[idx], pq[i]);
		max_heapify(idx);
	}
}

int get_max() {
	return pq[1];
}

void pop() {
	int n = pq.size() - 1;
	swap(pq[1], pq[n]);
	pq.pop_back();
	max_heapify(1);
}

void build_max_heap() {
	int n = pq.size() - 1;

	for (int i = n/2; i >= 1; i--)
		max_heapify(i);
}

void heap_sort() {
	while (pq.size() > 1) {
		cout<<get_max()<<" ";
		pop();
	}
	cout<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	pq.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin>>pq[i];

	build_max_heap();
	heap_sort();
	return 0;
}