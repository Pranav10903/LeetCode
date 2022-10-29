class Solution {
public:
    void recurPermute(vector<vector<int>>&ans,vector<int>&nums,int v) {
        if(v==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=v;i<nums.size();i++)
        {
            swap(nums[v],nums[i]);
            recurPermute(ans,nums,v+1);
            swap(nums[v],nums[i]);
        }
    }   
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(ans,nums,0);
      return ans;
    }
};