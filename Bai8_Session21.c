#include <stdio.h>
#include <string.h>
#define MAX 100

struct Product {
    char id[20];
    char name[50];
    float importPrice;
    float sellPrice;
    int quantity;
};
float revenue = 0; 

void inputProducts(struct Product products[], int *n) {
    printf("Nhap so luong san pham: ");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin san pham %d:\n", i + 1);

        printf("Ma san pham: ");
        fgets(products[i].id, sizeof(products[i].id), stdin);
        products[i].id[strcspn(products[i].id, "\n")] = '\0';

        printf("Ten san pham: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("Gia nhap: ");
        scanf("%f", &products[i].importPrice);

        printf("Gia ban: ");
        scanf("%f", &products[i].sellPrice);

        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        getchar();

        revenue -= products[i].quantity * products[i].importPrice;
    }
}
void displayProducts(struct Product products[], int n) {
    printf("\n--- Danh sach san pham ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | %s | Gia nhap: %.2f | Gia ban: %.2f | SL: %d\n",
               i + 1, products[i].id, products[i].name,
               products[i].importPrice, products[i].sellPrice, products[i].quantity);
    }
}
void addProduct(struct Product products[], int *n) {
    struct Product newProduct;
    printf("\nNhap thong tin san pham moi:\n");

    printf("Ma san pham: ");
    fgets(newProduct.id, sizeof(newProduct.id), stdin);
    newProduct.id[strcspn(newProduct.id, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(products[i].id, newProduct.id) == 0) {
            printf("San pham da ton tai. Nhap so luong them: ");
            int addQty;
            scanf("%d", &addQty);
            getchar();
            products[i].quantity += addQty;
            revenue -= addQty * products[i].importPrice;
            return;
        }
    }
    printf("Ten san pham: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0';

    printf("Gia nhap: ");
    scanf("%f", &newProduct.importPrice);

    printf("Gia ban: ");
    scanf("%f", &newProduct.sellPrice);

    printf("So luong: ");
    scanf("%d", &newProduct.quantity);
    getchar();

    products[*n] = newProduct;
    (*n)++;

    revenue -= newProduct.quantity * newProduct.importPrice;
}
void updateProduct(struct Product products[], int n, char id[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Cap nhat thong tin san pham %s:\n", id);

            printf("Ten moi: ");
            fgets(products[i].name, sizeof(products[i].name), stdin);
            products[i].name[strcspn(products[i].name, "\n")] = '\0';

            printf("Gia nhap moi: ");
            scanf("%f", &products[i].importPrice);

            printf("Gia ban moi: ");
            scanf("%f", &products[i].sellPrice);

            printf("So luong moi: ");
            scanf("%d", &products[i].quantity);
            getchar();

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham co ma %s\n", id);
}
void sortProducts(struct Product products[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && products[i].sellPrice > products[j].sellPrice) ||
                (!ascending && products[i].sellPrice < products[j].sellPrice)) {
                struct Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia %s!\n", ascending ? "tang" : "giam");
}
void searchProduct(struct Product products[], int n, char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Tim thay: %s | %s | Gia nhap: %.2f | Gia ban: %.2f | SL: %d\n",
                   products[i].id, products[i].name,
                   products[i].importPrice, products[i].sellPrice, products[i].quantity);
            return;
        }
    }
    printf("Khong tim thay san pham co ten %s\n", name);
}
void sellProduct(struct Product products[], int n, char id[], int qty) {
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            if (products[i].quantity == 0) {
                printf("Het hang!\n");
                return;
            }
            if (qty > products[i].quantity) {
                printf("Khong con du hang!\n");
                return;
            }
            products[i].quantity -= qty;
            revenue += qty * products[i].sellPrice;
            printf("Ban thanh cong %d san pham %s\n", qty, products[i].name);
            return;
        }
    }
    printf("Khong tim thay san pham co ma %s\n", id);
}
int main() {
    struct Product products[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputProducts(products, &n);
                break;
            case 2:
                displayProducts(products, n);
                break;
            case 3:
                addProduct(products, &n);
                break;
            case 4: {
                char id[20];
                printf("Nhap ma san pham can cap nhat: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                updateProduct(products, n, id);
                break;
            }
            case 5: {
                int asc;
                printf("Nhap 1 de sap xep tang, 0 de giam: ");
                scanf("%d", &asc);
                getchar();
                sortProducts(products, n, asc);
                break;
            }
            case 6: {
                char name[50];
                printf("Nhap ten san pham can tim: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchProduct(products, n, name);
                break;
            }
            case 7: {
                char id[20];
                int qty;
                printf("Nhap ma san pham can ban: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                printf("Nhap so luong can ban: ");
                scanf("%d", &qty);
                getchar();
                sellProduct(products, n, id, qty);
                break;
            }
            case 8:
                printf("Doanh thu hien tai: %.2f\n", revenue);
        break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
           }
    } while (choice != 9);

    return 0;
} 
