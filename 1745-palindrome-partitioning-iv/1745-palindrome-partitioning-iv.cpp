class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        for(int i1=1;i1<n-1;i1++){
            for(int i2=i1+1;i2<n;i2++){
                if(ispal(s,0,i1-1)&& ispal(s,i1,i2-1)&& ispal(s,i2,n-1)){
                    return true;
                }
            }
        }
         return false;
    }
private:
bool ispal(string& s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    
    
    }
    return true;
}
};