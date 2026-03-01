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






#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Bookmark {
    string color;
    string material;
    int pageNumber;

    Bookmark() : color("Red"), material("Paper"), pageNumber(1) {}

    Bookmark(const string& c, const string& m, int p)
        : color(c), material(m), pageNumber(p) {
    }

    Bookmark(const Bookmark& other)
        : color(other.color), material(other.material), pageNumber(other.pageNumber) {
    }


    Bookmark& operator++() {
        pageNumber++;
        return *this;
    }

    Bookmark operator++(int) {
        Bookmark temp = *this;
        pageNumber++;
        return temp;
    }

    Bookmark& operator--() {
        if (pageNumber > 1) pageNumber--;
        return *this;
    }

    Bookmark operator--(int) {
        Bookmark temp = *this;
        if (pageNumber > 1) pageNumber--;
        return temp;
    }

    void display() const {
        cout << "Bookmark: " << color << ", " << material << ", page " << pageNumber << endl;
    }
};

class Book {
private:
    string author;
    string title;
    int pages;
    double rating;
    double cost;
    vector<string> works;
    Bookmark* bookmark;

public:
    // Конструкторы
    Book() : author("Unknown"), title("Untitled"), pages(0), rating(0.0), cost(0.0), bookmark(nullptr) {
        cout << "Book default constructor called" << endl;
    }

    Book(const string& auth, const string& titl, int p, double rate, double c, const vector<string>& w)
        : author(auth), title(titl), pages(p), rating(rate), cost(c), works(w), bookmark(nullptr) {
        cout << "Book full constructor called" << endl;
    }

    Book(const Book& other)
        : author(other.author), title(other.title), pages(other.pages),
        rating(other.rating), cost(other.cost), works(other.works) {
        if (other.bookmark) {
            bookmark = new Bookmark(*other.bookmark);
        }
        else {
            bookmark = nullptr;
        }
        cout << "Book copy constructor called" << endl;
    }

    // Деструктор
    ~Book() {
        delete bookmark;
        cout << "Book destructor called for: " << title << endl;
    }

    // Геттеры
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    int getPages() const { return pages; }
    double getRating() const { return rating; }
    double getCost() const { return cost; }
    vector<string> getWorks() const { return works; }
    Bookmark* getBookmark() const { return bookmark; }

    // Сеттеры
    void setAuthor(const string& auth) {
        if (!auth.empty()) author = auth;
    }

    void setTitle(const string& titl) {
        if (!titl.empty()) title = titl;
    }

    void setPages(int p) {
        if (p > 0) pages = p;
    }

    void setRating(double r) {
        if (r >= 0 && r <= 5) rating = r;
    }

    void setCost(double c) {
        if (c >= 0) cost = c;
    }

    void setWorks(const vector<string>& w) {
        works = w;
    }

    void setBookmark(Bookmark* bm) {
        delete bookmark;
        bookmark = bm;
    }

    // Методы оценки
    void ratePositive() {
        rating += 1.0;
        if (rating > 5.0) rating = 5.0;
    }

    void rateNegative() {
        rating -= 1.0;
        if (rating < 0.0) rating = 0.0;
    }

    // Изменение стоимости
    void changeCost(double percent) {
        cost *= (1.0 + percent / 100.0);
    }

    // Вывод информации
    void display() const {
        cout << "\n=== Book Information ===" << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
        cout << "Rating: " << fixed << setprecision(1) << rating << endl;
        cout << "Cost: " << fixed << setprecision(2) << cost << endl;
        cout << "Works included: ";
        for (size_t i = 0; i < works.size(); i++) {
            cout << works[i];
            if (i < works.size() - 1) cout << ", ";
        }
        cout << endl;
        if (bookmark) {
            bookmark->display();
        }
    }

    // Операторы
    Book operator+(const Book& other) const {
        vector<string> newWorks;
        for (const auto& w : works) newWorks.push_back(w);
        for (const auto& w : other.works) {
            bool found = false;
            for (const auto& existing : newWorks) {
                if (existing == w) {
                    found = true;
                    break;
                }
            }
            if (!found) newWorks.push_back(w);
        }

        string newTitle = title + " & " + other.title;
        string newAuthor = (author == other.author) ? author : author + "/" + other.author;

        return Book(newAuthor, newTitle, pages + other.pages,
            (rating + other.rating) / 2, cost + other.cost, newWorks);
    }

