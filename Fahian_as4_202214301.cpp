#include <iostream>
#include <string>
using namespace std;
struct Book {
    int isbn;
    std::string title;
    std::string author;
    double price;
    int quantity;

    Book(int isbn, const std::string& title, const std::string& author, double price, int quantity)
        : isbn(isbn), title(title), author(author), price(price), quantity(quantity) {}
};

struct Node {
    Book* book;
    Node* left;
    Node* right;

    Node(Book* book) : book(book), left(nullptr), right(nullptr) {}
};

class Bookstore {
private:
    Node* root;

    Node* insert(Node* node, Book* book) {
        if (node == nullptr) {
            return new Node(book);
        }

        if (book->isbn < node->book->isbn) {
            node->left = insert(node->left, book);
        } else if (book->isbn > node->book->isbn) {
            node->right = insert(node->right, book);
        } else {
            // ISBN already exists, update quantity
            node->book->quantity += book->quantity;
            delete book;
        }

        return node;
    }

    Node* remove(Node* node, int isbn) {
        if (node == nullptr) {
            return nullptr;
        }

        if (isbn < node->book->isbn) {
            node->left = remove(node->left, isbn);
        } else if (isbn > node->book->isbn) {
            node->right = remove(node->right, isbn);
        } else {
            if (node->left == nullptr) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                Node* successor = findMinNode(node->right);
                node->book = successor->book;
                node->right = remove(node->right, successor->book->isbn);
            }
        }

        return node;
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* search(Node* node, int isbn) {
        if (node == nullptr || node->book->isbn == isbn) {
            return node;
        }

        if (isbn < node->book->isbn) {
            return search(node->left, isbn);
        } else {
            return search(node->right, isbn);
        }
    }

    void displayInOrder(Node* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            displayBookDetails(node->book);
            displayInOrder(node->right);
        }
    }

    void displayBookDetails(const Book* book) {
        std::cout << "ISBN: " << book->isbn << std::endl;
        std::cout << "Title: " << book->title << std::endl;
        std::cout << "Author: " << book->author << std::endl;
        std::cout << "Price: " << book->price << std::endl;
        std::cout << "Quantity: " << book->quantity << std::endl;
        std::cout << std::endl;
    }

public:
    Bookstore() : root(nullptr) {}

    void addBook(Book* book) {
        root = insert(root, book);
    }

    void removeBook(int isbn) {
        root = remove(root, isbn);
    }

    void updateQuantity(int isbn, int newQuantity) {
        Node* node = search(root, isbn);
        if (node != nullptr) {
            node->book->quantity = newQuantity;
            std::cout << "Quantity updated successfully." << std::endl;
        } else {
            std::cout << "Book not found." << std::endl;
        }
    }

    void searchByISBN(int isbn) {
        Node* node = search(root, isbn);
        if (node != nullptr) {
            std::cout << "Book found:" << std::endl;
            displayBookDetails(node->book);
        } else {
            std::cout << "Book not found." << std::endl;
        }
    }

    void displayAllBooks() {
        std::cout << "Inventory:" << std::endl;
        displayInOrder(root);
    }
};

int main() {
    Bookstore bookstore;

    // Example usage
    bookstore.addBook(new Book(123456, "Book Title 1", "Author 1", 19.99, 5));
    bookstore.addBook(new Book(234567, "Book Title 2", "Author 2", 29.99, 3));
    bookstore.addBook(new Book(345678, "Book Title 3", "Author 3", 39.99, 7));
    bookstore.addBook(new Book(456789, "Book Title 4", "Author 4", 49.99, 2));

    bookstore.displayAllBooks();

    bookstore.searchByISBN(345678);

    bookstore.updateQuantity(234567, 10);

    bookstore.removeBook(123456);

    bookstore.displayAllBooks();

    return 0;
}

