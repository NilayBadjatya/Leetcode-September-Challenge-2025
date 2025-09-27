class Solution {
    public double largestTriangleArea(int[][] p) {
        double area = 0;
        int n = p.length;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int x1 = p[i][0], x2 = p[j][0], x3 = p[k][0];
                    int y1 = p[i][1], y2 = p[j][1], y3 = p[k][1];
                    double tempArea = Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
                    area = Math.max(area, tempArea);
                }
            }
        }
        return area;
    }
}
