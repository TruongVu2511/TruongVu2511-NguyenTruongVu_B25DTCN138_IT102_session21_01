#include <stdio.h>
#include <string.h>
#define MAX 100

struct Book {
    char id[20];
    char title[50];
    char author[50];
    float price;
    char category[30];
};

void inputBooks(struct Book books[], int *n) {
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    getchar(); 

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);

        printf("Ma sach: ");
        fgets(books[i].id, sizeof(books[i].id), stdin);
        books[i].id[strcspn(books[i].id, "\n")] = '\0';

        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("The loai: ");
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void displayBooks(struct Book books[], int n) {
    printf("\n--- Danh sach sach ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | %s | %s | %.2f | %s\n",
               i + 1, books[i].id, books[i].title,
               books[i].author, books[i].price, books[i].category);
    }
}

void addBookAt(struct Book books[], int *n, int pos) {
    if (*n >= MAX || pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    struct Book newBook;
    getchar();
    printf("Nhap ma sach: ");
    fgets(newBook.id, sizeof(newBook.id), stdin);
    newBook.id[strcspn(newBook.id, "\n")] = '\0';

    printf("Nhap ten sach: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Nhap tac gia: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Nhap gia tien: ");
    scanf("%f", &newBook.price);
    getchar();

    printf("Nhap the loai: ");
    fgets(newBook.category, sizeof(newBook.category), stdin);
    newBook.category[strcspn(newBook.category, "\n")] = '\0';

    for (int i = *n; i > pos; i--) {
        books[i] = books[i - 1];
    }
    books[pos] = newBook;
    (*n)++;
}

void deleteBookById(struct Book books[], int *n, char id[]) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("Da xoa sach co ma %s\n", id);
            return;
        }
    }
    printf("Khong tim thay sach co ma %s\n", id);
}

void updateBookById(struct Book books[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Cap nhat thong tin sach co ma %s:\n", id);

            printf("Ten sach moi: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';

            printf("Tac gia moi: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';

            printf("Gia tien moi: ");
            scanf("%f", &books[i].price);
            getchar();

            printf("The loai moi: ");
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach co ma %s\n", id);
}

void sortBooksByPrice(struct Book books[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && books[i].price > books[j].price) ||
                (!ascending && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia %s!\n", ascending ? "tang" : "giam");
}
void searchBookByTitle(struct Book books[], int n, char title[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Tim thay: %s | %s | %s | %.2f | %s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].price, books[i].category);
            return;
        }
    }
    printf("Khong tim thay sach co ten %s\n", title);
}
int main() {
    struct Book books[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputBooks(books, &n);
                break;
            case 2:
                displayBooks(books, n);
                break;
            case 3: {
                int pos;
                printf("Nhap vi tri muon them (0-%d): ", n);
                scanf("%d", &pos);
                addBookAt(books, &n, pos);
                break;
            }
            case 4: {
                char id[20];
                printf("Nhap ma sach can xoa: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                deleteBookById(books, &n, id);
                break;
            }
            case 5: {
                char id[20];
                printf("Nhap ma sach can cap nhat: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                updateBookById(books, n, id);
                break;
            }
            case 6: {
                int asc;
                printf("Nhap 1 de sap xep tang, 0 de giam: ");
                scanf("%d", &asc);
                sortBooksByPrice(books, n, asc);
                break;
            }
            case 7: {
                char title[50];
                printf("Nhap ten sach can tim: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                searchBookByTitle(books, n, title);
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

