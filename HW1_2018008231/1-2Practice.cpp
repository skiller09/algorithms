#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct nodestruct *node;
typedef struct HeapStruct *MinHeap;
struct nodestruct{
	int num;
	int xaddress;
	int yaddress;
};
struct HeapStruct{
	int size;
	node *list;
};

int Parent(int x){
	return x/2;
}

int LChild(int x){
	return 2*x;
}

int RChild(int x){
	return 2*x+1;
}

void swap(node* a, node* b){
	node temp;
	*a = *b;
	*b = temp;
}

MinHeap BuildHeap(int size, MinHeap H){
	H = new struct HeapStruct;
	H->list = new node[size+5];
	H->size = 0;
	return H;
}

void Min_Heapify(int nodenum, MinHeap H){
	int i, child;
	node last;
	last = H->list[nodenum];
	for(i=nodenum;LChild(i) <= H->size; i=child){
                child = LChild(i);
                if(child != H->size && H->list[child+1]->num < H->list[child]->num)
                        child++;
                if(last->num > H->list[child]->num) H->list[i] = H->list[child];
                else break;
        }
        H->list[i] = last;
}

void Insert(node X, MinHeap H){
	int i;
	node temp = new struct nodestruct;
	temp->num = X->num;
	temp->xaddress = X->xaddress;
	temp->yaddress = X->yaddress;
	for(i=++H->size;Parent(i)>0 && H->list[Parent(i)]->num>X->num ; i=Parent(i)){
		H->list[i] = H->list[Parent(i)];
	}
	H->list[i] = temp;
}

node Delete_Min(MinHeap H){
	node min = H->list[1];
	node last = H->list[H->size];
	swap(H->list[1],H->list[H->size--]);
	Min_Heapify(1,H);
	return min;
}

int main(void){
	int** array;
	MinHeap H;
	node N = new struct nodestruct;
	node tmp = new struct nodestruct;
	int input, i, j, cnt, temp, k, x, y;
	string buffer;

	ifstream in("input1-2.txt");
	if(!in.is_open()){
		cout<<"file not found"<<endl;
		return 0;
	}

	in>>input;
	array = new int*[input+5];
	H = BuildHeap(input,H);

	getline(in,buffer);
	for(i=0;i<input;i++){
		array[i] = new int[105];
		getline(in,buffer);
		istringstream row(buffer);
		for(j=1;row>>temp;j++) array[i][j]=temp;
		array[i][j] = -2; // end of the list
	}

	for(i=0;i<input;i++){
		N->num = array[i][1];
		N->xaddress = i;
		N->yaddress = 1;
		Insert(N,H);
		array[i][1] = -1;
	}

	cnt=0;
	while(cnt<input){
		tmp = Delete_Min(H);
		cout<<tmp->num<<" ";

		x = tmp->xaddress;
		y = tmp->yaddress;

		if(array[x][++y]==-2){ //end of the current line
			if(++cnt>=input) break;
			continue;
		}

		tmp->num = array[x][y];
		tmp->xaddress = x;
		tmp->yaddress = y;
		Insert(tmp,H);
		array[x][y] = -1;
	}
	
	while(H->size>0) cout<<Delete_Min(H)->num<<" ";
	cout<<endl;
}
