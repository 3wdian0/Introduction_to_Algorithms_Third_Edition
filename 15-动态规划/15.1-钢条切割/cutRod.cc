#include<iostream>
#include<vector>
#include<limits.h>

#define max(x,y) (x)>(y)?(x):(y);

using namespace std;

// 法一
int cutRod(vector<int> &p, int n){
    if(n==0)
        return 0;
    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        q = max(q, p[i-1]+cutRod(p, n - i));
    }
    return q;

}

// auxiliary
int memoizedCutRodAux(vector<int> &p, int n , vector<int> &r);

// main procedure
int memoizedCutRod(vector<int> &p, int n){
    vector<int> r;
    for(int i = 0; i < p.size(); i++){
        r.push_back(INT_MIN);
    }
    return memoizedCutRodAux(p,n,r);
}

int memoizedCutRodAux(vector<int> &p, int n , vector<int> &r){
    if(n==0)
        return 0;
    if(r[n-1]!=INT_MIN)
        return r[n-1];
    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        q = max(q, p[i-1]+memoizedCutRodAux(p,n - i,r) );
    }
    r[n-1] = q;
    return r[n-1];
}

int main(int argc, char *argv []){
    vector<int> p ;
    /*
     * lengthi   1 2 3 4 5  6  7  8  9  10 
     * pricepi   1 5 8 9 10 17 17 20 24 30
     */
    p.push_back(1); p.push_back(5); p.push_back(8); p.push_back(9); p.push_back(10);
    p.push_back(17);p.push_back(17);p.push_back(20);p.push_back(24);p.push_back(30);
    cout<<"法一"<< cutRod(p, 9) <<endl;
    cout<<"法二"<< memoizedCutRod(p, 9) <<endl;
    return 0;
}
