#include "Bookshelf.hpp"
#include <iostream>

using namespace std;

void rateLabWork() {
    cout << "\n========== LABORATORY WORK 3 EVALUATION ==========" << endl;
    cout << "Interest:     8/10 - Interesting to work with classes and libraries" << endl;
    cout << "Complexity:   7/10 - Moderate complexity with multiple files and integration" << endl;
    cout << "Completeness: 9/10 - Well-structured tasks covering various OOP concepts" << endl;
    cout << "Personal rating: 8/10 - Enjoyable and educational experience" << endl;
    cout << "==================================================\n" << endl;
}

int main() {
    cout << "=== TESTING BOOK CLASS ===" << endl;

    // Создание книг
    vector<string> works1 = { "War and Peace", "Anna Karenina" };
    vector<string> works2 = { "Crime and Punishment", "The Idiot" };
    vector<string> works3 = { "1984", "Animal Farm" };

    Book book1("Tolstoy", "War and Peace Collection", 1200, 4.5, 29.99, works1);
    Book book2("Dostoevsky", "Dostoevsky Collection", 800, 4.8, 24.99, works2);
    Book book3("Orwell", "Orwell Collection", 600, 4.7, 19.99, works3);

    // Добавление флажка
    Bookmark* bm = new Bookmark("Blue", "Plastic", 100);
    book1.setBookmark(bm);

    // Демонстрация методов книги
    cout << "\n--- Book 1 Info ---";
    book1.display();

    cout << "\n--- Testing rating methods ---";
    cout << "\nPositive rating:";
    book1.ratePositive();
    cout << " New rating: " << book1.getRating();

    cout << "\nNegative rating:";
    book1.rateNegative();
    cout << " New rating: " << book1.getRating();

    cout << "\n\n--- Testing cost change ---";
    cout << "\nOriginal cost: " << book1.getCost();
    book1.changeCost(10); // +10%
    cout << "\nAfter +10%: " << book1.getCost();

    // Тестирование операторов
    cout << "\n\n=== TESTING OPERATORS ===";
    cout << "\n\n--- Operator + ---";
    Book book4 = book1 + book2;
    book4.display();

    cout << "\n--- Operator += ---";
    Book book5 = book3;
    book5 += book2;
    book5.display();

    cout << "\n--- Operator / ---";
    Book book6 = book1 / book2;
    book6.display();

    // Тестирование полки
    cout << "\n=== TESTING BOOKSHELF CLASS ===";
    Bookshelf shelf(5);

    // Создаем копии книг для полки
    Book* shelfBook1 = new Book(book1);
    Book* shelfBook2 = new Book(book2);
    Book* shelfBook3 = new Book(book3);
    Book* shelfBook4 = new Book("Pushkin", "Eugene Onegin", 200, 4.6, 15.99, vector<string>{"Eugene Onegin"});
    Book* shelfBook5 = new Book("Lermontov", "A Hero of Our Time", 250, 4.4, 14.99, vector<string>{"A Hero of Our Time"});

    cout << "\n--- Placing books on shelf ---";
    shelf.placeBook(shelfBook1);
    shelf.placeBook(shelfBook2);
    shelf.placeBook(shelfBook3);
    shelf.placeBook(shelfBook4);
    shelf.placeBook(shelfBook5);

    shelf.display();

    cout << "\n--- Sorting books by title ---";
    shelf.sortByTitle();
    shelf.display();

    // Тестирование флажка
    cout << "\n=== TESTING BOOKMARK STRUCT ===";
    Bookmark bm2("Green", "Leather", 50);
    cout << "\nOriginal: ";
    bm2.display();

    ++bm2;
    cout << "After ++: ";
    bm2.display();

    bm2++;
    cout << "After ++ (postfix): ";
    bm2.display();

    --bm2;
    cout << "After --: ";
    bm2.display();

    // Оценка лабораторной работы
    rateLabWork();

    return 0;
}