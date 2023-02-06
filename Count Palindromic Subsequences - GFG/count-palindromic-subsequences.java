//{ Driver Code Starts
import java.util.*;
class GFG
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		while(t>0)
		{
			String str = sc.nextLine();
			//System.out.println(str.length());
			Solution ob  = new Solution();
			System.out.println(ob.countPS(str));
		t--;
		}
	}
}
// } Driver Code Ends


/*You are required to complete below method */

class Solution
{
    long mod=1000000007;
    long solve(String s)
    {
        int n=s.length();
        long dp[][]=new long[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(j-1>=0)
                {
                    if(s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=(1+dp[i+1][j]%mod+dp[i][j-1]%mod)%mod;
                    }
                    else
                    {
                        dp[i][j]=(mod+dp[i+1][j]%mod+dp[i][j-1]%mod-dp[i+1][j-1]%mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    long countPS(String str)
    {
        // Your code here
        return solve(str);
    }
}