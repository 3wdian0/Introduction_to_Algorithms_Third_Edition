#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


//  A = [3, 2, 1, 2, 3, 2]
int Partition(vector<int> &A, int p, int r){
	int x = A[r];
	int i =  p - 1;
	for(int j = p; j < r; j++){
		if(A[j]<x){
			++i;
			if(i!=j){
				int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
			}
		}
	}
	++i;
	int tmp = A[i]; A[i] = A[r]; A[r] = tmp;
	return i;
}




void QuickSort(vector<int> &A, int p, int r){
	if( p < r ){
		int q = Partition(A, p, r);
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
}

void _print(vector<int> A){
	for(int i =  0; i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main(int argc , char * argv[]) {
	cout<<"快速排序"<<endl;
	vector<int> A;
	A.push_back(3);A.push_back(2);A.push_back(1);A.push_back(2);A.push_back(3);A.push_back(2);
	cout<<"input :";
	_print(A);
	QuickSort(A,0, A.size()-1);
	cout<<"output:";
	_print(A);
	return 0;
}
