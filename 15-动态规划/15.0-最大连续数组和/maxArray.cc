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
        if(sum+p[i]<0)
            sum = 0;
        else
            sum += p[i];
        m = max(m,sum);
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
    return 0;
}
