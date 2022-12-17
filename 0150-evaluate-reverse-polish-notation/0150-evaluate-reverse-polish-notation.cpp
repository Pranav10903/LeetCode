class Solution {
public:
    void solve(stack<long long> &st,string s){
        long long b=st.top();st.pop();
        long long a=st.top();st.pop();
        if(s=="+"){
            st.push(a+b);
        }
        else if(s=="-"){
            st.push(a-b);
        }
        else if(s=="*"){
            st.push(a*b);
        }
        else{
            st.push(a/b);
        }
    }
    int evalRPN(vector<string>& nums) {
        int n=nums.size();
        stack<long long> st;
        for(int i=0;i<n;i++){
            if(nums[i]=="+" || nums[i]=="-" || nums[i]=="*" || nums[i]=="/"){
                solve(st,nums[i]);
            }
            else{
                st.push(stol(nums[i]));
            }
        }
        return st.top();
    }
};