class Solution {
public:
    double minDD(double a, double b){
        return a>b?b:a;
    }
    double angleClock(int hour, int minutes) {
        double min = (minutes/(double)60);
        double min_diff = min*360;
        double hour_diff = min*30;
        double h = (hour==12?0:hour)/(double)12;
        double hour_time = h*360 + hour_diff;
        double ans = minDD(abs(hour_time-min_diff),360-abs(hour_time-min_diff));
        return ans;
    }
};