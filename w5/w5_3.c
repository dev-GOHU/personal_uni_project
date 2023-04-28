#include<stdio.h>
#include<time.h>
#include"selectionSort.h"

void main(void){
	int arr1[]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	clock_t start;
	start = clock();
	sort(arr1, 10);
	double duration_clock = ((double)(clock()-start))/CLOCKS_PER_SEC;
	
	int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	time_t t;
	t = time(NULL);
	sort(arr2, 10);
	double duration_time = ((double)difftime(time(NULL),t));
	printf("duration_clock: %lf\nduration_time: %lf", duration_clock, duration_time);
}
