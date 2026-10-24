

class Solution{
    public:
     int solve(vector<int>& nums, int target, int idx,int sum){
     if(idx == nums.size()){
        return (sum == target)? 1:0;

     }
       return solve (nums,target,idx+1,sum + nums[idx]) + solve(nums,target,idx+1,sum - nums[idx]);

     }
      int findTargetSumWays(vector<int>& nums,int target ){
        return solve(nums,target,0,0);
      }

};
