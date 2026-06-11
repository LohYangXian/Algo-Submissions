class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (char c: s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                res += tolower(static_cast<unsigned char>(c));
            }
        }
        int l = 0; 
        int r = res.size() - 1;
        while (l <= r) {
            if (res[l] != res[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
