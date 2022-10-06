class Solution {
public:
    int helper(string s,int k,char ch)
    {
	// Sliding Window method
        int i=0; // Intializing the value to traverse this acts as the right end of window 
        int count = 0; // To count the length 
        int j =0; // This acts as the left end of window
        int n = s.length();
        while(i<n){
		// If we have K(we can use K to change s[i] to ch ) or the char s[i] is equal to ch then we traverse the string further 
            while(i<n && (k||s[i]==ch))
            {
                if(s[i]!=ch){
                    k--;
                }
                i++;
            }
            count= max(count,i-j);// Total length
			// Now we have a window from j to i so, slide this window by increasing j 
			//if s[j] is not equal to ch then we used 1k to convert this to ch so 
			//we get back this value of k as we are checking the next window. Similarly, loop goes...... 
            if(s[j]!=ch){  
                k++;
            }
            j++;
        }
        return count;
    }
    int characterReplacement(string s, int k) {
        int ans = INT_MIN;
		// Checking length for all the alphabet (A-Z) 
        for(int i=0;i<26;i++)
        {
            ans = max(ans,helper(s,k,'A'+i));
        }
        return ans;
    }
};