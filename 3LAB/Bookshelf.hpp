#include "Book.hpp"
#include <algorithm>

class Bookshelf {
private:
    Book** books;
    int maxCapacity;
    int currentCount;

public:
    Bookshelf();
    Bookshelf(int capacity);
    Bookshelf(const Bookshelf& other);

    ~Bookshelf();

    bool placeBook(Book* book);
    void sortByTitle();
    void display() const;

    int getCurrentCount() const;
    int getMaxCapacity() const;
    Book* getBookAt(int index) const;
};