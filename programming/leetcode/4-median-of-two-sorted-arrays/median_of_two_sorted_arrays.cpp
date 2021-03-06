/** 
 * @problem: 4. Median of Two Sorted Arrays
 * @file: median-of-two-sorted-arrays.cpp
 * @url: https://leetcode-cn.com/problems/median-of-two-sorted-arrays
 * @description: 
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n
 * respectively.
 * Find the median of the two sorted arrays. The overall run time
 * complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * 
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 * 
 * @author: Du Ang
 * @date: Mar 30, 2019
 */

#include <iostream>
#include <vector>

using namespace std;

int find_the_kth_largest_num(vector<int>::const_iterator A, int m,
                             vector<int>::const_iterator B, int n, int k)
{
    if (m > n) return find_the_kth_largest_num(B, n, A, m, k);
    if (m == 0) return *(B + k - 1);
    if (k == 1) return min(*A, *B);
    int i = min(m, k/2), j = k - i;
    if (*(A + i - 1) < *(B + j - 1)) {
        return find_the_kth_largest_num(A + i, m - i, B, n, k - i);
    } else if (*(A + i - 1) > *(B + j - 1)) {
        return find_the_kth_largest_num(A, m, B + j, n - j, k - j);
    } else {
        return *(A + i - 1);
    }
}

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 != 0) {
            return find_the_kth_largest_num(nums1.begin(), m, nums2.begin(), n,
                                            (m + n) / 2 + 1);
        } else {
            double a = find_the_kth_largest_num(nums1.begin(), m, nums2.begin(), n,
                                         (m + n) / 2);
            double b = find_the_kth_largest_num(nums1.begin(), m, nums2.begin(), n,
                                         (m + n) / 2 + 1);
            return (a + b) / 2.;
        }
    }
};

double find_the_kth_largest_num_optimize(vector<int>::const_iterator A, int m,
                                         vector<int>::const_iterator B, int n,
                                         int k, bool find_next)
{
    if (m > n)
        return find_the_kth_largest_num_optimize(B, n, A, m, k, find_next);
    if (m == 0) {
        if (!find_next) {
            return *(B + k - 1);
        } else {
            double a = *(B + k - 1);
            double b = *(B + k);
            return (a + b) / 2.;
        }
    }
    if (k == 1) {
        if (!find_next) {
            return min(*A, *B);
        } else {
            double a, b;
            if (*A < *B) {
                a = *A;
                if (m > 1) {
                    b = min(*(A+1), *B);
                } else {
                    b = *B;
                }
            } else if (*A == *B) {
                return *A;
            } else {
                a = *B;
                if (n > 1) {
                    b = min(*A, *(B + 1));
                } else {
                    b = *A;
                }
            }
            return (a + b) / 2.;
        }
    }
    int i = min(m, k / 2), j = k - i;
    if (*(A + i - 1) < *(B + j - 1)) {
        return find_the_kth_largest_num_optimize(A + i, m - i, B, n, k - i,
                                                 find_next);
    } else if (*(A + i - 1) > *(B + j - 1)) {
        return find_the_kth_largest_num_optimize(A, m, B + j, n - j, k - j,
                                                 find_next);
    } else {
        if (!find_next) {
            return *(A + i - 1);
        } else {
            double a = *(A + i - 1);
            double b;
            if (i <= m && j <= n) {
                b = min(*(A + i), *(B + j));
            } else if (j <= n) {
                b = *(B + j);
            } else if (i <= m) {
                b = *(A + i);
            } else {
                exit(-1);
            }
            return (a + b) / 2.;
        }
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        bool find_next = ((m + n) % 2 == 0);
        if (find_next) {
            return find_the_kth_largest_num_optimize(
                nums1.begin(), m, nums2.begin(), n, (m + n) / 2, find_next);
        } else {
            return find_the_kth_largest_num_optimize(
                nums1.begin(), m, nums2.begin(), n, (m + n) / 2 + 1, find_next);
        }
    }
};

int main (int argc, char *argv[])
{
    vector<int> v1 = {1, 3, 5, 7}, v2 = {2, 4, 6, 8, 10};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
