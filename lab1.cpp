#include <iostream>
#include <string>


using namespace std;

class Book {
private:
    string author;
    string title;
    int pages;
    double rating;
    double price;

public:
    Book() : author("Неизвестно"), title("Без названия"), pages(0),
        rating(0.0), price(0.0){
        cout << "Вызван конструктор по умолчанию" << endl;
    }

    Book(string a, string t, int p, double r, double pr)
        : author(a), title(t), pages(p), rating(r), price(pr){
        cout << "Вызван полного заполнения" << endl;
    }

    Book(const Book& other)
        : author(other.author), title(other.title), pages(other.pages),
        rating(other.rating), price(other.price){
        cout << "Вызван конструктор копирования" << endl;
    }

    ~Book() {
        cout << "Деструктор запущен для книги: " << title << endl;
    }

    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    int getPages() const { return pages; }
    double getRating() const { return rating; }
    double getPrice() const { return price; }


    void setRating(double newRating) {
        if (newRating >= 0.0 && newRating <= 10.0) {
            rating = newRating;
            cout << "Оценка изменена на: " << rating << "/10" << endl;
        }
        else {
            cout << "Недопустимое значение" << endl;
        }
    }

    void setAuthor(const string& a) {
        if (!a.empty() && a.length() >= 2) {
            author = a;
            cout << "Автор: " << author << endl;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    void setTitle(const string& t) {
        if (!t.empty()) {
            title = t;
            cout << "Название: " << title << endl;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    void setPages(int p) {
        if (p > 0) {
            pages = p;
            cout << "Количество страниц установлено: " << pages << endl;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }


    void setPrice(double p) {
        if (p >= 0) {
            price = p;
            cout << "Стоимость: " << price << " руб." << endl;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    void changePrice(double newPrice) {
        if (newPrice >= 0) {
            double oldPrice = price;
            price = newPrice;
            cout << "Стоимость:" << price << " руб." << endl;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

};

int main() {
    setlocale(LC_ALL, "Ru");
    int choice;
    Book book("Джордж Оруэлл", "1984", 328, 9.5, 450.0);

    do {
        cout << "1. Изменить оценку книги" << endl;
        cout << "2. Изменить стоимость книги" << endl;
        cout << "3. Показать все данные" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
                double newRating;
                cout << "Текущая оценка: " << book.getRating() << "/10" << endl;
                cout << "Введите новую оценку: ";
                cin >> newRating;
                book.setRating(newRating);
        }

        case 2: {
                double newPrice;
                cout << "Текущая стоимость: " << book.getPrice() << " руб." << endl;
                cout << "Введите новую стоимость: ";
                cin >> newPrice;
                book.changePrice(newPrice);
        }

        case 3: {
                cout << "Автор: " << book.getAuthor() << endl;
                cout << "Название: " << book.getTitle() << endl;
                cout << "Страниц: " << book.getPages() << endl;
                cout << "Оценка: " << book.getRating() << "/10" << endl;
                cout << "Стоимость: " << book.getPrice() << " руб." << endl;
        }

        case 0: {
            break;
        }

        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 0);

}