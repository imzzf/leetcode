#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        char ch[7] = {'I','V','X','L','C','D','M'};
        int num[7] = {1,5,10,50,100,500,1000};
        for(int n = 0; n < s.size()-1; n++) {
            int i = 0;
            int j = 0;
            while(s[n] != ch[i]) {
                i++;
            }
            while(s[n+1] != ch[j]) {
                j++;
            }
            //如遇前小后大的特例，则减去小数加上大数。
            //例如IV=-1+5
            if(j>i){
                value -= num[i];
            }else{
                value += num[i];
            }
        }
        int i = 0;
        while(s[s.size()-1] != ch[i]){
           i++; 
        }
        value += num[i];
        return value;
    }
};
