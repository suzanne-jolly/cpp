class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>rev(V);
        vector<int>indegree(V);
        for(int u=0; u<V; u++){
            for(auto v:graph[u]){
                rev[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int>q;
        vector<int>safenodes;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: rev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }



        sort(safenodes.begin(),safenodes.end());
        return safenodes;

    }
};