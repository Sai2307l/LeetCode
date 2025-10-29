class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minVal = -1, maxVal = -1, mode = 0, modeFreq = 0;
        long long totalSum = 0, totalCount = 0;
        for (int i = 0; i < 256; ++i) {
            if (count[i]) {
                if (minVal == -1) minVal = i;
                maxVal = i;
                if (count[i] > modeFreq) {
                    modeFreq = count[i];
                    mode = i;
                }
                totalSum += 1LL * i * count[i];
                totalCount += count[i];
            }
        }
        double median = 0;
        int mid1 = -1, mid2 = -1;
        long long cnt = 0;
        for (int i = 0; i < 256; ++i) {
            if(count[i]){
                cnt += count[i];
                if (cnt >= (totalCount + 1) / 2 && mid1 == -1) mid1 = i;
                if (cnt >= (totalCount + 2) / 2) {
                    mid2 = i;
                    break;
                }
            }
        }
        median = (totalCount % 2 == 1) ? mid2 : (mid1 + mid2) / 2.0;
        return {(double)minVal, (double)maxVal, (double)totalSum / totalCount, median, (double)mode};
    }
};