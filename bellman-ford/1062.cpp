#include <iostream>
#include <vector>
// #include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXLEN 1200
#define INF 0x7fffffff

int edge[101][101];
int ranks[101];
int visited[101];
int dis[101];

int m, n;


int dfs(int vertice, int rmin, int rmax) {
	if (visited[vertice])
		return dis[vertice];
	visited[vertice] = true;
	int ans = INF;
	for (int i = 0; i <= n; i++) {
		if (!visited[i] && edge[i][vertice] && abs(rmin - ranks[i]) < m && abs(rmax - ranks[i]) < m) {
			int nextrmin = min(ranks[i], rmin);
			int nextrmax = max(ranks[i], rmax);
			ans = min(ans, edge[i][vertice] + dfs(i, nextrmin, nextrmax));
		}
	}
	visited[vertice] = false;
	return dis[vertice] = ans;
}

int main() {
	cin >> m >> n;
	int i = 1;
	for (int l = 1; l < 101; l++)
		dis[l] = INF;
	dis[0] = 0;
	while (i <= n) {
		int counts;
		cin >> edge[0][i] >> ranks[i] >> counts;
		int j = 0;
		while (j < counts) {
			int v, weight;
			cin >> v >> weight;
			edge[v][i] = weight;
			j += 1;
		} 
		i += 1;
	}	

	int ret;
	visited[0] = 1;
	ret = dfs(1, ranks[1], ranks[1]);
	cout << ret << endl;
	return 0;
}