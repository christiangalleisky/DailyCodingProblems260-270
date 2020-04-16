/*
This code snipet takes an array and orders it with respect to a character
array that tells the adjacent number to be either larger or smaller 
than the preceding number in the array.
*/
//Christian Galleisky
//12-16-2019


#include <iostream>

int* arrangeNums(int nums[], int lengthOfNums, char plus_minus[],
					int lengthOfPlusMinus) {
	int plusTotal = 0;
	for (int i = 0; i < lengthOfPlusMinus; i++) {
		if (plus_minus[i] == '+')
			plusTotal++;
	}
	int startNum = lengthOfNums - plusTotal - 1;
	int* finalProduct = new int[lengthOfNums];
	int positiveNum = startNum;
	int negativeNum = startNum;
	finalProduct[0] = startNum;
	for (int i = 1; i < lengthOfNums; i++) {
		if (plus_minus[i] == '+') {
			positiveNum++;
			finalProduct[i] = positiveNum;
		}
		else if (plus_minus[i] == '-') {
			negativeNum--;
			finalProduct[i] = negativeNum;
		}
	}

	return finalProduct;
}

int main() {
	char chars[] = { 'n','+','+','-','+','+','-','+','+' };
	int nums[] = { 0,1,2,3,4,5,6,7,8 };
	int* finalProduct = arrangeNums(nums, 9, chars, 9);
	int size = sizeof(finalProduct) / sizeof(int);
	for (int i = 0; i < 9; i++) 
		std::cout << *(finalProduct+i) << std::endl;
	std::cout << size << std::endl;
	system("PAUSE");

	return 0;
}