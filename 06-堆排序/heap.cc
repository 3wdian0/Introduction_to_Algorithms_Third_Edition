#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct _HEAP
{
	int length;      // 数组的长度
	int heap_size;   // 堆大小
	vector<int> data;
};

void MaxHeapify(_HEAP &A, int i){
	// 时间复杂度 O(lg n)
	
	/*
	 * 假定i的左右子树都是最大堆
	 * 如果不符合,会出现什么情况?
	*/
	int l = i*2;
	int r = i*2+1;
	int largest;
	if(l<=A.heap_size and A.data[l]>A.data[i])
		largest = l;
    else
        largest = i;

	if(r<=A.heap_size and A.data[r]>A.data[largest])
		largest = r;
	if(largest!=i){
		int tmp = A.data[largest]; A.data[largest] = A.data[i]; A.data[i] = tmp;
		MaxHeapify(A,largest);
	}
};
void BuildMaxHeap(_HEAP &A){
	A.heap_size = A.length;
	// 子数组A[floor(n/2)+1,...,n]都是叶子节点
	// 所以从A[floor(n/2)],非叶子节点开始建堆
	for(int i=floor(A.length/2); i>=1;i--){
		MaxHeapify(A,i);
	}
}
void HeapSort(_HEAP &A){
	BuildMaxHeap(A);
	for(int i = A.length; i >= 2; i--){
		int tmp = A.data[1]; A.data[1] = A.data[i]; A.data[i] = tmp;	
		A.heap_size = A.heap_size - 1;
		MaxHeapify(A,1);
	}
}
void _print(vector<int> A){
    cout<<"长度:"<<A.size()<<endl;
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;	
}

int main(){
	cout<<"开始"<<endl;
	_HEAP A;
	A.data.push_back(-1);
	// 注：树的根节点，是A[1]
	A.data.push_back(1);
	A.data.push_back(2);A.data.push_back(3);
	A.data.push_back(4);A.data.push_back(5);A.data.push_back(6);A.data.push_back(7);
	A.data.push_back(8);A.data.push_back(9);A.data.push_back(10);A.data.push_back(11);A.data.push_back(12);A.data.push_back(13);A.data.push_back(14);
	A.length    = A.data.size()-1; // A.length    = A.data.size() 如果length错误的话，堆内元素值会减1

	_print(A.data);
	BuildMaxHeap(A);
	_print(A.data);
	HeapSort(A);
	_print(A.data);
	return 0;
}
