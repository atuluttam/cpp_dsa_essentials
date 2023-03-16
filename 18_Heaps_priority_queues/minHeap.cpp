/*---------------------------------------------------------------------
 *                  code : minHeap   
 *               @author :  Atul Uttam     
 *          Date Created :  25-02-2023(17:56:38)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "Heap.hpp"
using namespace std;

int main(){

	int marks[] = {90,80,12,13,15,56,94};

	Heap minheap;

	for(int x:marks){
		minheap.push(x); //logn
	}

	while(!minheap.empty()){
		cout<< minheap.getMin() <<endl;
		minheap.pop(); //logn
	}
	return 0;
}
