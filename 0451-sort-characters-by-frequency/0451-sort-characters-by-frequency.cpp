class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        // Character + frequency
        vector<pair<char, int>> v;

        for (auto p : freq) {
            v.push_back({p.first, p.second});
        }

        // Decreasing frequency
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });

        // Build answer
        string ans = "";

        for (auto p : v) {

            char ch = p.first;
            int count = p.second;

            for (int i = 0; i < count; i++) {
                ans += ch;
            }
        }

        return ans;
    }
};