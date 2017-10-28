#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector <int> adj[N];
int n, m;
bool vis[N];

queue <int> q;
void bfs_sub(int u) {
	q.push(u);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int v: adj[curr])
			if (!vis[v])
				vis[v] = 1, q.push(v);
	}
}

void bfs() {
	for (int u = 1; u <= n; u++)
		if (!vis[u])
			vis[u] = 1, bfs_sub(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int u, v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();
	return 0;
}