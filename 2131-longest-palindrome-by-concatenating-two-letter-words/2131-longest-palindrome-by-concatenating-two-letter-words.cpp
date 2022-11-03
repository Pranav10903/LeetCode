

class Solution {

public:

    string reversed(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t;
    }
    int longestPalindrome(vector<string>& words) {
        int ans = 0, middle = 0;
        // count the frequency of each word
        unordered_map<string, int> cnt;
        for (auto word : words) cnt[word]++;
        for (auto [s, f] : cnt) {
            // using rev(s) is just to generalise the solution
            // in this problem, we can just check if s[0] != s[1]
            string rev = reversed(s);
            if (s != rev) {
                // case 1: the word is not same as the reversed self, e.g. "ab" != "ba
                // find the reversed self
                if (cnt.count(rev)) {
                    ans += min(cnt[s], cnt[rev]);
                }
            } else {

                // case 2: both character are same, e.g. aa

                // we can put it on both side

                ans += f;

                // however, if the frequency is odd

                if (f & 1) {

                    // we can place one in the middle and others on the side

                    middle = 1;

                    ans -= 1;

                }

            }

        }

        ans += middle;

        // at the end, we need to multiply the answer by 2

        // e.g. if frequency of "aa" is 2, the longest palindrome is 4 ("aaaa")

        return 2 * ans;

    }

};
        
    
