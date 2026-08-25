#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }else if(x<10){
          return true ;
        }
        vector<int> vec;
        
        while(x>0){
            vec.push_back(x%10);
            x=x/10;
        }
        vector<int> rv(vec.rbegin(), vec.rend());
        for(int i=0;i<vec.size();i++){
            if(vec[i]!=rv[i]){
                return false;
                break;
            }
        }

    return true;}
};