    Book& operator+=(const Book& other) {
        for (const auto& w : other.works) {
            bool found = false;
            for (const auto& existing : works) {
                if (existing == w) {
                    found = true;
                    break;
                }
            }
            if (!found) works.push_back(w);
        }

        title = title + " & " + other.title;
        author = (author == other.author) ? author : author + "/" + other.author;
        pages += other.pages;
        rating = (rating + other.rating) / 2;
        cost += other.cost;

        return *this;
    }

    Book operator/(const Book& other) const {
        vector<string> newWorks;
        size_t half1 = works.size() / 2;
        size_t half2 = other.works.size() / 2;

        for (size_t i = 0; i < half1; i++) newWorks.push_back(works[i]);
        for (size_t i = 0; i < half2; i++) newWorks.push_back(other.works[i]);

        return Book(author, title + " (split)", pages + other.pages,
            rating, cost * 0.7, newWorks);
    }
};

#endif









#ifndef BOOKSHELF_HPP
#define BOOKSHELF_HPP

#include "Book.hpp"
#include <algorithm>

class Bookshelf {
private:
    Book** books;
    int maxCapacity;
    int currentCount;

public:

    Bookshelf() : maxCapacity(10), currentCount(0) {
        books = new Book * [maxCapacity];
        for (int i = 0; i < maxCapacity; i++) books[i] = nullptr;
        cout << "Bookshelf default constructor called" << endl;
    }

    Bookshelf(int capacity) : maxCapacity(capacity), currentCount(0) {
        books = new Book * [maxCapacity];
        for (int i = 0; i < maxCapacity; i++) books[i] = nullptr;
        cout << "Bookshelf parameter constructor called" << endl;
    }

    Bookshelf(const Bookshelf& other) : maxCapacity(other.maxCapacity), currentCount(other.currentCount) {
        books = new Book * [maxCapacity];
        for (int i = 0; i < maxCapacity; i++) {
            if (other.books[i]) {
                books[i] = new Book(*other.books[i]);
            }
            else {
                books[i] = nullptr;
            }
        }
        cout << "Bookshelf copy constructor called" << endl;
    }

    ~Bookshelf() {
        for (int i = 0; i < maxCapacity; i++) {
            delete books[i];
        }
        delete[] books;
        cout << "Bookshelf destructor called" << endl;
    }

    bool placeBook(Book* book) {
        if (currentCount >= maxCapacity || !book) {
            return false;
        }

        for (int i = 0; i < maxCapacity; i++) {
            if (!books[i]) {
                books[i] = book;
                currentCount++;
                return true;
            }
        }
        return false;
    }

    void sortByTitle() {
        Book** temp = new Book * [currentCount];
        int idx = 0;
        for (int i = 0; i < maxCapacity; i++) {
            if (books[i]) {
                temp[idx++] = books[i];
            }
        }

        for (int i = 0; i < currentCount - 1; i++) {
            for (int j = 0; j < currentCount - i - 1; j++) {
                if (temp[j]->getTitle() > temp[j + 1]->getTitle()) {
                    Book* swap = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = swap;
                }
            }
        }

        for (int i = 0; i < maxCapacity; i++) {
            books[i] = nullptr;
        }
        for (int i = 0; i < currentCount; i++) {
            books[i] = temp[i];
        }

        delete[] temp;
    }

    void display() const {
        cout << "\n=== Bookshelf Contents ===" << endl;
        cout << "Capacity: " << maxCapacity << ", Current: " << currentCount << endl;
        for (int i = 0; i < maxCapacity; i++) {
            if (books[i]) {
                cout << "Position " << i << ": " << books[i]->getTitle()
                    << " by " << books[i]->getAuthor() << endl;
            }
        }
    }

    // Геттеры
    int getCurrentCount() const { return currentCount; }
    int getMaxCapacity() const { return maxCapacity; }
    Book* getBookAt(int index) const {
        if (index >= 0 && index < maxCapacity) {
            return books[index];
        }
        return nullptr;
    }
};

#endif