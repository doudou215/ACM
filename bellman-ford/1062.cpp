#include <iostream>
#include <vector>
// #include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXLEN 1200

struct 	Vertice {
	int weight;
	int prio;
};

struct Edge {
	int src;
	int dst;
	int weight;
};

struct Range {
	int rmin;
	int rmax;
};

Edge edge[MAXLEN];
Vertice	vertices[MAXLEN];
int dis[MAXLEN];
Range ranks[MAXLEN];
int m, n, k;

int bellman() {
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j < k; j++) {
			if (dis[edge[j].dst] > (dis[edge[j].src] + edge[j].weight) && (edge[j].src == 0 || abs(vertices[edge[j].dst].prio - vertices[edge[j].src].prio) <= m)) {
				if ((abs(vertices[edge[j].dst].prio - ranks[edge[j].src].rmin) > m || abs(vertices[edge[j].dst].prio - ranks[edge[j].src].rmax) > m) && edge[j].src)
					continue;
				if (edge[j].src) {
					ranks[edge[j].dst].rmin = min(vertices[edge[j].dst].prio, ranks[edge[j].src].rmin);
					ranks[edge[j].dst].rmax = max(vertices[edge[j].dst].prio, ranks[edge[j].src].rmax);
				}
				dis[edge[j].dst] = dis[edge[j].src] + edge[j].weight;
				cout << dis[edge[j].dst] << " " << dis[edge[j].src] << " " << edge[j].dst << " " << edge[j].src << endl;
			}
		}
		cout << endl;
	}
	return dis[1];
}

int main() {
	cin >> m >> n;
	k = 0;
	int i = 1;
	for (int l = 1; l < MAXLEN; l++)
		dis[l] = 100000;
	dis[0] = 0;
	// ranks[0].rmin = 100000;
	// cout << dis[1] << endl;
	while (i <= n) {
		int counts;
		cin >> vertices[i].weight >> vertices[i].prio >> counts;
		int j = 0;
		ranks[i].rmin = vertices[i].prio;
		ranks[i].rmax = vertices[i].prio;
		edge[k].src = 0;
		edge[k].dst = i;
		edge[k].weight = vertices[i].weight;
		k += 1;
		while (j < counts) {
			int v, weight;
			cin >> v >> weight;
			edge[k].src = v;
			edge[k].dst = i;
			edge[k].weight = weight;
			k += 1;
			j += 1;
		} 
		i += 1;
	}	

	/*
	for (int i = 0; i < k; i++)
		cout << edge[i].src << edge[i].dst << edge[i].weight << endl;
	*/
	int ret;
	ret = bellman();
	cout << ret << endl;
	return 0;
}