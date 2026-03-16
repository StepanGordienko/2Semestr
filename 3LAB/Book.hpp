#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Bookmark {
    string color;
    string material;
    int pageNumber;

    Bookmark();
    Bookmark(const string& c, const string& m, int p);
    Bookmark(const Bookmark& other);

    Bookmark& operator++();
    Bookmark operator++(int);
    Bookmark& operator--();
    Bookmark operator--(int);

    void display() const;
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
    Book();
    Book(const string& auth, const string& titl, int p, double rate, double c, const vector<string>& w);
    Book(const Book& other);

    ~Book();

    string getAuthor() const;
    string getTitle() const;
    int getPages() const;
    double getRating() const;
    double getCost() const;
    vector<string> getWorks() const;
    Bookmark* getBookmark() const;

    void setAuthor(const string& auth);
    void setTitle(const string& titl);
    void setPages(int p);
    void setRating(double r);
    void setCost(double c);
    void setWorks(const vector<string>& w);
    void setBookmark(Bookmark* bm);

    void ratePositive();
    void rateNegative();

    void changeCost(double percent);

    void display() const;

    Book operator+(const Book& other) const;
    Book& operator+=(const Book& other);
    Book operator/(const Book& other) const;
};