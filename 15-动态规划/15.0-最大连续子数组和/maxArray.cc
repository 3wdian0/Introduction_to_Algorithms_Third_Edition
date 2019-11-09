#include<iostream>
#include<limits.h>
#include<vector>

#define max(x,y) (x>y)?x:y;

using namespace std;

// 法一
int maxArray(vector<int> &p){
    /*
     * 算法思路 分析
     *  2, 4, -5, 9, 8, 3, -6
     *     4, -5, 9, 8, 3, -6
     * 在值4之前的某个连续子区间，有个最大值m，
     * 以及和4连续的区间也有个值sum.
     */
    int m = 0;
    int sum = 0;
    for(int i=0; i<p.size(); i++){
        if(sum+p[i]<0){
            // 中断在这里体现
            sum = 0;
        }
        else{
            sum += p[i];
        }
        m = max(m,sum);
    }
    return m;
}

// 法二
/*
 * dp[i] = max(p[i], dp[i-1]+p[i])
 * dp的前提，连续 
 * 此外，还需要一个最大值m
 */
int bottomUpMaxArray(vector<int> &p){
    vector<int> dp;
    for(int i = 0; i <= p.size(); i++){
        dp.push_back(0);
    }
    int m = 0;
    for(int i = 1; i<= p.size(); i++){
        dp[i] = max(p[i-1], dp[i-1]+p[i-1]); //中断在这里体现
        /*
         * 假设dp[i-1] = -5;
         *      p[i]   = 9;
         * 则  dp[i]   = 9;
         */
        m = max(m,dp[i]);
    }
    return m;
}
int main(int argc, char * argv []){
    vector<int> p;
    // 2, 4, -5, 9, 8, 3, -6
    p.push_back(2);p.push_back(4);p.push_back(-5);p.push_back(9);p.push_back(8);p.push_back(3);p.push_back(-6);
    cout<<maxArray(p)<<endl;

    p.clear();
    //    4, -5, 9, 8, 3, -6
    p.push_back(4);p.push_back(-5);p.push_back(9);p.push_back(8);p.push_back(3);p.push_back(-6);
    cout<<maxArray(p)<<endl;
    cout<<"法二:"<<bottomUpMaxArray(p)<<endl;
    return 0;
}
