#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         nums1.resize(m);
         int i=0;
         int j=0;
        while(j<n){
              while (i < nums1.size() && nums1[i] <= nums2[j]) {
                i++;
            }
            nums1.insert(nums1.begin() + i, nums2[j]);
            i++;
            j++;
        }
    }
};