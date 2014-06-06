/*
错误：
没有考虑斜率为零的情况，k = (y1-y2)/(x1-x2)，此时除数为零！不能用斜截式表示
没有考虑重合点
没有考虑全部是重合点。。。
重合点计数错误
结构体下标错误
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxCount = (points.size() > 2) ? 2 : points.size();
        for(vector<Point>::size_type i = 0; i < points.size(); i++){
            int overlapPointCount = 1;  //重合点计数，算上当前点
            for(vector<Point>::size_type j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    overlapPointCount++;
                    continue;
                }
                //calculate line equation (line: Ax + By + C = 0, y = kx + d)
                double A, B, C;
                if(points[i].x != points[j].x){
                    double k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    double d = points[i].y - k * points[i].x;
                    A = k, B = -1, C = d;
                } else{
                    A = 1, B = 0, C = -points[i].x;
                }
                int count = 1 + overlapPointCount;  //当前点j + 另一点i及其所有重合点
                //find points on this line
                for(vector<Point>::size_type p = j + 1; p < points.size(); p++){
                    if(doubleEqual(A * points[p].x + B * points[p].y + C, 0)){
                        count++;
                    }
                }
                if(maxCount < count)
                    maxCount = count;
            }
            if(maxCount < overlapPointCount)    //全部是重合点，未能组成直线
                maxCount = overlapPointCount;
        }
        return maxCount;
    }
private:
    bool doubleEqual(double a, double b){
        return fabs(a - b) < 0.000001;
    }
};