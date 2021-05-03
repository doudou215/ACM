#include <iostream>
#include <string.h>

using namespace std;

struct Edge {
	int src;
	int dst;
	double rate;
	double commission;
};

Edge edge[220];
double dis[150];
int n, m, s;
double v;

bool dfs() {
	memset(dis, 0, sizeof(dis));
	dis[s] = v;

	for (int i = 1; i <= n - 1; i++) {
		bool flag = true;
		for (int j = 0; j < 2 * m; j++) {
			if (dis[edge[j].dst] < (dis[edge[j].src] - edge[j].commission) * edge[j].rate) {
				dis[edge[j].dst] = (dis[edge[j].src] - edge[j].commission) * edge[j].rate;
				flag = false;
			}
		}
		if (flag)
			break;
	}

	for (int j = 0; j < 2 * m; j++) {
		if (dis[edge[j].dst] < (dis[edge[j].src] - edge[j].commission) * edge[j].rate) {
			dis[edge[j].dst] = (dis[edge[j].src] - edge[j].commission) * edge[j].rate;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m >> s >> v;

	int i = 0;
	while (i < 2 * m) {
		cin >> edge[i].src >> edge[i].dst >> edge[i].rate >> edge[i].commission;
		edge[i + 1].src = edge[i].dst;
		edge[i + 1].dst = edge[i].src;
		cin >> edge[i + 1].rate >> edge[i + 1].commission;
		i += 2;
	}

	if (dfs())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}