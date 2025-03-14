#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char arr[100];
    printf("Enter string: ");
    scanf(" %[^\n]", arr);
    int size = strlen(arr), k = 0;
    int i;
    printf("You entered: %s\n", arr);
    for(i = 0; i < size; i++){
        if(isalpha(arr[i])){
            arr[k++] = tolower(arr[i]);
        }
    }
    int check = 0;
    int x = 0, y = k - 1;
    printf("String \"");
    printf("%s", arr);
    for(i = 0; x <= y ; i++){
        if(arr[x++] != arr[y--]){
            check = 1;
        }
    }
    if(check == 1){
        printf("\" Not a Palindrome");
    } else {
        printf("\" Is a Palindrome");
    }
    
    return 0;
}
