/*3. Book Inventory Management using Unions
"Problem Statement:"  
Create a "union" to store different types of books:  
- "Fiction" (title, author, price)  
- "Non-Fiction" (title, subject, price)  

Write a program to:  
1. Allow users to "enter details of multiple books".  
2. Display details of books based on their category.  

"Function Prototype:"  
    void addBooks();
    void displayBooks();


"Sample Test Case:"  
"Input:"  

Enter number of books: 2  
Book 1: Fiction - "Harry Potter", J.K. Rowling, $30  
Book 2: Non-Fiction - "Physics Fundamentals", Science, $25  

"Output:"  

Fiction Book: Harry Potter, Author: J.K. Rowling, Price: $30  
Non-Fiction Book: Physics Fundamentals, Subject: Science, Price: $25  



struct Book_t {
    int type;
    union {
        struct {
            char title[250];
            char author[125];
            float price;
        } fiction;
        struct {
            char title[250];
            char subject[500];
            float price;
        } nonFiction;
    } booktype;
};*/

#include<stdio.h>
struct Fiction_t { //383
    char title[250];
    char author[125];
    float price;
}; 
typedef struct Fiction_t Fiction;

struct NonFiction_t { //758
    char title[250];
    char subject[500];
    float price;
}; 
typedef struct NonFiction_t NonFiction;

union BookType_t {
    Fiction fiction;
    NonFiction nonFiction;
};

typedef union BookType_t BookType;

struct Book_t {
    int type;
    BookType booktype;
};

typedef struct Book_t Book;

Book books[1000];
int bookCount;

void readBooks();
void displayBooks();

int main() {
    readBooks();
    displayBooks();
    return 0;
}

void readBooks() {
    printf("Enter number of books:");
    scanf("%d", &bookCount);

    for(int i = 0; i < bookCount; i++) {
        printf("Type of book(1-Fiction, 2-Non fiction):");
        scanf("%d", &books[i].type);

        switch(books[i].type) {
            case 1 : {
                printf("Enter Fiction Book Details(Title, Author, Price):");
                scanf("%s%s%f", books[i].booktype.fiction.title,
                        books[i].booktype.fiction.author,
                        &books[i].booktype.fiction.price);
            } break;
            case 2 : {
                printf("Enter Non Fiction Book Details(Title, Subject, Price):");
                scanf("%s%s%f", books[i].booktype.nonFiction.title,
                        books[i].booktype.nonFiction.subject,
                        &books[i].booktype.nonFiction.price);
            } break;
        }
    }
}
void displayBooks() {
    for(int i = 0; i < bookCount; i++) {
        switch(books[i].type) {
            case 1 : {
                printf("Fiction Book: %s, Author: %s, Price: $%.2f\n", books[i].booktype.fiction.title,
                                                books[i].booktype.fiction.author,
                                                books[i].booktype.fiction.price);
            } break;
            case 2 : {
                printf("Non-Fiction Book: %s, Subject: %s, Price: $%.2f\n", books[i].booktype.nonFiction.title,
                    books[i].booktype.nonFiction.subject,
                    books[i].booktype.nonFiction.price);
            } break;
        }
    }
}