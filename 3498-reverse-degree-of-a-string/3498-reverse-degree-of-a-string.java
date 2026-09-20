class Solution {
    public int reverseDegree(String s) {
        int sum=0;
        s=s.toLowerCase();
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            int p=26-(ch-'a');
            sum=sum+p*(i+1);
        } 
        return sum;
    }
}