class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (char c: s) {
            if (c == '[' || c == '(' || c == '{') {
                v.push_back(c);
            } else {
                if (v.size() == 0) {
                    return false;
                }
                char temp = v.back();
                if (c == ']' && temp != '[') return false;
                if (c == ')' && temp != '(') return false;
                if (c == '}' && temp != '{') return false;
                v.pop_back();
            }
        }
        return v.size() == 0;
    }
};
