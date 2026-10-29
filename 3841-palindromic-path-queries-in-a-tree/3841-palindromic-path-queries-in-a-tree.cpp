class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void add(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        // XOR update on range [l, r]
        void rangeUpdate(int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), sz(n, 1);
        vector<int> order;
        order.reserve(n);

        // Iterative DFS: avoids recursion stack overflow.
        vector<int> st = {0};
        vector<int> parent(n, -1);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = (int)order.size();
            order.push_back(u);
            up[0][u] = parent[u];

            for (int v : adj[u]) {
                if (parent[v] != -1)
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        // Calculate subtree sizes in reverse DFS order.
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        // Binary lifting table.
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b])
                swap(a, b);

            int diff = depth[a] - depth[b];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k))
                    a = up[k][a];
            }

            if (a == b)
                return a;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }

            return up[0][a];
        };

        auto mask = [](char c) {
            return 1 << (c - 'a');
        };

        Fenwick fw(n);

        // Initial root-to-node XOR masks.
        vector<int> pref(n, 0);

        for (int u : order) {
            pref[u] = mask(s[u]);

            if (u != 0)
                pref[u] ^= pref[parent[u]];
        }

        // Initialize Fenwick with point values.
        for (int u = 0; u < n; u++) {
            int p = tin[u] + 1;
            fw.rangeUpdate(p, p, pref[u]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);

                if (delta != 0) {
                    int l = tin[u] + 1;
                    int r = tin[u] + sz[u];

                    fw.rangeUpdate(l, r, delta);
                    s[u] = c;
                }
            } 
            else {
                int v;
                ss >> v;

                int a = lca(u, v);

                int pu = fw.query(tin[u] + 1);
                int pv = fw.query(tin[v] + 1);

                int pathMask = pu ^ pv ^ mask(s[a]);

                ans.push_back(__builtin_popcount(
                    (unsigned int)pathMask
                ) <= 1);
            }
        }

        return ans;
    }
};