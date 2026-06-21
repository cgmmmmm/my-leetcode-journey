using ll = long long;
class Solution {
public:
    ll dfs(int u, const vector<vector<int>>& adj, const vector<int>& baseTime) {
        if (adj[u].empty()) return baseTime[u];

        ll earliest = LLONG_MAX;
        ll latest = LLONG_MIN;

        for (int v : adj[u])
        {
            ll cf = dfs(v, adj, baseTime);
            earliest = min(earliest, cf);
            latest = max(latest, cf);
        }

        ll ownDur = (latest - earliest) + baseTime[u];
        return latest + ownDur;
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for (const auto& e : edges)
        {
            int p = e[0];
            int c = e[1];
            adj[p].push_back(c);
        }

        return dfs(0, adj, baseTime);
    }
};