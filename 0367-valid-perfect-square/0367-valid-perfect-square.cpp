#define ll long long
class Solution {
public:
    bool isPerfectSquare(int num) {
        ll low = 1, high = num;
        while (low <= high) {
            ll mid = (low + high) >> 1;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                low = (int) mid + 1;
            } else {
                high = (int) mid - 1;
            }
        }
        return false;
    }
};