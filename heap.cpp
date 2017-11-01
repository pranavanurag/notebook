#include <bits/stdc++.h>

using namespace std;

#define INF 123456789

struct pq {
	vector <int> x;
	int n;

	pq() {
		n = 0;
	}

	void show() {
		for (int i = 1; i <= n; i++)
			cout<<x[i]<<" ";
		cout<<endl;
	}

	void max_heapify(int i) {
		int l = i << 1, r = l + 1, idx = i;
		if (l <= n && x[l] > x[i])
			idx = l;
		if (r <= n && x[r] > x[idx])
			idx = r;

		if (idx != i) {
			swap(x[idx], x[i]);
			max_heapify(idx);
		}
	}

	int front() {
		return x[1];
	}

	void pop() {
		swap(x[1], x[n]);
		x.pop_back();
		n--;
		max_heapify(1);
	}

	void insert(int v) {
		x.push_back(v);
		n++;

		int i = n;
		while (i > 1 && x[i/2] < x[i]) {
			swap(x[i], x[i/2]);
			i = i/2;
		}
	}

	void build(vector <int> a) {
		n = a.size();
		x.resize(n + 1);
		for (int i = 0; i < a.size(); i++)
			x[i + 1] = a[i];

		for (int i = n/2; i >= 1; i--)
			max_heapify(i);
	}
};

int main() {
	ios::sync_with_stdio(false);
	
	vector <int> a = {1, 2, 5, 3, 6, -1, 10, 7};

	pq q;
	q.build(a);
	q.show();

	q.insert(-9);
	q.show();

	q.insert(7);
	q.show();
	return 0;
}