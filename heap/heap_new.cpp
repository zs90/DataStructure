//Heap is an array from 0 to len-1

//When building a heap, we just filter down all the elements beginning from the last non-leaf node
void BuildHeap(int a[], int len){
	for(int i = (len - 2)/2; i > 0; i--){
		AjustDown(a, i, len);
	}
}

void AdjustDown(int a[], int k, int len){
	int key = a[k];  // storing the elements filtered down
	
	for(int i = 2*k + 1; i < len; i = i * 2 + 1){
		// compare left and right child to get the smaller one
		if( i + 1 < len && a[i] < a[i + 1]){
			i++;		 
			
		// if key is larger than the smallest children. move up that child
		// then make k points to that child 
		if(a[i] < key){
			a[k] = a[i];
			k = i;
		}
		else{ // else we stop filtering down
			break;
		}
	}
	
	// Now, whatever the case jumping out of the loop, map the key value to the final place
	a[k] = key;
}

void HeapSort(int a[], int len){
	// build heap
	BuildHeap(a, len);
	
	// swap the top of heap with the last one of heap
	// then adjust down the top of heap to maintain it property, now the length should decrease by one
	for(int i = len - 1; i > 0 ; i--){
		swap(a, i, 0);
		AdjustDown(a, 0, len - 1);
	}
}