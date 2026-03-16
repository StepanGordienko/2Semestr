#include "Bookshelf.hpp"

Bookshelf::Bookshelf() : maxCapacity(10), currentCount(0) {
    books = new Book * [maxCapacity];
    for (int i = 0; i < maxCapacity; i++) books[i] = nullptr;
    cout << "Конструктор полки по умолчанию вызван" << endl;
}

Bookshelf::Bookshelf(int capacity) : maxCapacity(capacity), currentCount(0) {
    books = new Book * [maxCapacity];
    for (int i = 0; i < maxCapacity; i++) books[i] = nullptr;
    cout << "Конструктор полки с параметрами вызван" << endl;
}

Bookshelf::Bookshelf(const Bookshelf& other) : maxCapacity(other.maxCapacity), currentCount(other.currentCount) {
    books = new Book * [maxCapacity];
    for (int i = 0; i < maxCapacity; i++) {
        if (other.books[i]) {
            books[i] = new Book(*other.books[i]);
        }
        else {
            books[i] = nullptr;
        }
    }
    cout << "Конструктор копирования полки вызван" << endl;
}

Bookshelf::~Bookshelf() {
    for (int i = 0; i < maxCapacity; i++) {
        delete books[i];
    }
    delete[] books;
    cout << "Деструктор полки вызван" << endl;
}

bool Bookshelf::placeBook(Book* book) {
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

void Bookshelf::sortByTitle() {
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

void Bookshelf::display() const {
    cout << "Вместимость: " << maxCapacity << ", Книг: " << currentCount << endl;
    for (int i = 0; i < maxCapacity; i++) {
        if (books[i]) {
            cout << "Позиция " << i << ": \"" << books[i]->getTitle()
                << "\" - " << books[i]->getAuthor() << endl;
        }
    }
}

int Bookshelf::getCurrentCount() const { return currentCount; }
int Bookshelf::getMaxCapacity() const { return maxCapacity; }
Book* Bookshelf::getBookAt(int index) const {
    if (index >= 0 && index < maxCapacity) {
        return books[index];
    }
    return nullptr;
}