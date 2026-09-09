class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for(char ch : s){
            mpp[ch]++;
        }

        vector<pair<char,int>> v;

        for(auto x : mpp){
            v.push_back({x.first, x.second});
        }

        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b){
            return a.second > b.second;
        });

        string ans = "";

        for(auto p: v){
            char ch = p.first;
            int count = p.second;

            for(int i=0;i<count;i++){
                ans+=ch;
            }
        }
        return ans;
    }
};