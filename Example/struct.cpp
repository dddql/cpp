#include <bits/stdc++.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

using namespace std;

/*指向结构的指针*/
void printBook(struct Books *book)
{
    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}

int main()
{
    struct Books Book1;
    struct Books Book2;

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* 输出 Book1 信息 */
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 Book_id : %d\n", Book1.book_id);

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    printf("\n");

    /* 输出 Book2 信息 */
    printBook(&Book2);

    return 0;
}