class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (const string& str: strs) {
            s += to_string(str.size());
            s += "*";
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int pointer = 0;
        while (pointer < s.size()) {
            int j = pointer;

            while (s[j] != '*') {
                j++;
            }
            int len = stoi(s.substr(pointer, j - pointer));

            string word = s.substr(j + 1, len);
            v.push_back(word);

            pointer = j + 1 + len;
        }
        return v;
    }
};
