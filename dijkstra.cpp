#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

const int N = 123456;

struct ccompare {
	bool operator() (const pair <int, int> &lhs, const pair <int, int> &rhs) {
		return lhs.second > rhs.second;
	}
};

int n, m;
vector <int> adj[N];
int dist[N];
bool vis[N];
unordered_map <int, unordered_map <int, int> > w;
priority_queue <pair <int, int> , vector <pair <int, int> >, ccompare> pq;

void dijkstra(int src) {
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[src] = 0;
	memset(vis, 0, sizeof vis);

	for (int i = 1; i <= n; i++)
		pq.push({i, dist[i]});

	while (!pq.empty()) {
		int u = pq.top().first, d = pq.top().second;
		pq.pop();

		if (!vis[u]) {
			vis[u] = 1;
			for (int v: adj[u]) {
				if (dist[v] > dist[u] + w[u][v]) {
					dist[v] = dist[u] + w[u][v];
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin>>u>>v>>d;
		adj[u].push_back(v);
		// adj[v].push_back(u);	//uncomment for undirected graph
		w[u][v] = d;
	}

	dijkstra(1);
	for (int i = 1; i <= n; i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}