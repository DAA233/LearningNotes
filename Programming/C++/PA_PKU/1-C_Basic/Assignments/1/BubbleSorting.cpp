/**
 * 感性认识计算机程序  编程题 #1：实现冒泡排序
 *
 * @file: BubbleSorting.cpp
 * @description: 请根据自己的理解编写冒泡排序算法，数组大小1000以内
 * 样例输入
    50
    71 899 272 694 697 296 722 12 726 899 374 541 923 904 83 462 981 929 304
    550 59 860 963 516 647 607 590 157 351 753 455 349 79 634 368 992 401
    357 478 601 239 365 453 283 432 223 739 487 714 391
 * 样例输出
    12
    59
    71
    79
    83
    157
    223
    239
    272
    283
    296
    304
    349
    351
    357
    365
    368
    374
    391
    401
    432
    453
    455
    462
    478
    487
    516
    541
    550
    590
    601
    607
    634
    647
    694
    697
    714
    722
    726
    739
    753
    860
    899
    899
    904
    923
    929
    963
    981
    992
 * @author: PKU
 * @date: copied on Apr. 3rd, 2017
 */

#include <iostream>
using namespace std;

int main() {
    int n, a[1000]; // 一共n个数，n不超过1000。a用来保存这些数
    cin >> n;
    // 输入n个数
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    // 依次输出
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
