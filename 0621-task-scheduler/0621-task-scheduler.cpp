class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch : tasks){
            freq[ch-'A']++;
        }
        int maxfreq = 0;
        for(int x : freq){
            maxfreq = max(maxfreq, x);
        }
        int countMax = 0;
        for (int x : freq)
            if (x == maxfreq) countMax++;
        int formula = (maxfreq-1)*(n+1)+countMax;
        return max((int)tasks.size(), formula);
    }
};