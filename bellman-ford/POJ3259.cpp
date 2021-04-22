#include <iostream>
#include <string.h>

using namespace std;

int dis[5200];

struct Edge {
	int src;
	int dst;
	int weight;
}e[5200];

int idx;
int n, m, w;

bool bellman() {
	for (int i = 1; i <= n - 1; i++) {
		bool flag = false;
		for (int j = 0; j < idx; j++) {
			if (dis[e[j].dst] > dis[e[j].src] + e[j].weight) {
				flag = true;
				dis[e[j].dst] = dis[e[j].src] + e[j].weight;
			}
		}
		if (!flag)
			break;
	}

	for (int i = 0; i < idx; i++) {
		if (dis[e[i].dst] > dis[e[i].src] + e[i].weight)
			return true;
	}
	return false;
}

int main() {
	int F;
	cin >> F;
	
	while (F--) {
		cin >> n >> m >> w;
		idx = 0;
		memset(dis, 100000, sizeof(dis));

		for (int i = 0; i < m; i++) {
			cin >> e[idx].src >> e[idx].dst >> e[idx].weight;
			e[idx + 1].src = e[idx].dst;
			e[idx + 1].dst = e[idx].src;
			e[idx + 1].weight = e[idx].weight;
			idx += 2; 
		}
		for (int i = 0; i < w; i++) {
			cin >> e[idx].src >> e[idx].dst >> e[idx].weight;
			e[idx].weight = 0 - e[idx].weight;
			idx++;
		}
		
		dis[1] = 0;
		if (bellman())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
