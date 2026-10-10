class Solution {
public:
    int mySqrt(int x) {
        long long low,high;
        high=(long long)x+1;   low=0;
        while(high-low>1){
            long long mid=(low+high)/2;
            if(mid*mid>x){
                high=mid;
            }else if(mid*mid<x){
                low=mid;
            }else{
                return mid;
            }
        }
        return low;
    }
};