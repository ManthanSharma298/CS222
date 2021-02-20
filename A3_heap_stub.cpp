#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class maxHeap{
private:
        vector<int>items;
        int size = 0;
        
        void sift_down(int);		//takes an index. Assume all the other items in the sub-tree rooted at the index satisfy the max-heap property. Swap items in the sub-tree rooted at the index, so that the sub-tree rooted at the index is a max-heap.
        void sift_up(int); 		//takes an index. Assume all the other items in the heap satisfy the max-heap property.  Swap items from the root to the index so that the tree satisfies the max-heap property.
        int find_parent(int);	//Returns the index of the parent
        int find_lchild(int);	//Returns the index of the left child
        int find_rchild(int);	//Returns the index of the right child
        bool is_valid_index(int);
public:
        void heapify(); //called by the constructor below to convert the arbitrary array items into a max-heap.
        int get_max (); //peeks into the max-heap and returns the maximum value
        void insert(int);	//inserts an element into the max heap
        int delete_max();	// returns the maximum value and deletes the item.

		maxHeap(int sz, int arr[]){
		//Constructor that takes an arbitrary array of size sz and creates a max-heap.
			size = sz;
			for(int i=0;i<sz;++i){
				items[i]=arr[i];
			}
		}
};

int maxHeap::find_parent(int idx){
	return (idx-1)/2;
}
int maxHeap::find_lchild(int idx){
	return 2*idx + 1;
}
int maxHeap::find_rchild(int idx){
	return 2*idx + 2;
}
void maxHeap::sift_up(int idx){
	if(!is_valid_index(idx)) return;
	if(idx == 0) return;
	if(items[idx] > items[find_parent(idx)]){
		swap(items[idx],items[find_parent(idx)]);
	}
	sift_up(find_parent(idx));
}
void maxHeap::sift_down(int idx){
	if(!is_valid_index(idx)) return;
	int temp_id;
	if(is_valid_index(find_lchild(idx)) && items[find_lchild(idx)] > items[idx]){
		temp_id = find_lchild(idx);
	}
	if(is_valid_index(find_rchild(idx)) && items[find_rchild(idx)] > items[idx]){
		temp_id = find_rchild(idx);
	}
	if(temp_id != idx){
		swap(items[temp_id],items[idx]);
		sift_down(temp_id);
	}
}
bool maxHeap::is_valid_index(int idx){
	return (idx>=0 && idx<size);
}	
int maxHeap::get_max(){
	return items[0];
}
int maxHeap::delete_max(){
	int mx_elm = items[0];
	swap(items[0],items[size-1]);
	size--;
	sift_down(0);
	return mx_elm;
}
void maxHeap::insert(int elm){
	if(size >= items.size()){
		items.push_back(0);
	}
	items[size] = elm;
	size++;
	sift_up(size-1);
}

int main(){
	int sz = 5;
	int arr[5] = {1,2,33,4,7};
	maxHeap* Heap = new maxHeap(sz,arr);
	cout<<Heap->get_max()<<"\n";

	return 0;
}