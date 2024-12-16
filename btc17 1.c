#include <stdio.h>
void nhapmang(int arr[], int *n, int kichThuocToiDa);
void hienthimang(int arr[], int n);
int sum(int arr[], int n);
int timphantulonnhat(int arr[], int n);
int main() {
    int arr[100];
    int n = 0;
    int luaChon;
    int kichThuocToiDa = sizeof(arr) / sizeof(arr[0]); 
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapmang(arr, &n, kichThuocToiDa);
                break;
            case 2:
                if (n > 0) {
                    hienthimang(arr, n);
                } else {
                    printf("Mang chua duoc khoi tao hoac rong!\n");
                }
                break;
            case 3:
                printf("Do dai cua mang: %d\n", n);
                break;
            case 4:
                if (n > 0) {
                    printf("Tong cac phan tu trong mang: %d\n", sum(arr, n));
                } else {
                    printf("Mang chua duoc khoi tao hoac rong!\n");
                }
                break;
            case 5:
                if (n > 0) {
                    printf("Phan tu lon nhat trong mang: %d\n", timphantulonnhat(arr, n));
                } else {
                    printf("Mang chua duoc khoi tao hoac rong!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 6);
    return 0;
}
void nhapmang(int arr[], int *n, int kichThuocToiDa) {
    do {
        printf("Nhap so phan tu cua mang (1 - %d): ", kichThuocToiDa);
        scanf("%d", n);
        if (*n <= 0 || *n > kichThuocToiDa) {
            printf("So phan tu khong hop le. Vui long thu lai!\n");
        }
    } while (*n <= 0 || *n > kichThuocToiDa);

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void hienthimang(int arr[], int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int sum(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}
int timphantulonnhat(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
