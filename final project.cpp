#include <iostream>
#include <string>
#include <vector>
#include <fstream>//مكتبه للتعامل مع الملفات
using namespace std;

int main() {
    int your_choice;
    int Ar_borrowed_books;
    int En_borrowed_books;
    string username, password;
    bool login_success = false;//login وضع قيمه افتراضيه ل ال
    cout << "╔════════════════════════════════╗" << endl;
    cout << "║  📚 Welcome to the Library 📚  ║" << endl;
    cout << "╚════════════════════════════════╝" << endl;
    cout << "1. Sign in | 2. Sign up" << endl;
    cin >> your_choice;

    if (your_choice == 1) {
        //تسجيل الدخول 
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        ifstream file("users.txt"); //انشاء ملف 
        if (file.is_open()) { //التأكد من ان كان الملف مفتوح
            string stored_username, stored_password;
            while (file >> stored_username >> stored_password) {
                if (stored_username == username && stored_password == password) {
                    login_success = true;
                    break;
                }
            }
            file.close(); //اغلاق الملف بعد التعديل عليه

            if (login_success) {
                cout << "Login successful! Welcome to the library." << endl;
            } else {
                cout << "Invalid username or password!" << endl;
                return 0;  // الخروج مباشرة عند فشل تسجيل الدخول
            }
        } else {
            cout << "Failed to open the file 'users.txt'!" << endl;
            return 0;
        }
    } else if (your_choice == 2) {
        // Sign-up 
        cout << "Enter a new username: ";
        cin >> username;
        cout << "Enter a new password: ";
        cin >> password;

        ofstream file("users.txt", ios::app); //دالة الالحاق اكتب البيانات ف سطر جديد
        if (file.is_open()) {
            file << username << " " << password << endl;
            file.close();
            cout << "Account created successfully!" << endl;
            login_success = true; // السماح بالدخول بعد إنشاء الحساب
        } else {
            cout << "Failed to create or open the file 'users.txt'!" << endl;
            return 0;
        }
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    int choice, book;
    vector<string> English_books = {"The Push", "Bride Read", "The Hedge", "It", "The Coming of the Ice"};
    vector<string> Arabic_books = {"في قلبي انثى عبرية", "ارض زيكولا 1", "ارض زيكولا 2", "ارض زيكولا 3", "ما وراء الكواليس الدحيح"};
    vector<string> borrowed_books;

    cout << "1. English library" << endl;
    cout << "2. Arabic library" << endl;
    cout << "----------------------" << endl;
    cout << "Choose from the Menu" << endl;
    cout << "----------------------" << endl;
    cin >> choice;

    if (choice == 1) {
        
        
            cout << "Hello in English library" << endl;
            cout << "Choose from books:" << endl;
            cout << "1. " << English_books[0] << endl;
            cout << "2. " << English_books[1] << endl;
            cout << "3. " << English_books[2] << endl;
            cout << "4. " << English_books[3] << endl;
            cout << "5. " << English_books[4] << endl;
            cout << "6. Add a book" << endl;
            cout << "7. Delete a book" << endl;
            cout << "8. Borrow a book" << endl;
            cout << "9. Return a book" << endl;
            cout << "10. Back to main menu" << endl;
            cin >> book;
           do
           {
            switch (book) {
                case 1:
                    cout << "You chose: " << English_books[0] << endl;
                    cout << "Link to Read: https://www.readanybook.com/online/684299" << endl;
                    break;
                case 2:
                    cout << "You chose: " << English_books[1] << endl;
                    cout << "Link to Read: https://www.readanybook.com/online/765632#583144" << endl;
                    break;
                case 3:
                    cout << "You chose: " << English_books[2] << endl;
                    cout << "Link to Read: https://www.readanybook.com/online/765193#582482" << endl;
                    break;
                case 4:
                    cout << "You chose: " << English_books[3] << endl;
                    cout << "Link to Read: https://www.readanybook.com/ebook/it-book-565296" << endl;
                    break;
                case 5:
                    cout << "You chose: " << English_books[4] << endl;
                    cout << "Link to Read: https://www.readanybook.com/online/10556#9479" << endl;
                    break;
                case 6: {
                    string new_book;
                    cout << "Enter the name of the book to add: ";
                    getline(cin, new_book);
                    English_books.push_back(new_book);
                    cout << "Added: " << new_book << endl;
                    cout << "Updated book list:" << endl;
                    for (size_t i = 0; i < English_books.size(); ++i) {
                        cout << i + 1 << ". " << English_books[i] << endl;
                    }

                    break;
                }
                case 7: {
                    int delete_index;
                    cout << "Enter the number of the book to delete: ";
                    cin >> delete_index;
                    if (delete_index >= 1 && delete_index <= English_books.size()) {
                        cout << "Deleted: " << English_books[delete_index - 1] << endl;
                        English_books.erase(English_books.begin() + delete_index - 1);
                        cout << "Updated book list:" << endl;
                        for (const string& book : English_books) {
                            cout << book << endl;
                                              }

                    } else {
                        cout << "Invalid book number!" << endl;
                    }
                    break;
                }
                case 8: {
                    cout <<"number of box to borrow"<<endl;
                    cin >> En_borrowed_books;
                    cout << "borrowed" , En_borrowed_books;
                }
                break;
                case 9: {
                    int En_books_wants_to_return;
                    cout << "enter number of box to return"<<endl;
                    cin >> En_books_wants_to_return;
                    if (En_borrowed_books >= 1){
                    cout <<"The books has been returned";
                    cout <<"Remaining books :", En_borrowed_books - En_books_wants_to_return;
                    }
                    else
                    {
                      cout <<"No borrowed books to return!"<<endl;
                    }
                    
    
                }
                break;
                case 10:
                break;  // العودة للقائمة الرئيسية
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }        } while (book != 10);{while (true);}
        
    } else if (choice == 2) {
        do
        {
            cout << "Hello in Arabic library" << endl;
            cout << "Choose from books:" << endl;
            cout << "1. " << Arabic_books[0] << endl;
            cout << "2. " << Arabic_books[1] << endl;
            cout << "3. " << Arabic_books[2] << endl;
            cout << "4. " << Arabic_books[3] << endl;
            cout << "5. " << Arabic_books[4] << endl;
            cout << "6. Add a book" << endl;
            cout << "7. Delete a book" << endl;
            cout << "8. Borrow a book" << endl;
            cout << "9. Return a book" << endl;
            cout << "10. Back to main menu" << endl;
            cin >> book;
    
            switch (book) {
                case 1:
                    cout << "You chose: " << Arabic_books[0] << endl;
                    cout << "Link to Read: https://docs.google.com/viewerng/viewer?hl=ar&t=1&url=https://www.alarabimag.com/books/22459.pdf" << endl;
                    break;
                case 2:
                    cout << "You chose: " << Arabic_books[1] << endl;
                    cout << "Link to Read: https://docs.google.com/viewerng/viewer?hl=ar&t=8&url=https://www.alarabimag.com/books/22375.pdf" << endl;
                    break;
                case 3:
                    cout << "You chose: " << Arabic_books[2] << endl;
                    cout << "Link to Read: https://docs.google.com/viewerng/viewer?hl=ar&t=22&url=https://www.alarabimag.com/books/34834.pdf" << endl;
                    break;
                case 4:
                    cout << "You chose: " << Arabic_books[3] << endl;
                    cout << "Link to Read: https://archive.org/details/2_20240503_20240503_0905/1-%20%D8%A3%D8%B1%D8%B6%20%D8%B2%D9%8A%D9%83%D9%88%D9%84%D8%A7" << endl;
                    break;
                case 5:
                    cout << "You chose: " << Arabic_books[4] << endl;
                    cout << "Link to Read: https://kolalkotob.com/read/3141" << endl;
                    break;
                case 6: {
                    string new_book;
                    cout << "Enter the name of the book to add: ";
                    cin.ignore();
                    getline(cin, new_book);
                    Arabic_books.push_back(new_book);
                    cout << "Added: " << new_book << endl;
                    cout << "Updated book list:" << endl;
                   for (const string& book : Arabic_books) {
                   cout << book << endl;
                                           }

                    break;
                }
                case 7: {
                    int delete_index;
                    cout << "Enter the number of the book to delete: ";
                    cin >> delete_index;
                    if (delete_index >= 1 && delete_index <= Arabic_books.size()) {
                        cout << "Deleted: " << Arabic_books[delete_index - 1] << endl;
                        Arabic_books.erase(Arabic_books.begin() + delete_index - 1);
                        cout << "Updated book list:" << endl;
                   for (const string& book : Arabic_books) {
                    cout << book << endl;
                    }

                    } else {
                        cout << "Invalid book number!" << endl;
                    }
                    break;
                    case 8: {
                        cout <<"number of box to borrow"<<endl;
                        cin >> Ar_borrowed_books;
                        cout << "borrowed" , Ar_borrowed_books;
                    }
                    break;
                    case 9: {
                        int AR_books_wants_to_return;
                        cout << "enter number of box to return"<<endl;
                        cin >> AR_books_wants_to_return;
                        if (Ar_borrowed_books >= 1){
                        cout <<"Ar_borrowed_booksThe books has been returned";
                        cout <<"Remaining books :", Ar_borrowed_books - AR_books_wants_to_return;
                        }
                        case 10:
                            break;  // العودة للقائمة الرئيسية
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
    
            }
        }
        } while (book != 10);{while (true);}
 } 
 else {
        cout << "Invalid library!" << endl;    }

    return 0;
}

