class Solution {
public:
    int maxProduct(int n) {
        int num=n;
        int max1= INT_MIN;
        int max2=INT_MIN;
        while(num>0){
            int rem=num%10;
            num=num/10;
            if(rem >= max1){
                max2=max1;
                max1= rem;
            }
            else if(rem>=max2){
                max2=rem;
            }
        }
        return max1 * max2;
    }
};