class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Use an unordered_set for O(1) lookups of valid mutations
        unordered_set<string> bankSet(bank.begin(), bank.end());
        
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        
        // If startGene happens to be in the bank, erase it so we don't revisit it
        if (bankSet.count(startGene)) {
            bankSet.erase(startGene);
        }
        
        // The 4 possible nucleotide choices for a mutation
        vector<char> choices = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            string cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if (cur == endGene) {
                return steps;
            }
            
            // Try mutating each of the 8 characters
            for (int i = 0; i < 8; i++) {
                char original = cur[i];
                
                // Try replacing the current character with A, C, G, or T
                for (char c : choices) {
                    if (c == original) continue; // Skip if it's the same character
                    
                    cur[i] = c;
                    
                    // If the mutated gene is valid (exists in the bank)
                    if (bankSet.find(cur) != bankSet.end()) {
                        bankSet.erase(cur); // Remove it from the bank to mark it as visited
                        q.push({cur, steps + 1});
                    }
                }
                
                // Backtrack: restore the original character for the next iteration
                cur[i] = original;
            }
        }
        
        // If we exhaust the queue without finding the endGene
        return -1;
    }
};