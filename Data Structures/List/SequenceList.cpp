//
// Created by 29546 on 2020/2/28.
//

#include <iostream>
#include <vector>

using namespace std;

//王道P18-综合题9
int BinarySearch(int *array, int length, int x){
    int h=0, r= length - 1,s=0;
    while(h + 1 != r){
        s= (h + r) / 2;
        if(array[s]==x){
            cout<<"find x in "<<s;
            return s;
        } else if(array[s] < x){
            h = s;
        }else {
            r = s;
        }
    }
    int *array1 = new int[length+1];
    for (int i=length; i >= h+1; i--){
        array1[i] = array[i-1];
    }
    array1[h+1] = x;
    for(int i = 0; i <= h; i++){
        array1[i] = array[i];
    }
//    cout<<"没有找到x，插入x后的新数组为：";
    for(int i=0; i <= length; i++){
        cout<<array1[i]<<' ';
    }
}

bool ReverseArray(int* &array, int length, int begin){
    for(int i=0; i<length/2; i++){
        int tmp=array[begin + i];
        array[begin + i] = array[begin + length - 1 - i];
        array[begin + length - i - 1] = tmp;
    }
    return true;
}

//王道P18-综合题8 & 10
void ArrayRotateLeft(int *array, int length, int n){
    if (length < n){
        cout<<"Illegal parameter....";
        return;
    }
    ReverseArray(array, length, 0);
    ReverseArray(array, length-n, 0);
    ReverseArray(array, n, length-n);
    for(int i = 0; i < length; i++){
        cout<<array[i]<<' ';
    }
}

/**
 * 王道P18-综合题11
 * 对于序列长为偶数时,中位数取后半段的第一个数.
 * @param array1
 * @param length1
 * @param array2
 * @param length2
 * @return
 */
int GetMedianOfTwoArray1(int *array1, int length1, int* array2, int length2){
    int cnt = 1, flag = 0, m = 0, n = 0, res = 0;
    int med = (length1+length2) / 2 + 1;

    cout<<"Array1: [";
    for(int i = 0; i<length1; i++){
        cout<<array1[i]<<',';
    }
    cout<<"]"<<endl;
    cout<<"Array2 [";
    for(int i = 0; i<length2; i++){
        cout<<array2[i]<<',';
    }
    cout<<"]"<<endl;

    while(cnt!= med){
        if(array1[m] <= array2[n]){
            flag = 2;
            if(m == length1 - 1){
                res = array2[n + med - cnt - 1];
                cout<<"Median is " << res << endl;
                return res;
            }
            m++;
        } else{
            flag = 1;
            if(n == length2 - 1){
                res = array1[m + med - cnt - 1];
                cout<<"Median is " << res << endl;
                return res;
            }
            n++;
        }
        cnt++;
    }
    if (flag == 1){
        res = array1[m];
        cout<<"Median is " << res << endl;
        return array1[m];
    } else{
        res = array2[m];
        cout<<"Median is " << res << endl;
        return res;
    }
}

/**
 * LeetCode 4
 * 对于序列长为偶数时,中位数取中间两数均值.
 * @param array1
 * @param length1
 * @param array2
 * @param length2
 * @return
 */
double GetMedianOfTwoArray2(int *array1, int length1, int* array2, int length2){
    int cnt = 1, flag = 0, m = 0, n = 0, odd = 1;
    double pre = 0.0, res = 0.0;
    int med = (length1+length2) / 2 + 1;

    cout<<"Array1: [";
    for(int i = 0; i<length1; i++){
        cout<<array1[i]<<',';
    }
    cout<<"]"<<endl;
    cout<<"Array2 [";
    for(int i = 0; i<length2; i++){
        cout<<array2[i]<<',';
    }
    cout<<"]"<<endl;

    if ((length1 + length2) % 2 == 0){
        odd = 0;
    }
    while(cnt!= med){
        if(array1[m] <= array2[n]){
            flag = 2;
            pre = array1[m];
            if(m == length1 - 1){
                if(odd){
                    pre = 0;
                    res = array2[n + med - cnt - 1];
                } else{
                    res = (array2[n + med - cnt - 1] + pre) / 2;
                }
                cout<<"Median is " << res << endl;
                return res;
            }
            m++;
        } else{
            flag = 1;
            pre = array2[n];
            if(n == length2 - 1){
                if(odd){
                    pre = 0;
                    res = array1[m + med - cnt - 1];
                } else {
                    res = (array1[m + med - cnt - 1] + pre) / 2;
                }
                cout<<"Median is " << res << endl;
                return res;
            }
            n++;
        }
        cnt++;
    }
    if (odd){
        pre = 0;
        if(flag == 1){
            res = array1[m];
            cout<<"Median is " << res << endl;
        }else{
            res = array2[n];
            cout<<"Median is " << res << endl;
        }
    } else{
        if (flag == 1){
            res = (pre + array1[m]) / 2;
            cout<<"Median is " << res << endl;
        } else{
            res = (pre + array2[m]) / 2;
            cout<<"Median is " << res << endl;
        }
    }
    return res;
}
//  0 1 1 2 3 4 5 5 6 7   7 8    8 9 10 11 12 14 18 21 22 25
int run() {
    int n = 6;
//    int array1[] = {1, 5, 7, 8, 14, 18, 21, 22, 25};
//    int array2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

//    int array1[] = {2};
//    int array2[] = {};
    int length1 = sizeof(array1) / sizeof(int);
    int length2 = sizeof(array2) / sizeof(int);
    //BinarySearch(array1, length1, 21);
    //ArrayRotateLeft(array2, length2, n); //将数组array1循环左移n位
    // GetMedianOfTwoArray1(array1, length1, array2, length2);
    GetMedianOfTwoArray2(array1, length1, array2, length2);
}
