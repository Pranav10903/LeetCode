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
int largestRectangleArea(vector<int> &arr){
   vector<int> next;
   int n = arr.size();
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
};