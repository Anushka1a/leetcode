class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        
        // knowledge ko map mein store karo
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }
        
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') {
                
                string key = "";
                i++;
                
                // '(' aur ')' ke beech ka key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                
                // key map mein hai?
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } 
                else {
                    ans += "?";
                }
            }
            else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};