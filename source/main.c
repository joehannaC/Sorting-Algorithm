#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
* Store filename in the variable "path"
* n represents the number of elements in the chosen file
*
*/
int main()
{
    Record *record = (Record*)malloc(100000*sizeof(Record)); //initialization of record
    int flag = 0, n = 0; //to be increment later
    FILE *fp;
	int opt; //choice of the user
    char path[500]; //where filename will be stored
    char prefix[] = "data/";
    char suffix[] = ".txt"; 
    char filename[500];
    long start_Time, end_Time, execution_Time;
    int p, r;
    
	/*
    * Source:  https://l.facebook.com/l.php?u=https%3A%2F%2Fstackoverflow.com%2Fquestions%2F2795382%2Fenter-custom-file-name-to-be-read%3Ffbclid%3DIwAR3gQVN4Iu8HiFsvDlzl-
	* Dy7rEb5s3XqQM0W7POotli1AONsBlriJFb-Sls&h=AT1U7bG32gmNIVLMVzI5Eda9KlB42-iJuD9WQ525bDZy_IIsoydMUK3kFwgOW-GX14yjJTlP9J5fY8uLXbo7QyKEuehNuCozqSG6CL6N4FjyE9_Nb2ioO5Ia9lo6X
	* 5srXpwCtNqyJsJAp0Iq8KjXzA 
    * limit to 3 tries of inputting filename
    */
    
    do{
    	printf("Enter the filename you want to sort: ");
    	scanf("%s", path);
		strcpy(filename, prefix); //stores prefix to filename
		strcat(filename, path); //filename + path
    	strcat(filename, suffix); //filename + suffix
    	strcpy(path, filename); //copies the newly formed name from variable filename to path
    	
    	fp = fopen(path, "r");
    	
    	if(fp == NULL){
    		printf("\nFile not found.\n\n");
    		flag++;
    		if(flag == 3){
    			printf("\nSorry but you have no attempts left. Please restart the program.");
    			return 0;
			}		
		}
			else
			printf("\nFile found and successfully open.\n");
	
	fclose(fp);		
	}while(fp == NULL);
	
	readFile(record, path);  //implementation of reading and storing the contents of the file
	

	//increments the value of n as long as the content of the file is not empty
    while (record[n].idNumber != NULL) {
		n++;
	}
	
	//printReadFile(record,n); for checking only
	
	//checks if the memory allocation for record is successful or not
	if(record == NULL) {
		printf("\nFailed to allocate memory for the array.\n");
	}
	
	do {
		printf("\n\nSelect a sorting agorithm that you want to sort your file: ");
		printf("\n\n[1] Insertion Sort \n[2] Selection Sort \n[3] Merge Sort \n[4] Bucket Sort \n[5] Exit");
		printf("\n\nSelected option: ");
		scanf("%d", &opt); 
		printf("\n-------------------------------------");
	
		if(opt == 1) {
			printf("\n\nINSERTION SORT");
			start_Time = currentTimeMillis();
			insertionSort(record, n);
			end_Time = currentTimeMillis();
			printf("\n\n-------------------------------------");
			execution_Time = end_Time - start_Time;
			printf("\n\nExecution time (Insertion Sort): %ld ms\n", execution_Time);
			printf("\n\n-------------------------------------");
		} 
			else if(opt == 2) {
				printf("\n\nSELECTION SORT");
				start_Time = currentTimeMillis();
    			selectionSort(record, n);
    			end_Time = currentTimeMillis();
    			printf("\n\n-------------------------------------");
				execution_Time = end_Time - start_Time; 
				printf("\n\nExecution time (Selection Sort): %ld ms\n", execution_Time);
				printf("\n\n-------------------------------------");
			}
				else if(opt == 3) {
					printf("\n\nMERGE SORT");
						start_Time = currentTimeMillis();
						mergeSort(record,0, n - 1);
						//printMergeSortedArray(record, n); for checking only.
						end_Time = currentTimeMillis();
						printf("\n\n-------------------------------------");
						execution_Time = end_Time - start_Time;
						printf("\n\nExecution time (Merge Sort): %ld ms\n", execution_Time);
						printf("\n\n-------------------------------------");
				}
					else if(opt == 4) {
						printf("\n\nBUCKET SORT");
						start_Time = currentTimeMillis();
						bucketSort(record, n);
						end_Time = currentTimeMillis();
						printf("\n\n-------------------------------------");
						execution_Time = end_Time - start_Time;
						printf("\n\nExecution time (Bucket Sort): %ld ms\n", execution_Time);
						printf("\n\n-------------------------------------");
					}
						else if(opt == 5) {
							printf("\n- End Program -");
							return 0;
						}
							else if (opt < 0 || opt > 5){
								printf("\n\nInvalid input!");
								return 0;
							}
							
		if(opt < 5 && opt > 0) {
			resetRecord(record,n);
			readFile(record, path);
			//printReadFile(record,n); for checking only. 
		}		
		
 } while(opt > 1 || opt < 5);
    return 0;
}
