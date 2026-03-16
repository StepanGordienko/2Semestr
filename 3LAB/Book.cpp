#include "Book.hpp"

Bookmark::Bookmark() : color("Красный"), material("Бумага"), pageNumber(1) {}

Bookmark::Bookmark(const string& c, const string& m, int p)
    : color(c), material(m), pageNumber(p) {
}

Bookmark::Bookmark(const Bookmark& other)
    : color(other.color), material(other.material), pageNumber(other.pageNumber) {
}

Bookmark& Bookmark::operator++() {
    pageNumber++;
    return *this;
}

Bookmark Bookmark::operator++(int) {
    Bookmark temp = *this;
    pageNumber++;
    return temp;
}

Bookmark& Bookmark::operator--() {
    if (pageNumber > 1) pageNumber--;
    return *this;
}

Bookmark Bookmark::operator--(int) {
    Bookmark temp = *this;
    if (pageNumber > 1) pageNumber--;
    return temp;
}

void Bookmark::display() const {
    cout << "Флажок: " << color << ", " << material << ", стр. " << pageNumber << endl;
}

Book::Book() : author("Неизвестен"), title("Без названия"), pages(0),
rating(0.0), cost(0.0), bookmark(nullptr) {
    cout << "Конструктор книги по умолчанию вызван" << endl;
}

Book::Book(const string& auth, const string& titl, int p, double rate, double c, const vector<string>& w)
    : author(auth), title(titl), pages(p), rating(rate), cost(c), works(w), bookmark(nullptr) {
    cout << "Конструктор книги с параметрами вызван" << endl;
}

Book::Book(const Book& other)
    : author(other.author), title(other.title), pages(other.pages),
    rating(other.rating), cost(other.cost), works(other.works) {
    if (other.bookmark) {
        bookmark = new Bookmark(*other.bookmark);
    }
    else {
        bookmark = nullptr;
    }
    cout << "Конструктор копирования книги вызван" << endl;
}

Book::~Book() {
    delete bookmark;
    cout << "Деструктор книги вызван для: " << title << endl;
}

string Book::getAuthor() const { return author; }
string Book::getTitle() const { return title; }
int Book::getPages() const { return pages; }
double Book::getRating() const { return rating; }
double Book::getCost() const { return cost; }
vector<string> Book::getWorks() const { return works; }
Bookmark* Book::getBookmark() const { return bookmark; }

void Book::setAuthor(const string& auth) {
    if (!auth.empty()) author = auth;
}

void Book::setTitle(const string& titl) {
    if (!titl.empty()) title = titl;
}

void Book::setPages(int p) {
    if (p > 0) pages = p;
}

void Book::setRating(double r) {
    if (r >= 0 && r <= 5) rating = r;
}

void Book::setCost(double c) {
    if (c >= 0) cost = c;
}

void Book::setWorks(const vector<string>& w) {
    works = w;
}

void Book::setBookmark(Bookmark* bm) {
    delete bookmark;
    bookmark = bm;
}

void Book::ratePositive() {
    rating += 1.0;
    if (rating > 5.0) rating = 5.0;
}

void Book::rateNegative() {
    rating -= 1.0;
    if (rating < 0.0) rating = 0.0;
}

void Book::changeCost(double percent) {
    cost *= (1.0 + percent / 100.0);
}

void Book::display() const {
    cout << "Автор: " << author << endl;
    cout << "Название: " << title << endl;
    cout << "Страниц: " << pages << endl;
    cout << "Оценка: " <<  rating << endl;
    cout << "Стоимость: " <<  cost << " руб." << endl;
    cout << "Произведения: ";
    for (size_t i = 0; i < works.size(); i++) {
        cout << works[i];
        if (i < works.size() - 1) cout << ", ";
    }
    cout << endl;
    if (bookmark) {
        bookmark->display();
    }
}

Book Book::operator+(const Book& other) const {
    vector<string> newWorks = works;
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

    string newTitle = title + " + " + other.title;
    string newAuthor = (author == other.author) ? author : author + "/" + other.author;

    return Book(newAuthor, newTitle, pages + other.pages,
        (rating + other.rating) / 2, cost + other.cost, newWorks);
}

Book& Book::operator+=(const Book& other) {
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

    title = title + " + " + other.title;
    if (author != other.author) {
        author = author + "/" + other.author;
    }
    pages += other.pages;
    rating = (rating + other.rating) / 2;
    cost += other.cost;

    return *this;
}

Book Book::operator/(const Book& other) const {
    vector<string> newWorks;
    size_t half1 = works.size() / 2;
    size_t half2 = other.works.size() / 2;

    for (size_t i = 0; i < half1; i++) newWorks.push_back(works[i]);
    for (size_t i = 0; i < half2; i++) newWorks.push_back(other.works[i]);

    return Book(author, title + " (разделение)", pages + other.pages,
        rating, cost * 0.8, newWorks);
}