    // I also came up with slope comparison
    // but didn't think this easy to avoid divide by zero
    bool isBoomerang(vector<vector<int>>& points) {
return ((points[1][1] - points[0][1]) * (points[2][0] - points[0][0])) != ((points[2][1] - points[0][1]) * (points[1][0] - points[0][0]));
    }
