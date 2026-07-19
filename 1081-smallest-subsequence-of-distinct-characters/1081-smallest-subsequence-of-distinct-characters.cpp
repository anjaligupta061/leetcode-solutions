class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        for (char ch : s)
            freq[ch - 'a']++;
        string st = "";
        for (char ch : s) {
            freq[ch - 'a']--;
            if (vis[ch - 'a'])
                continue;
            while (!st.empty() &&
                   st.back() > ch &&
                   freq[st.back() - 'a'] > 0) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            vis[ch - 'a'] = true;
        }
        return st;
    }
};