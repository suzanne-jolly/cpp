class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")){
            return -1;
        }
        q.push({"0000",0});
        
        visited.insert("0000");
     
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==target){
                return steps;
            }
            for(int i=0; i<4; i++){
                char original=word[i];
                word[i]=(original=='9')? '0':original+1;
                if(visited.find(word)==visited.end()){
                    visited.insert(word);
                    q.push({word,steps+1});
                }

                word[i]=(original=='0')?'9':original-1;
                if(visited.find(word)==visited.end()){
                    visited.insert(word);
                    q.push({word,steps+1});
                }
                word[i]=original;

            }
        }
        return -1;

        
    }
};