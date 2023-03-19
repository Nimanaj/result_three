#include <stdio.h>
#include <stdlib.h>

int* two_sum(int* arr, int numm_size, int target, int return_size) {
	
	int* result = malloc(return_size * sizeof(int));;
	
	result[0] = 0;
	result[1] = 0;
	
	for(int i = 0; i < numm_size; i++) {
		for(int j = i + 1; j < numm_size; j++) {
			if(arr[i] + arr[j] == target) {
				result[0] = arr[i];
				result[1] = arr[j];
			} 
		}
	}
	
	
	return result;
}

void test_equal_i_arr(int* arr, int arr_length, int result){
	char same[] = "matches";
	char greater[] = "greater";
	char smaller[] = "smaller";
	
	int sum = 0;
	
	for(int i = 0; i < arr_length; i++){
		sum += arr[i];
	}
	
	if(sum == result){
		printf("The sum in the array %s.\n", same);
	} else {
		if(sum > result){
			printf("The sum in the array [%d] is %s then the expected value [%d].\n", sum, greater, result);
		}
		printf("The sum in the array [%d] is %s then the expected value [%d].\n", sum, smaller, result);
	}
}


int main() {
	
	int one_arr[] = {2, 7, 11, 15};
	int one_num_sise = 4;
	int one_target = 9;
	
	int two_arr[] = {3, 2, 4};
	int two_num_sise = 3;
	int two_target = 6;
	
	int three_arr[] = {1, 3, 5, 7, 9};
	int three_num_sise = 5;
	int three_target = 6;
	
	int return_size = 2;
	
	int* result = two_sum(one_arr, one_num_sise, one_target, return_size);
	test_equal_i_arr(result, return_size, one_target);
	free(result);

	result = two_sum(two_arr, two_num_sise, two_target, return_size);
	test_equal_i_arr(result, return_size, two_target);
	free(result);
	
	result = two_sum(three_arr, three_num_sise, three_target, return_size);
	test_equal_i_arr(result, return_size, three_target);
	free(result);
	
}