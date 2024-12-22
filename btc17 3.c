#include <stdio.h>
#include <string.h>
#include <ctype.h>
void enter(char *word);
void daoNguoc(char *word);
void count(char *word);
void up(char *word);
void compareAndShorter(char *word);
void append(char *word);

int main() {
    int choose;
    char word[1000];
    int flag = -1;

    do {
        printf("\tMENU\n");
        printf("1. Nhap chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap chuoi khac roi so sanh in ra cai ngan hon\n");
        printf("5. In hoa tat ca cac chu\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar(); 

        switch (choose) {
            case 1:
                enter(word);
                flag = 1;
                break;
            case 2:
                if (flag == -1) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    daoNguoc(word);
                }
                break;
            case 3:
                if (flag == -1) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    printf("So luong tu co trong chuoi: ");
                    count(word);
                }
                break;
            case 4:
                if (flag == -1) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    compareAndShorter(word);
                }
                break;
            case 5:
                if (flag == -1) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    printf("Chuoi in hoa: ");
                    up(word);
                }
                break;
            case 6:
                if (flag == -1) {
                    printf("Chuoi chua duoc nhap\n");
                } else {
                    append(word);
                }
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Khong hop le\n");
        }
    } while (choose != 7);

    return 0;
}
void enter(char *word) {
    printf("Nhap chuoi bat ki: ");
    fgets(word, 1000, stdin);
    word[strcspn(word, "\n")] = '\0'; 
}
void daoNguoc(char *word) {
    printf("Chuoi dao nguoc: ");
    int len = strlen(word);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}
void count(char *word) {
    int count = 0;
    int inWord = 0; 

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != ' ' && !inWord) {
            count++;
            inWord = 1;
        } else if (word[i] == ' ') {
            inWord = 0; 
        }
    }
    printf("%d\n", count);
}
void up(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
    printf("%s\n", word);
}
void compareAndShorter(char *word) {
    char newWord[1000];
    printf("Nhap chuoi khac: ");
    fgets(newWord, 1000, stdin);
    newWord[strcspn(newWord, "\n")] = '\0'; 
    if (strlen(word) < strlen(newWord)) {
        printf("Chuoi ngan hon: %s\n", word);
    } else {
        printf("Chuoi ngan hon: %s\n", newWord);
    }
}
void append(char *word) {
    char newWord[1000];
    printf("Nhap chuoi khac de them: ");
    fgets(newWord, 1000, stdin);
    newWord[strcspn(newWord, "\n")] = '\0'; 

    strcat(word, newWord); 
    printf("Chuoi sau khi them: %s\n", word);
}
