#include<iostream>
#include<vector>

using namespace std;

int fibonacci(int n){
    if(n==0 || n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int fibRecursiveCore(vector<int> &num,int);

int fibRecursive(int n){
    vector<int> num;
    for(int i = 0; i <= n; i++){
        num.push_back(0);
    }
    return fibRecursiveCore(num,n);
}

int fibRecursiveCore(vector<int> &num,int n){
    if(n<0){
        throw "Division by zero condition!";
    }
    if(n==0 || n==1){
        num[n]=1;
        return num[n];
    }
    else{
        /*
        int t1=0,t2=0;
        if(num[n-1]==0)
            t1 = fibRecursiveCore(num, n-1);
        else
            t1 = num[n-1];
        if(num[n-2]==0)
            t2 = fibRecursiveCore(num, n-2);
        else
            t2 = num[n-2];
        num[n] = t1 + t2;
        */
        num[n] = (num[n-1]==0 ? fibRecursiveCore(num,n-1) : num[n-1]) + (num[n-2]==0 ? fibRecursiveCore(num,n-2):num[n-2]);
        return num[n];

    }

}

int fibIterative(int n){
    vector<int> num;
    for(int i=0; i<=n; i++){
        num.push_back(0);
    }
    num[0]=1;
    num[1]=1;
    for(int i=2;i<=n;i++){
        num[i]=num[i-1]+num[i-2];
    }
    return num[n];
}
int main(int argc, char * argv[]){
    // 1 1 2 3 5 8
    cout<<fibonacci(5)<<endl;
    cout<<fibRecursive(5)<<endl;
    cout<<fibIterative(5)<<endl;
    return 0;
}
