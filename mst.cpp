#include <bits/stdc++.h>

using namespace std;

struct ccompare {
	bool operator() (const pair <int, int> &lhs, const pair <int, int> &rhs) {
		return lhs.second > rhs.second;
	}
};

#define INF INT_MAX

const int N = 123456;

vector <int> adj[N];
map <int, map <int, int> > ew;
int n, m;

bool vis[N];
int key[N];
priority_queue <pair <int, int> , vector <pair <int, int> >, ccompare> pq;

void pre() {
	memset(vis, 0, sizeof vis);
	for (int u = 2; u <= n; u++)
		key[u] = INF;
	key[1] = 0;
}

int mst_wgt() {
	pre();
	int ans = 0;
	for (int u = 1; u <= n; u++)
		pq.push({u, key[u]});

	while (!pq.empty()) {
		pair <int, int> x = pq.top();
		pq.pop();
		int u = x.first, w = x.second;

		if (!vis[u]) {
			ans += w;
			vis[u] = 1;

			for (int v: adj[u]) {
				if (ew[u][v] < key[v]) {
					key[v] = ew[u][v];
					pq.push({v, key[v]});
				}
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ew[u][v] = ew[v][u] = w;
	}

	cout<<"Weight of mst: "<<mst_wgt()<<endl;

	return 0;
}