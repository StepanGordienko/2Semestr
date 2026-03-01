#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BookCollection {
private:
    string author;
    string works[100];
    int worksCount;
    int pages;
    double cost;

public:
    
    BookCollection() : author("Неизвестно"), pages(0), cost(0.0), worksCount(0) {
        cout << "Вызван конструктор по умолчанию" << endl;
    }

    
    BookCollection(const BookCollection& other) : author(other.author), pages(other.pages),
        cost(other.cost), worksCount(other.worksCount) {
        for (int i = 0; i < worksCount; i++) {
            works[i] = other.works[i];
        }
        cout << "Вызван конструктор полного копирования" << endl;
    }

    
    BookCollection(const string& auth, const string w[], int count, int p, double c)
        : author(auth), pages(p), cost(c), worksCount(count) {
        for (int i = 0; i < count && i < 100; i++) {
            works[i] = w[i];
        }
        cout << "Вызван конструктор полного заполнения" << endl;
    }

    
    ~BookCollection() {
        cout << "Вызван деструктор" << endl;
    }

    
    string getAuthor() const { return author; }
    int getPages() const { return pages; }
    double getCost() const { return cost; }
    int getWorksCount() const { return worksCount; }

    
    string getWork(int index) const {
        if (index >= 0 && index < worksCount) {
            return works[index];
        }
        return "";
    }

    
    void setAuthor(const string& auth) {
        if (!auth.empty()) {
            author = auth;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    void setPages(int p) {
        if (p >= 0) {
            pages = p;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    void setCost(double c) {
        if (c >= 0) {
            cost = c;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    
    void addWork(const string& work) {
        if (worksCount < 100) {
            works[worksCount] = work;
            worksCount++;
        }
    }

    
    void changeCost(double percent) {
        cost = cost * (1.0 + percent / 100.0);
    }

    
    void displayInfo() const {
        cout << "Автор: " << author << endl;
        cout << "Работы: ";
        for (int i = 0; i < worksCount; i++) {
            cout << works[i];
            if (i < worksCount - 1) cout << ", ";
        }
        cout << endl;
        cout << "Страницы: " << pages << endl;
        cout << "Цена: " << fixed << setprecision(2) << cost << endl;
    }

    
    bool hasWork(const string& work) const {
        for (int i = 0; i < worksCount; i++) {
            if (works[i] == work) return true;
        }
        return false;
    }

    
    bool hasWorkWithAuthor(const string& workWithAuthor) const {
        for (int i = 0; i < worksCount; i++) {
            if ((author + works[i]) == workWithAuthor) return true;
        }
        return false;
    }

    
    BookCollection operator+(const BookCollection& other) const {
        BookCollection result;

        
        if (author == other.author) {
            result.author = author;
        }
        else {
            result.author = author + " и " + other.author;
        }

        
        result.pages = pages + other.pages;

        
        result.cost = (cost + other.cost) * 0.85;

        
        if (author == other.author) {
            for (int i = 0; i < worksCount; i++) {
                if (!result.hasWork(works[i])) {
                    result.works[result.worksCount] = works[i];
                    result.worksCount++;
                }
            }
            for (int i = 0; i < other.worksCount; i++) {
                if (!result.hasWork(other.works[i])) {
                    result.works[result.worksCount] = other.works[i];
                    result.worksCount++;
                }
            }
        }
        else {
            for (int i = 0; i < worksCount; i++) {
                string combined = author + works[i];
                if (!result.hasWorkWithAuthor(combined)) {
                    result.works[result.worksCount] = combined;
                    result.worksCount++;
                }
            }
            for (int i = 0; i < other.worksCount; i++) {
                string combined = other.author + other.works[i];
                if (!result.hasWorkWithAuthor(combined)) {
                    result.works[result.worksCount] = combined;
                    result.worksCount++;
                }
            }
        }

        return result;
    }

    BookCollection operator/(const BookCollection& other) const {
        BookCollection result;

        if (author == other.author) {
            result.author = author;
        }
        else {
            result.author = author + " и " + other.author;
        }

        result.pages = (pages + other.pages) * 70 / 100;

        result.cost = (cost + other.cost) * 1.10;

        int takeFromFirst = worksCount / 2;
        int takeFromSecond = other.worksCount / 2;

        if (author == other.author) {
            for (int i = 0; i < takeFromFirst; i++) {
                if (!result.hasWork(works[i])) {
                    result.works[result.worksCount] = works[i];
                    result.worksCount++;
                }
            }
            for (int i = 0; i < takeFromSecond; i++) {
                if (!result.hasWork(other.works[i])) {
                    result.works[result.worksCount] = other.works[i];
                    result.worksCount++;
                }
            }
        }
        else {
            for (int i = 0; i < takeFromFirst; i++) {
                string combined = author + works[i];
                if (!result.hasWorkWithAuthor(combined)) {
                    result.works[result.worksCount] = combined;
                    result.worksCount++;
                }
            }
            for (int i = 0; i < takeFromSecond; i++) {
                string combined = other.author + other.works[i];
                if (!result.hasWorkWithAuthor(combined)) {
                    result.works[result.worksCount] = combined;
                    result.worksCount++;
                }
            }
        }

        return result;
    }
};
