#include <stdio.h>

struct Car{
	char model[50];
	int year;
	int price;
};

int main(){
	struct Car myCar ={
		"lambogini",
		2023,
		100000
	};
	printf("Mau xe la : %s \n",myCar.model);
	printf("Nam san xuat la : %d\n",myCar.year);
	printf("Gia cua xe la : %d",myCar.price);
	
	return 0;
} 
