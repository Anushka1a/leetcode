class Solution {
public:
     double findMedianSortedArrays(vector<int>&nums1, vector<int>& nums2){
        int m = nums1.size(),n=nums2.size();
        int total =m+n;
        int i =0 , j=0;
        int prev =0 , curr = 0 ;
        for(int k =0;k<=total/2;k++){
            prev = curr;
            if(i< m && (j>=n|| nums1[i]<=nums2[j]))
            curr=nums1[i++];
            else
               curr = nums2[j++];
        }
        if(total %2 == 1)
          return curr;
        return((double)prev+curr)/2.0;
     }
};