class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        int V=numCourses;
        vector<vector<int>>adj(V);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>topo;
        vector<int>indegree(V);
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
            
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topo.push_back(front);
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    reverse(topo.begin(),topo.end());
    if(topo.size()==V){
        return topo;
    }
    return {};
        
    }
};