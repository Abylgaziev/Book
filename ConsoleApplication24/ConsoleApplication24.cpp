#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(std::string t, std::string a,int y):title(t),author(a),year(y){}
};

class HomeLibrary {
private:
    std::vector<Book> books;

public:
    void addBook(std::string title, std::string author, int year) {
        Book newBook(title, author, year);
        books.push_back(newBook);
    }

    void removeBook(std::string title) {
        books.erase(std::remove_if(books.begin(), books.end(), [&](const Book& b) {
            return b.title == title;
            }), books.end());
    }

    std::vector<Book> searchByAuthor(std::string author) {
        std::vector<Book> result;
        for (const Book& book : books) {
            if (book.author == author) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::vector<Book> searchByYear(int year) {
        std::vector<Book> result;
        for (const Book& book : books) {
            if (book.year == year) {
                result.push_back(book);
            }
        }
        return result;
    }

    void sortByTitle() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.title < b.title;
            });
    }

    void sortByAuthor() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
            });
    }

    void sortByYear() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.year < b.year;
            });
    }
};

int main() {
    setlocale(LC_ALL, "");
    HomeLibrary myLibrary;

    myLibrary.addBook("Великий Гэтсби", "F. Скотт Фицджеральд", 1925);
    myLibrary.addBook("Убить пересмешника", "Харпер Ли", 1960);
    myLibrary.addBook("1984", "Джордж Оруэлл", 1949);

    myLibrary.sortByYear();

    std::vector<Book> result = myLibrary.searchByAuthor("Харпер Ли");
    for (const Book& book : result) {
        std::cout << "Заголовок: " << book.title << ", Автор: " << book.author << ", Год: " << book.year << std::endl;
    }

    return 0;
}