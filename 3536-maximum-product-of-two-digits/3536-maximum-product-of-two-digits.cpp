class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n>0){
            pq.push(n%10);
            n/=10;
        }
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        long long ans = x*y;
        return ans;
    }
};