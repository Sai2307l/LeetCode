class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
    int n = nums.size();
    int sol = 0;
    for(int k=0;k<n;k++){
        int num = nums[k];
        long long total = 1;
        long long count = 1;
        for (int i = 2; (long long)i * i <= num; i++) {
            if (num % i == 0) {
                int e = 0;
                do {
                    e++;
                    num /= i;
                } while (num % i == 0);
                count *= e + 1;

                long long sum = 0, pow = 1;
                do {
                    sum += pow;
                    pow *= i;
                } while (e-- > 0);
                total *= sum;
            }
        }
        if (num > 1) {
            total *= (1 + num);
            count *= 2;
        }
        if(count==4) sol+=total;
    }
    return sol;
    }
};