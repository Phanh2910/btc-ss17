#include<stdio.h>
#include<string.h> 
#include<ctype.h> 
void enter(char *word);
void show(char *word); 
int character(char *word);
int number(char *word);
int special(char *word);
int main(){
	int choose;
	char word[1000];
	int flag=-1; 
	int size=0;
	do{
		printf("\t MENU\n1.Nhap chuoi\n2.Hien thi chuoi\n3.Dem so luong chu cai va in ra\n4.dem so luong chu so va in ra\n5.dem so luong ki tu dac biet va in ra\n6.Thoat\nLua chon cua ban: ");
		scanf("%d",&choose);
		getchar(); 
		switch(choose){
		case 1:
			enter(word);
			flag=1; 
			break;
		case 2:
			if(flag!=1){
				printf("chuoi chua duoc nhap\n"); 
			}else{
				show(word);
			} 
			break;
		case 3:
			if(flag!=1){
				printf("chuoi chua duoc nhap\n"); 
			} else{
				character(word); 
			} 
			break;
		case 4:
			if(flag!=1){
				printf("chuoi chua duoc nhap\n"); 
			} else{
				number(word);	
			} 
			break;
		case 5:
			if(flag!=1){
				printf("chuoi chua duoc nhap\n"); 
			} else{
				special(word); 
			} 
			break;
		case 6:
			printf("thoat chuong trinh");
			break;
		default:
			printf("ko hop le\n");
		}
	}while(choose!=6);
	return 0;
}
void enter(char *word){
	printf("nhap chuoi bat ki:");
	fgets(word,1000,stdin);
}
void show(char *word){
	printf("%s",word);
}  
int character(char *word){
	int count=0; 
	for(int i=0;i<strlen(word);i++){
		if(isalpha(word[i])){
		count++; 
	} 
	}
	printf("so luong chu cai la %d\n",count);
	return count; 
} 
int number(char *word){
	int count=0; 
	for(int i=0;i<strlen(word);i++){
		if(isdigit(word[i])){
		count++; 
	} 
	}
	printf("so luong chu so la %d\n",count);
	return count; 
} 
int special(char *word){
	int count=0; 
	for(int i=0;i<strlen(word);i++){
		if(!isalpha(word[i]) && !isdigit(word[i]) ){
		count++; 
	} 
	}
	printf("so luong ki tu dac biet la %d\n",count);
	return count; 
}
