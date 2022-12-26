#include <stdio.h>
#include <string.h>

void shift_right(int *arr, int i){
    while(i > 0){
        *(arr+i) = *(arr+i-1);
        i--;
    }
}
void insertion_sort(int* arr , int len){
    for(int i =1 ; i < len ; i++){
        int temp = *(arr+i);

        int j = i -1;
        while(j>=0 && *(arr+j) > temp){
            j--;
        }
        //memcpy(arr+j+1,arr+j,sizeof(int)*(i-j));
        shift_right(arr+j+1,i-j-1);
        *(arr+j+1) = temp;
    }
}
int main() {
	int arr[50] = {0};
	for(int i = 0 ; i < 50 ; i++){
	int temp = 0;
	scanf("%d",&temp);
	arr[i] = temp;
	}
	insertion_sort(arr,sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i < 50 ; i++){
	if(i == 49){
	printf("%d\n",arr[i]);
	break;
	}
	printf("%d,",arr[i]);
	}
	return 0;
	}
