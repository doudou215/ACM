class Solution {
public:

    struct UnionFind{
        vector<int> parent;
        vector<double> weight;

        UnionFind(int n) : parent(n), weight(n) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                weight[i] = 1;
            }
        }

        int find(int x) {
            int cur = x;

            while (parent[x] != x) {
                weight[cur] *= weight[parent[x]];
                x = parent[x];
            }
            return parent[cur] = x;
        }
        
        void Myunion(int x, int y, double value) {
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y) {
                parent[root_x] = root_y;
                weight[root_x] = value * weight[y] / weight[x]; // 核心算法，先将weight[root_x]和weight[x]的关系利用find(x)找出来，再利用weight[y]和weight[x]的关系找出weight[root_x]和weight[root_y]的关系
            }
        }

        bool IsConnected(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            return root_x == root_y;
        }
    };

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        UnionFind u(2 * n);
        int id = 0;
        unordered_map<string, int> mem;
        vector<double> ret(m, -1);

        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            if (mem.find(a) == mem.end()) {
                mem[a] = id;
                id += 1;
            }
            if (mem.find(b) == mem.end()) {
                mem[b] = id;
                id += 1;
            }
            u.Myunion(mem[a], mem[b], values[i]);
        }

        for (int i = 0; i < m; i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (mem.find(a) == mem.end() || mem.find(b) == mem.end() || !u.IsConnected(mem[a], mem[b])) {
                continue;
            }
            // u.Myunion(mem[a], mem[b], 1);
            // u.find(mem[a]);
            // u.find(mem[b]);
            // cout << u.weight[mem[a]] << u.weight[mem[b]] << endl;
            ret[i] = u.weight[mem[a]] * 1.0 / u.weight[mem[b]];
        }

        return ret;
    }
};