class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        //  if (divisor == 0 || (dividend == INT_MIN && divisor == 1)) return INT_MIN;
        long long int s = 0;
        long long int e = llabs(dividend);
        long long int mid = s + (e - s)/2;
        long long int ans =0;
        while(s<=e){
            if(llabs(mid*divisor) == llabs(dividend)){
                ans = mid;       //  store and break instead of returning mid
                break;
            }
            if(llabs(mid*divisor) > llabs(dividend)){
                
                e = mid - 1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
            mid = s + ( e - s)/2;
        }
        if((divisor > 0 && dividend > 0 ) || (divisor < 0 && dividend < 0 )){
            return ans;
        }
        else{
            return -ans;
        }
    }
};