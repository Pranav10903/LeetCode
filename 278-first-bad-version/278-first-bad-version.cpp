// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 0; int e = n;
        int ans = 0;
        while(s<=e)
        {
            int mid = s +(e-s)/2;
            if(isBadVersion(s))
            {
                return s;
            }
            else if(isBadVersion(mid))
            {
                ans = mid;
                e = mid-1;
            }
            else if(!isBadVersion(mid))
            {
                s = mid+1;
            }
        } return ans;
    }
};