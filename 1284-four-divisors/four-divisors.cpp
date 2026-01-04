class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sol = 0;
        for (int k = 0; k < n; k++) {
            int num = nums[k];
            long long total = 1;
            long long count = 1;

            for (int i = 2; (long long)i * i <= num; i++) {
                if (num % i == 0) {
                    int e = 1;
                    num/=i;
                    while (num % i == 0){
                        num/=i;
                        e++;
                    }
                    count *= e + 1;

                    long long sum = 1, pow = i;
                    while(e-- > 0){
                        sum += pow;
                        pow *= i;
                    }
                    total *= sum;
                }
            }

            if (num > 1) {
                total *= (1 + num);
                count *= 2;
            }

            if (count == 4)
                sol += total;
                
        }
        return sol;
    }
};