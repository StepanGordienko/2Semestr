#include "Bookshelf.cpp"
#include <iostream>

using namespace std;

void rateLabWork() {
    cout << "Интерес:         10/10" << endl;
    cout << "Сложность:       10/10" << endl;
    cout << "Наполненность:   10/10" << endl;
    cout << "Личная оценка:   10/10" << endl;
}

int main() {
    vector<string> works1 = { "Война и мир. Том 1", "Война и мир. Том 2" };
    vector<string> works2 = { "Преступление и наказание", "Идиот" };
    vector<string> works3 = { "1984", "Скотный двор" };

    Book book1("Лев Толстой", "Война и мир", 1200, 4.5, 2999.99, works1);
    Book book2("Федор Достоевский", "Преступление и наказание", 800, 4.8, 2499.99, works2);
    Book book3("Джордж Оруэлл", "1984", 600, 4.7, 1999.99, works3);

    Bookmark* bm = new Bookmark("Синий", "Пластик", 100);
    book1.setBookmark(bm);


    book1.display();

    book1.ratePositive();
    cout << " Новая оценка: " << book1.getRating();

    book1.rateNegative();
    cout << " Новая оценка: " << book1.getRating();

    cout << "\nИсходная стоимость: " << book1.getCost() << " руб.";
    book1.changeCost(10);
    cout << "\nНовая стоимость: " << book1.getCost() << " руб.";

    Book book4 = book1 + book2;
    book4.display();

    Book book5 = book3;
    book5 += book2;
    book5.display();

    Book book6 = book1 / book2;
    book6.display();

    Bookshelf shelf(5);

    Book* shelfBook1 = new Book(book1);
    Book* shelfBook2 = new Book(book2);
    Book* shelfBook3 = new Book(book3);
    Book* shelfBook4 = new Book("Александр Пушкин", "Евгений Онегин", 200, 4.6, 1599.99,
        vector<string>{"Евгений Онегин"});
    Book* shelfBook5 = new Book("Михаил Лермонтов", "Герой нашего времени", 250, 4.4, 1499.99,
        vector<string>{"Герой нашего времени"});

    shelf.placeBook(shelfBook1);
    shelf.placeBook(shelfBook2);
    shelf.placeBook(shelfBook3);
    shelf.placeBook(shelfBook4);
    shelf.placeBook(shelfBook5);

    shelf.display();

    shelf.sortByTitle();
    shelf.display();

    Bookmark bm2("Зеленый", "Кожа", 50);
    cout << "\nИсходный: ";
    bm2.display();

    ++bm2;
    cout << "После ++: ";
    bm2.display();

    bm2++;
    cout << "После ++ (постфикс): ";
    bm2.display();

    --bm2;
    cout << "После --: ";
    bm2.display();

    rateLabWork();

    return 0;
}