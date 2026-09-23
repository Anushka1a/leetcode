// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
//         int all=0;
//         int i=0;
//         dfs(s,dict,i,all);
//         return (all>0);
        
//     }
//     private:
//     void dfs(string& s, unordered_set<string>& dict, int i , int& all){
//         if(i==s.size()) all=true;
//         else{
//             for(int j=i;j<s.size();j++){
//                 string word = s.substr(i,j-i+1);
//                 if(dict.find(word)!= dict.end()){
                


//                      dfs(s, dict, j+1,  all);
//                 }
//             }
//         }
//     }
// };
//    //second way
//     class Solution2 {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        
//         int i=0;
        
//         return f1(s,dict,i)>0;
        
        
//     }
//     private:
//     int f1(string& s, unordered_set<string>& dict, int i ){
//         if(i==s.size()) return 1;
//         else{ int count =0;
//             for(int j=i;j<s.size();j++){
//                 string word = s.substr(i,j-i+1);
//                 if(dict.find(word)!= dict.end()){
//                 count+= f1(s,dict,j+1);
                


                    
//                 }
//             }
//             return count;
//         }
//     }
// };
//    //memorization of the head recursive recurrence
//   class Solution3 {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());

//         int i = 0;
//         vector<int> dp(s.size() + 1, -1);

//         return f1(s, dict, i, dp) > 0;
//     }

// private:
//     int f1(string& s, unordered_set<string>& dict, int i, vector<int>& dp) {

//         if(i == s.size())
//             return 1;

//         if(dp[i] != -1)
//             return dp[i];

//         for(int j = i; j < s.size(); j++) {

//             string word = s.substr(i, j - i + 1);

//             if(dict.find(word) != dict.end()) {

//                 if(f1(s, dict, j + 1, dp))
//                     return dp[i] = 1;
//             }
//         }

//         return dp[i] = 0;
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int i = 0;
        vector<int> dp(s.size() + 1, -1);

        return f1(s, dict, i, dp) > 0;
    }

private:
    int f1(string& s, unordered_set<string>& dict, int i, vector<int>& dp) {

        if(i == s.size())
            return 1;

        if(dp[i] != -1)
            return dp[i];

        for(int j = i; j < s.size(); j++) {

            string word = s.substr(i, j - i + 1);

            if(dict.find(word) != dict.end()) {

                if(f1(s, dict, j + 1, dp))
                    return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }
};