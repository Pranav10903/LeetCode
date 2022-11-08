class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int>hsh;
        vector<int>res;
        for(int i=0;i<n1;i++)
        {
            hsh[nums1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            if(hsh.find(nums2[i])!=hsh.end() && --hsh[nums2[i]]>=0)
            {
                res.push_back(nums2[i]);
            }
        } return res;
    }
};