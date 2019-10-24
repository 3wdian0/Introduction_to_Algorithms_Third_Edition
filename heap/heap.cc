#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct _HEAP
{
	int length;   // 数组元素的长度
	int heap_size;// 堆元素个数
	vector<int> data;
};

int parent(int i){
	return floor(i/2);
}
int LEFT(int i){
	return i<<1;
}
int RIGHT(int i){
	return (i<<1)+1;
}
void MaxHeapify(_HEAP &A, int i){
	// 时间复杂度 O(lg n)
	
	/*
	 * 假定i的左右子树都是最大堆
	 * 如果不符合,会出现什么情况?
	*/
	int l = LEFT(i);
	int r = RIGHT(i);
	//cout<<"记录i="<<i<<" l="<<l<<" r="<<r<<endl;
	int largest=-1;
	if(l<A.heap_size and A.data[l]>A.data[i])
		largest = l;

      //if(r<A.heap_size and A.data[r]>A.data[i]) 错误; 导致可能取到第二大的值
	if(r<A.heap_size and A.data[r]>A.data[largest])
		largest = r;

	if(largest!=i and largest!=-1){
		//cout<<A.data[largest]<<" "<<A.data[i]<<endl;
		int tmp = A.data[largest]; A.data[largest] = A.data[i]; A.data[i] = tmp;
		cout<<A.data[largest]<<" "<<A.data[i]<<endl;
		MaxHeapify(A,largest);
	}
};
void BuildMaxHeap(_HEAP &A){
	A.heap_size = A.length;
	cout<<"长度"<<A.length<<endl;
	cout<<"长度"<<A.length/2<<endl;
	// 子数组A[floor(n/2)+1,...,n]都是叶子节点
	// 所以从A[floor(n/2)],非叶子节点开始建堆
	for(int i=floor(A.length/2); i>=0;i--){
		MaxHeapify(A,i);
	}
}
void HeapSort(_HEAP &A){
	BuildMaxHeap(A);
	int start = A.length - 1;
	int end   = 2; // 1、不计A[0]; 2、A[1]不用维护
	for(int i = start; i >= end; i--){
		int tmp = A.data[1]; A.data[1] = A.data[i]; A.data[i] = tmp;	
		A.heap_size = A.heap_size - 1;
		MaxHeapify(A,1);
	}
}
void _print(vector<int> A){
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
	A.length    = A.data.size();
	A.heap_size = A.data.size();

	_print(A.data);
	BuildMaxHeap(A);
	_print(A.data);
	HeapSort(A);
	_print(A.data);
	return 0;
}
