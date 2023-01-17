class Solution {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int num = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='1'){
                num++;
            }
            else{
                ans = Math.min(ans+1,num);
            }
        }
        return ans;
    }
}