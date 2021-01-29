======================================= Merge 2 sorted array without using extra space in one traversal only ======================================

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
=======================================================================================================================================================
Solution:
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1; 
		while (m > 0 && n > 0){                    // if nums1 and nums2 are not empty   check for m and n only not for k;
            if (nums1[m - 1] > nums2[n -1]){
                nums1[k] = nums1[m - 1];
                m--;
                k--;
            }
            else{
                nums1[k] = nums2[n - 1];
                n--;
                k--;
            }
        }
		// we only check if nums2 is not empty.
		// if nums2 is empty but nums1 is not, remain the sequence 
        while (k >= 0 && n > 0){
            nums1[k] = nums2[n - 1];
                n--;                                             // corner case - if only nums2 has elements .
                k--;
        }
			
    }
