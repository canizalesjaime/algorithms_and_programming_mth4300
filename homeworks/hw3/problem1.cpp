#include <iostream>
#include <string>

using namespace std;
class Book {
    private:
    std::string title_;
    std::string author_;
    int year_;
    double price_;

    public:
    Book(string& bookTitle, string& bookAuthor, int publishedYear=1900, double bookPrice=0.0) : title_(bookTitle), author_(bookAuthor), year_(publishedYear), price_(bookPrice) {
    }
    void applyDiscount(double& discountPercentage) {
        price_ *= (1 - discountPercentage / 100);
    }
    void getBookInfo() const {
        cout << "Title: " << title_ << ", Author: " << author_ << ", Year: " << year_ << ", Price: " << price_ << endl;
    }
};
int main() {
    string bookName = "The Great Gatsby";
    string bookAuthor = "F. Scott Fitzgerald";
    Book book(bookName, bookAuthor, 1925, 15.99);
    double discountPercentage = 10.0;
    book.applyDiscount(discountPercentage);
    book.getBookInfo();
    return 0;
}