// Q6) Define a structure Book with fields title, author, and price. Input details for n books and 
// then display all books whose price is above a given value. 
#include<stdio.h>
#include<string.h>
struct book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    int n, i;
    float priceLimit;
    printf("Enter number of books: ");
    scanf("%d", &n);
    struct book books[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %s", books[i].title);
        printf("Author: ");
        scanf(" %s", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("Enter price limit: ");
    scanf("%f", &priceLimit);

    printf("Books with price above %.2f:\n", priceLimit);
    for (i = 0; i < n; i++) {
        if (books[i].price > priceLimit) {
            printf("Title: %s, Author: %s, Price: %.2f\n", books[i].title, books[i].author, books[i].price);
        }
    }

    return 0;
}