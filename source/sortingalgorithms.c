#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include<limits.h>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void printReadFile (Record *arr, int n) {
	int k;
	
	printf("\n\nARRAY IN THE FILE: \n");
	for (k = 0; k < n; k++)	{
		printf("\n%d %s",arr[k].idNumber, arr[k].name);
	}
}

/*
* Source: https://www.geeksforgeeks.org/how-to-empty-a-char-array-in-c/
*/
void resetRecord (Record *arr, int n) {
	int i;
	
	for(i = 0; i < n; i++) {
		arr[i].idNumber = 0;
		strcpy(arr[i].name, "\0");
	}
}


void insertionSort(Record *arr, int n) {
	
	int i, j, key;
	char tempName[50];
	
    for (i = 1; i < n; i++) {
        key = arr[i].idNumber;
        j = i - 1;
 
        while (j >= 0 && arr[j].idNumber > key) {
            arr[j + 1].idNumber = arr[j].idNumber;
            strcpy(tempName, arr[j + 1].name);
            strcpy(arr[j + 1].name, arr[j].name);
            strcpy(arr[j].name, tempName);

            j = j - 1;
        }
        arr[j + 1].idNumber = key;
    }
    
    //printing sorted array, for checking only
    /*printf("\n\n");
    for(i = 0; i < n; i++)
    {
    	printf("%d ", arr[i].idNumber);
    	printf("%s\n", arr[i].name);
	}*/
	
}

void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
	int i, j, minIndex;
	Record temp; 
	
	for(i = 0; i < n - 1; i++) {
		minIndex = i;
		
		for(j = i + 1; j < n; j++) {
			if(arr[j].idNumber < arr[minIndex].idNumber)  // && arr[j].name < arr[minIndex].name
			minIndex = j;
		}
		
		//swap the records
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp; 
		
	}
	
	//printing sorted array, for checking only
	/*printf("\n\n");
    for(int z = 0; z < n; z++)
    {
    	printf("%d ", arr[z].idNumber);
    	printf("%s\n", arr[z].name);
	}*/


}


void merge(Record *arr, int p, int q, int r) {
    int i, j, k;
    int size1 = q - p + 1;
    int size2 = r - q;
  
    Record* L = (Record*)malloc(size1 * sizeof(Record));
	Record* R = (Record*)malloc(size2 * sizeof(Record));

    for (i = 0; i < size1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < size2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < size1 && j < size2) {
        if (L[i].idNumber <= R[j].idNumber) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Record *arr, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
    }
    
}

/*
* For checking 
*
*/
void printMergeSortedArray (Record *arr, int n) {
	  
	//printing sorted array, optional
	printf("\n\n");
    for(int z = 0; z < n; z++)
    {
    	printf("%d ", arr[z].idNumber);
    	printf("%s\n", arr[z].name);
	}
   
}


/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/
int maxElem(Record arr[], int size) {
    int max = arr[0].idNumber;
    int i;
    
    for (i = 1; i < size; i++) {
        if (arr[i].idNumber > max)
            max = arr[i].idNumber;
    }
    return max;
}

void bucketSort(Record arr[], int n) {
    int max = maxElem(arr, n);
    Record *bucket = (Record *)malloc((max + 1) * sizeof(Record));
    int i;
    
 
    
    // Count the occurrences of each ID number
    for (i = 0; i < n; i++)
    {
    	bucket[arr[i].idNumber].idNumber++;
    	strcpy(bucket[arr[i].idNumber].name, arr[i].name);
	}
    
    // Copy the sorted elements back to the original array
    int index = 0;
    for (i = 0; i <= max; i++) {
        while (bucket[i].idNumber > 0) {
            arr[index].idNumber = i;
            strcpy(arr[index].name, bucket[i].name);
            index++;
            bucket[i].idNumber--;
        }
    }
    
    free(bucket); //deallocate the memory previously assigned to bucket
    
    //printing sorted array, for checking only
    /*printf("\n\n");
    for(int z = 0; z < n; z++)
    {
    	printf("%d ", arr[z].idNumber);
    	printf("%s\n", arr[z].name);
	}*/

}
#endif
