#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];

    for (int i = 0; i < 3; i++) {
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);

        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Gia: ");
        scanf("%f", &books[i].price);
        getchar(); 
    }

    printf("\n--- Danh sach cac cuon sach ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
        printf("--------------------------\n");
    }

    return 0;
}

