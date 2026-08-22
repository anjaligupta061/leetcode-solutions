class Solution {
public:
    long long digitSum(int n) {
        long long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    long long product(int n) {
        long long prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        long long total = digitSum(n) + product(n);
        if (total == 0) return false;
        return (n % total == 0);
    }
};