/*
	Student info:
   	Name :- Manthan Sharma
   	Roll no :- 1906321
   	Branch :- Mathematics and Computer Science
   	Date of Submission :- 21.02.2021

	Summary:
   	This is a C++ program for implementation of Max Heap and Heap Sort. 
	In main method, we create a random array of length 20 and create a object of class maxHeap 
	and call heapsort function on that object.

	Result:
	In output we get an Sorted array
*/
#include <iostream> // Including nessesary libraries
#include <vector>
#include <algorithm>
#include <time.h>

/*
	This is maxHeap class used to implement Max Heap Data Structure
*/
class maxHeap
{
private:
	int *items;
	int size;

	void sift_down(int);	  //takes an index. Assume all the other items in the sub-tree rooted at the index satisfy the max-heap property. Swap items in the sub-tree rooted at the index, so that the sub-tree rooted at the index is a max-heap.
	void sift_up(int);		  //takes an index. Assume all the other items in the heap satisfy the max-heap property.  Swap items from the root to the index so that the tree satisfies the max-heap property.
	int find_parent(int);	  //Returns the index of the parent
	int find_lchild(int);	  //Returns the index of the left child
	int find_rchild(int);	  //Returns the index of the right child
	bool is_valid_index(int); // Returns the index is valid or not

public:
	void heapify(int *arr, int sz); //called by the constructor below to convert the arbitrary array items into a max-heap.
	int get_max();					//peeks into the max-heap and returns the maximum value
	void insert(int);				//inserts an element into the max heap
	int delete_max();				// returns the maximum value and deletes the item.
	maxHeap(int *arr, int sz)
	{
		//Constructor that takes an arbitrary array of size sz and creates a max-heap.
		heapify(arr, sz);
	}
};

void swap(int &a, int &b)
{ // function for swaping two elements
	int temp = a;
	a = b;
	b = temp;
}
/*
	Function Description:
    	This function converts the array into a max heap
    	Input type : int*,int
    	output type : void
*/
void maxHeap::heapify(int *arr, int sz)
{
	items = new int[sz]; // memory allocation for array
	size = 0;
	for (int i = 0; i < sz; ++i)
	{
		this->insert(arr[i]); // inserting elements into heap
	}
}
/*
	Function Description:
    	This function returns the index of parent
    	Input type : int
    	output type : int
*/
int maxHeap::find_parent(int idx)
{
	return (idx - 1) / 2;
}
/*
	Function Description:
    	This function returns the index of left child
    	Input type : int
    	output type : int
*/
int maxHeap::find_lchild(int idx)
{
	return 2 * idx + 1;
}
/*
	Function Description:
    	This function returns the index of Right child
    	Input type : int
    	output type : int
*/
int maxHeap::find_rchild(int idx)
{
	return 2 * idx + 2;
}
/*
	Function Description:
		This function set the element(of the given index) at the correct index according to max heap by shifting up (or comparing with parent)
    	Input type : int
    	output type : void
*/
void maxHeap::sift_up(int idx)
{
	int parIndex = find_parent(idx);
	if (idx == 0)
		return; // Base condition
	if (items[idx] > items[parIndex])
	{
		swap(items[idx], items[parIndex]);
		sift_up(parIndex); // Recursive step
	}
}
/*
	Function Description:
		This function set the element(of the given index) at the correct index according to max heap by shifting down (or comparing with right and left child)
    	Input type : int
    	output type : void
*/
void maxHeap::sift_down(int idx)
{
	int leftIndex = find_lchild(idx), rightIndex = find_rchild(idx);
	if (idx >= size)
		return;		 // Base condition
	int maxid = idx; // maxid is index which has greater child value(in terms of number)
	if (leftIndex < size && items[leftIndex] > items[maxid])
	{
		maxid = leftIndex;
	}
	if (rightIndex < size && items[rightIndex] > items[maxid])
	{
		maxid = rightIndex;
	}
	if (maxid != idx)
	{
		swap(items[maxid], items[idx]);
		sift_down(maxid); // Recursive step
	}
}
/*
	Function Description:
		This function returns the index is valid or not
    	Input type : int
    	output type : bool
*/
bool maxHeap::is_valid_index(int idx)
{
	return (idx >= 0 && idx < size);
}
/*
	Function Description:
		This function returns the maximum value 
    	Input type : none
    	output type : int
*/
int maxHeap::get_max()
{
	return items[0];
}
/*
	Function Description:
		This function returns the maximum value and deletes the item.
    	Input type : none
    	output type : int
*/
int maxHeap::delete_max()
{
	int mx_elm = items[0];
	swap(items[0], items[size - 1]);
	size--;
	sift_down(0);
	return mx_elm;
}
/*
	Function Description:
		This function insert the element in max heap data structure
    	Input type : int
    	output type : void
*/
void maxHeap::insert(int elm)
{
	items[size] = elm;
	sift_up(size);
	size++;
}
/*
	Function Description:
		This function sorts an input array using an object of maxHeap and print the sorted array
    	Input type : class maxHeap, int
    	output type : void
*/
void heapSort(maxHeap heap, int sz)
{
	std::vector<int> sortArray; // vector to store sorted array(sorted in reverse order)
	for (int i = 0; i < sz; ++i)
	{
		sortArray.push_back(heap.delete_max());
	}
	std::cout << "\nThe Sorted Array is: { ";
	for (int i = 0; i < sz; ++i)
	{
		std::cout << sortArray[sz - i - 1] << ", "; // print array in reverse order(for sorting in ascending order)
	}
	std::cout << " }\n";
}
int main()
{
	int sz = 20;
	int arr[sz];
	std::srand(time(0));
	for (int i = 0; i < sz; i++) // Creating Random array of size 20
		arr[i] = rand() % 1000000;

	std::cout << "\nThe Random Array is: { ";
	for (int i = 0; i < sz; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << " }\n";

	maxHeap Heap = maxHeap(arr, sz); // Creating an object of maxHeap (i.e. Heap)

	heapSort(Heap, sz); // Calling heapSort function

	return 0;
}