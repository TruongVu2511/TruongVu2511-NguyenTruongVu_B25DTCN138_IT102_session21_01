#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[5];
    float totalValue = 0;

    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin san pham %d:\n", i + 1);

        printf("Ten san pham: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("Gia: ");
        scanf("%f", &products[i].price);

        printf("So luong: ");
        scanf("%d", &products[i].quantity);

        getchar();

        totalValue += products[i].price * products[i].quantity;
    }

    printf("\nTong gia tri cua tat ca san pham: %.2f\n", totalValue);

    return 0;
}

