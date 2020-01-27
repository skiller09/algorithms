#include <iostream>
using namespace std;

int Parent(int x){
	return x/2;
}

int LChild(int x){
	return 2*x;
}

int RChild(int x){
	return 2*x+1;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Max_Heapify(int nodenum, int size, int* array){
	int i, child, last ;
	last = array[nodenum];
	for(i=nodenum;LChild(i) <= size; i=child){
                child = LChild(i);
                if(child != size && array[child+1] > array[child])
                        child++;
                if(last < array[child]) array[i] = array[child];
                else break;
        }
        array[i] = last;
}

int main(void){
	int array[105];
	int input, i, temp, k;

	cout<<"Input numbers to sort:"<<endl;

	for(i=1;;i++){
		cin>>input;
		if(input==-1) break;
		array[i] = input;
	}
	i--;

	for(k=Parent(i);k>0;k--) Max_Heapify(k,i,array);

	cout<<"\nResult:"<<endl;
	for(k=i;k>0;){
		cout<<array[1]<<" ";
		swap(&array[1],&array[k--]);
		Max_Heapify(1,k,array);
	}
	cout<<endl;
}
