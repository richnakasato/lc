ass Solution {
public:
    double getSmallAngle(double hour_angle, double minute_angle) {
        auto angle = abs(minute_angle - hour_angle);
        auto smaller_angle = min(360 - angle, angle);
        return smaller_angle;
    }
    double doMinutes(int minutes) {
        return ((double)minutes)/60 * 360;
    }
    double doHours(int hour, int minutes) {
        auto hour_mod = hour % 12;
        auto angle_per_hour = 30;
        auto hour_base_angle = hour_mod * angle_per_hour;
        double hour_frac_angle = ((double)minutes)/60 * angle_per_hour;
        return hour_base_angle + hour_frac_angle;
    }
    double angleClock(int hour, int minutes) {
        auto m = doMinutes(minutes);
        auto h = doHours(hour, minutes);
        return getSmallAngle(h, m);
    }
};
