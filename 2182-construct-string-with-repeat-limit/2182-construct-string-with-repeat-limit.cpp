class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mpp;

        for (char c : s)
            mpp[c]++;

        priority_queue<pair<char, int>> pq;

        for (auto p : mpp)
            pq.push({p.first, p.second});

        string result = "";
        while (!pq.empty()) {
            auto largest = pq.top();
            pq.pop();

            int take = min(repeatLimit, largest.second);

            for (int i = 0; i < take; i++)
                result += largest.first;

            largest.second -= take;

            if (largest.second > 0) {
                if (pq.empty())
                    break;

                auto second = pq.top();
                pq.pop();

                result += second.first;
                second.second--;

                if (second.second > 0)
                    pq.push(second);

                pq.push(largest);
            }
        }

        return result;
    }
};