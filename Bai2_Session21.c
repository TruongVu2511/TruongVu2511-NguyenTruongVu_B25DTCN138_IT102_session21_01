#include <stdio.h>
#include <string.h>

struct Student{
	char name[50];
	int age;
	float grade;
};

int main(){
	struct Student student1;
	
	printf("Nhap ten : ");
	fgets(student1.name,50,stdin);
	student1.name[strcspn(student1.name, "\n")] = '\0';
	
	printf("Nhap tuoi :");
	scanf("%d",&student1.age);
	getchar();
	
	printf("Nhap diem trung binh :");
	scanf("%f",&student1.grade);
	getchar();
	
	printf("Ten la : %s\n",student1.name);
	printf("Tuoi la : %d\n",student1.age);
	printf("Diem trung binh la : %.2f",student1.grade);
	
	
	
	return 0;
};
