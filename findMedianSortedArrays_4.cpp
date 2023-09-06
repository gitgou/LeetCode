#include<vector>
#include<iostream>

using namespace std;

// k 为在现有范围内的第 k 个数
double getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
  if(start1 > end1){
    return nums2[start2 + k - 1];
  }
  if(start2 > end2){
    return nums1[start1 + k - 1];
  }

  if(k == 1){
    return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
  }
  int tmp = k / 2;
  int index1 = start1 + tmp - 1;
  int index2 = start2 + tmp - 1;
  index1 = index1 < end1 ? index1 : end1;
  index2 = index2 < end2 ? index2 : end2;

  if(nums1[index1] < nums2[index2]){
    return getKth(nums1, index1 + 1, end1, nums2, start2, end2, k - (index1 - start1 + 1));
  }else{
    return getKth(nums1, start1, end1, nums2, index2 + 1, end2, k - (index2 - start2 + 1));
  }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int m = nums1.size(), n = nums2.size();
  int left = (m + n + 1) / 2; // 如果为偶数，left 即为中位数的第 k th， right = k + 1 th
  int right = (m + n + 2) / 2; 

  return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) * 0.5;
}

int main(){
  vector<int> vec1{1,2,3,4,5};
  vector<int> vec2{1,1,3,4,5};
  double res = findMedianSortedArrays(vec1, vec2);
  return 0;
}