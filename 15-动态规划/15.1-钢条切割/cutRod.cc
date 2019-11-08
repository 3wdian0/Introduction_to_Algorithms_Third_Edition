#include<iostream>
#include<vector>
#include<limits.h>

#define max(x,y) (x)>(y)?(x):(y);

using namespace std;


int cutRod(vector<int> &p, int n){
    if(n==0)
        return 0;
    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        q = max(q, p[i-1]+cutRod(p, n - i));
    }
    return q;

}

int main(int argc, char *argv []){
    vector<int> p ;
    /*
     * lengthi   1 2 3 4 5  6  7  8  9  10 
     * pricepi   1 5 8 9 10 17 17 20 24 30
     */
    p.push_back(1); p.push_back(5); p.push_back(8); p.push_back(9); p.push_back(10);
    p.push_back(17);p.push_back(17);p.push_back(20);p.push_back(24);p.push_back(30);
    cout<< cutRod(p, 9) <<endl;
    return 0;
}
