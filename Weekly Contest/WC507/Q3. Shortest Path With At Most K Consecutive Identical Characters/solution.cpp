class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // u: start node
        // v: end node
        // w: edge weight

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) 
            adj[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currW = curr[0];
            int u = curr[1];
            int count = curr[2];

            if (currW > dist[u][count]) continue;

            if (u == n-1) return currW;

            for (const auto& neighbour : adj[u])
            {
                int v = neighbour.first;
                int w = neighbour.second;

                int newCount = (labels[v] == labels[u]) ? (count + 1) : 1;
                
                if (newCount > k) continue;

                if (currW + w < dist[v][newCount])
                {
                    dist[v][newCount] = currW + w;
                    pq.push({currW + w, v, newCount});
                }
            }
        }

        return -1;
    }
};