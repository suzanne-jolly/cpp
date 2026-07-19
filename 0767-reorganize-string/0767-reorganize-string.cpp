class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(int i=0; i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for (auto const & [ch,count] : m){
            pq.push({count,ch});

        }
        string res="";
        pair<int,char>prev={0,'#'};
        while(!pq.empty()){
            auto[count,ch]=pq.top();
            pq.pop();
            res+=ch;
            if(prev.first>0){
                pq.push(prev);

            }
            count--;
            prev={count,ch};
        }
        return res.length()==s.length()? res:"";
        
    }
};