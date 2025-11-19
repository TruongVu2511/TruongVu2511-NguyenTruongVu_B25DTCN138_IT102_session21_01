#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
}; 
void searchStudent(struct Student students[], int size, char targetName[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            printf("\nTim thay hoc sinh:\n");
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("Diem trung binh: %.2f\n", students[i].grade);
            return;
        }
    }
    printf("\nKhong tim thay hoc sinh co ten '%s'\n", targetName);
}
int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin hoc sinh %d:\n", i + 1);

        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Tuoi: ");
        scanf("%d", &students[i].age);

        printf("Diem trung binh: ");
        scanf("%f", &students[i].grade);

        getchar(); 
    }
    char searchName[50];
    printf("\nNhap ten hoc sinh can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    searchStudent(students, 5, searchName);

    return 0;
}

