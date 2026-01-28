class Solution {
public:
    
    bool check(double mid, vector<vector<int>>& squares, double total_area) {
    double bottom_area = 0;

    for (auto &it : squares) {
        int y = it[1];
        int l = it[2];

        int b_y = y;
        int t_y = y + l;

        if (mid >= t_y) {
            bottom_area += 1.0 * l * l;       
        } 
        else if (mid > b_y) {
            bottom_area += (mid - b_y) * l;
        }
    }

    return bottom_area >= total_area / 2.0;
}

double separateSquares(vector<vector<int>>& squares) {
    double low = INT_MAX;
    double high = INT_MIN;
    double area = 0.0;
    double ans = 0.0;

    for (auto &it : squares) {
        double y = it[1];
        double l = it[2];

        area += 1.0 * l * l;                 
        low = min(low, y);
        high = max(high, y + l);
    }

    while (high - low > 1e-5) {
        double mid = low + (high - low) / 2;
        ans = mid;

        if (check(mid, squares, area)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return ans;
}

};