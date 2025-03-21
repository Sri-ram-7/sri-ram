#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book{
    char title[100];
    char author[50];
    int id;
};
void addBook(){
    struct Book b;
    FILE *file=fopen("library.txt","ab");
    if(!file){
        printf("Error.opening file!\n");
        return ;
    }
    printf("Enter Book ID:");
    scanf("%d",&b. id);
     printf("Enter Title:");
    scanf(" %[^\n]",b.title);
     printf("Enter Author:");
    scanf(" %[^\n]",b.author);
    fwrite(&b,sizeof(b),1,file);
    fclose(file);
    printf("Book added successfully!\n");
    }
    void displaybooks(){
        struct Book b;
        FILE *file=fopen("library.txt","rb");
    if(!file){
        printf("No books available!\n");
        return ;
    }
    printf("\n ID\tTitle\tAuthor\n");
    while(fread(&b,sizeof(b),1,file)){
        printf(" %d\t%s\t%s\n",b.id,b.title,b.author);
    }
    fclose(file);
    }
    int main(){
        int choice;
        while(1){
            printf("\n1.Add Book\n2.View Books\n3.Exit\nEnter choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: addBook();break;
                case 2: displaybooks();break;
                case 3:exit(0);
                default :printf("Invalid choice!\n");
            }
        }
        return 0;
    }
