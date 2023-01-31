class Solution {
public:
    vector<int> nextsmaller(vector<int> arr,int n){
   stack<int> s;
   s.push(-1);
   vector<int> ans(n);
   for(int i=n-1;i>=0;i--){
       while(s.top()!=-1 && arr[s.top()]>=arr[i] ){
           s.pop();
       }
       ans[i]=s.top();
       s.push(i);
   }
   return ans;
}
vector<int> prevsmaller(vector<int> arr,int n){
   stack<int> s;
   s.push(-1);
   vector<int> ans(n);
   for(int i=0;i<n;i++){
       while(s.top()!=-1 && arr[s.top()]>=arr[i] ){
           s.pop();
       }
       ans[i]=s.top();
       s.push(i);
   }
   return ans;
}
int largestarea(vector<int> arr,int n){
   vector<int> next;
   next=nextsmaller(arr,n);
   
   vector<int> prev;
   prev=prevsmaller(arr,n);
   
   
   int area=INT_MIN;
   for(int i=0;i<n;i++){
       int l=arr[i];
       if(next[i]==-1){
           next[i]=n;
       }
       int b=next[i]-prev[i]-1;
       area=max(area,l*b);
   }
   return area;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0 ; j < m; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = largestarea(heights,m);
            ans = max(ans,area);
        }
        return ans;
    }
};