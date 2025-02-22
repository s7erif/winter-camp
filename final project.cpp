
/*Latest updates  
1- from line 83 to 90 وضع الروابط في فيكتور 
2- line 95 اضافة خيار جديد في القائمه 
3- from line 103 to 114 تحسين شكل قائمة العرض ووضع الكتب داخل قائمه 
4- from 116 to 134 تطبيق التعديل رقم 3 عبر وضع الكتب ف قائمة فيو ووضعها ف الحاله الاولي 
5-from 134 to 135 عرض الروابط من الفيكتور بتاعها 
6- from 160 to 182 علشان يضيف اللينكات الجديده ف الفيكتور  push_back هسأل اليوزر عاوز يضيف لينك ولا لا ولو الاجابه كانت ايوه هستخدم نفس دالة  
------------------------------------------------------------------------------------------------------------------------------------------------------
التعديلات ال جايه هطبق ف المكتبه العربيه نفس ال حصل ف المكتبه الانجليزيه 
هعرب الخيارات بالكامل ف المكتبه العربيه 
بس بعد م اخلص واجب الماث 
                                                 ❤️I will wait for your feedback❤️
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // مكتبه للتعامل مع الملفات

using namespace std;

int main() {
    int your_choice;
    int Ar_borrowed_books = 0; 
    int En_borrowed_books = 0; 
    string username, password;
    bool login_success = false; // login وضع قيمه افتراضيه ل ال

    cout << "*****************************************" << endl;
    cout << "*                                       *" << endl;
    cout << "*   📖✨ WELCOME TO THE LIBRARY ✨📖   *" << endl;
    cout << "*                                       *" << endl;
    cout << "*****************************************" << endl;

    cout << "1. Sign in | 2. Sign up" << endl;
    cin >> your_choice;

    if (your_choice == 1) {
        // تسجيل الدخول
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        ifstream file("users.txt"); // انشاء ملف للقراءة
        if (file.is_open()) { // التأكد من ان كان الملف مفتوح
            string stored_username, stored_password;
            while (file >> stored_username >> stored_password) {
                if (stored_username == username && stored_password == password) {
                    login_success = true;
                    break;
                }
            }
            file.close(); // اغلاق الملف بعد القراءة

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

        ofstream file("users.txt", ios::app); // دالة الالحاق اكتب البيانات ف سطر جديد
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
    //**vector<string> borrowed_books;
 /*--------------------------------------------------------------------------------------------------------------------------------------------------*/ 
    vector<string> En_book_links = {
        "https://www.readanybook.com/online/684299",
        "https://www.readanybook.com/online/765632#583144",//فيكتور جديد نشيل فيه اللينكات
        "https://www.readanybook.com/online/765193#582482",
        "https://www.readanybook.com/ebook/it-book-565296",
        "https://www.readanybook.com/online/10556#9479"};
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    do { // الحلقة  للقائمة الرئيسية
        cout << "\nMain Menu" << endl;
        cout << "1. English library" << endl;
        cout << "2. Arabic library" << endl;
        cout << "3. Exit" << endl; //اوبشن جديد
        cout << "----------------------" << endl;
        cout << "Choose from the Menu (1-3)" << endl;
        cout << "----------------------" << endl;
        cin >> choice;

        if (choice == 1) {
            do {
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
                cout << "\nEnglish Library Menu" << endl;
                cout << "1. View Books" << endl;//EDIT
                cout << "2. Add a book" << endl;
                cout << "3. Delete a book" << endl;
                cout << "4. Borrow a book" << endl;
                cout << "5. Return a book" << endl;
                cout << "6. Back to main menu" << endl;
                cout << "----------------------" << endl;
                cout << "Choose an action (1-6):" << endl;//EDIT
                cout << "----------------------" << endl;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------- */
                cin >> book;

                switch (book) {
                    case 1: {
                        cout << "\nAvailable English Books:" << endl;
                        if (English_books.empty()) {//لو مفيش كتب قوله
                            cout << "No books available in English library." << endl;
                        } else {
                            for (size_t i = 0; i < English_books.size(); i++) {
                                cout << i + 1 << ". " << English_books[i] << endl;
                            }

                            int book_choice;
                            cout << "Enter the number of the book to view details (or 0 to cancel): ";//EDIT
                            cin >> book_choice;
                            if (book_choice > 0 && book_choice <= English_books.size()) {//لو كان الاختيار اكبر من صفر وجوا نطاق الكتب طلعله الكتب ال ب العدد ال هو اختاره ناقص واحد علشان بادئين من صفر 
                                cout << "You chose: " << English_books[book_choice - 1] << endl;
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
                                if (book_choice <= En_book_links.size()) { //EDIT
                                    cout << "Link to Read: " << En_book_links[book_choice - 1] << endl;
                                } else {
                                    cout << "No available link for this book." << endl;
                                }
                            } else if (book_choice == 0) {
                                cout << "Canceled." << endl;
                            } else {
                                cout << "Invalid choice!" << endl;
                            }
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
                        }
                        break;
                    }
                    case 2: { // Add a book
                        string new_book;
                        cout << "Enter the name of the book to add: ";
                        cin.ignore();
                        getline(cin, new_book);
                        English_books.push_back(new_book);
                        cout << "Added: " << new_book << endl;
                        cout << "Updated English book list:" << endl;
                        for (size_t i = 0; i < English_books.size(); ++i) {
                            cout << i + 1 << ". " << English_books[i] << endl;}
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
                            string link;
                            char add_link_chose;
                            cout <<"Do you want to add a link for this book? (y/n): "<<endl;
                            cin >> add_link_chose;
                            if (add_link_chose == 'y')
                            cin >> link;
                            En_book_links.push_back(link);
                            cout << "Added: " << link << endl;
                            cout << "Updated English book links:" << endl;
                            for (size_t i = 0; i < En_book_links.size(); ++i) {                                //edit
                                cout << i + 1 << ". " << En_book_links[i] << endl;
                            }
                            
                            if  (add_link_chose == 'y'){
                                cout <<"Thanks , The Book Adedd";
                            }
                            else {
                                cout << "Invalid choice!" << endl;

                            }
                        break;
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
                        }
                    case 3: { // Delete a book
                        if (English_books.empty()) {
                            cout << "No books available to delete in English library." << endl;
                        } else {
                            int delete_index;
                            cout << "Enter the number of the book to delete: ";
                            cin >> delete_index;
                            if (delete_index >= 1 && delete_index <= English_books.size()) {
                                cout << "Deleted: " << English_books[delete_index - 1] << endl;
                                English_books.erase(English_books.begin() + delete_index - 1);
                                cout << "Updated English book list:" << endl;
                                for (size_t i = 0; i < English_books.size(); ++i) {
                                    cout << i + 1 << ". " << English_books[i] << endl;
                                }
                            } else {
                                cout << "Invalid book number!" << endl;
                            }
                        }
                        break;
                    }
                    case 4: { // Borrow a book
                        int borrow_count;
                        cout << "Enter the number of books to borrow: ";
                        cin >> borrow_count;
                        if (borrow_count > 0) {
                            En_borrowed_books += borrow_count;
                            cout << "Borrowed " << borrow_count << " English book(s)." << endl;
                            cout << "Total borrowed English books: " << En_borrowed_books << endl;
                        } else {
                            cout << "Invalid number of books to borrow." << endl;
                        }
                        break;
                    }
                    case 5: { // Return a book
                        int return_count;
                        cout << "Enter the number of books to return: ";
                        cin >> return_count;
                        if (return_count > 0) {
                            if (return_count <= En_borrowed_books) {
                                En_borrowed_books -= return_count;
                                cout << "Returned " << return_count << " English book(s)." << endl;
                                cout << "Remaining borrowed English books: " << En_borrowed_books << endl;
                            } else {
                                cout << "You are trying to return more books than borrowed!" << endl;
                                cout << "Currently borrowed: " << En_borrowed_books << " books." << endl;
                            }
                        } else {
                            cout << "Invalid number of books to return." << endl;
                        }
                        break;
                    }
                    case 6: // Back to main menu
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
            } while (book != 6);

        } else if (choice == 2) {
            do {
                cout << "\nArabic Library Menu" << endl;
                cout << "1. View Books" << endl;
                cout << "2. Add a book" << endl;
                cout << "3. Delete a book" << endl;
                cout << "4. Borrow a book" << endl;
                cout << "5. Return a book" << endl;
                cout << "6. Back to main menu" << endl;
                cout << "----------------------" << endl;
                cout << "Choose an action (1-6):" << endl;
                cout << "----------------------" << endl;
                cin >> book;

                switch (book) {
                    /*case 1: { //sooooooooooooooon 
                        }
                        break;
                    }*/
                    case 2: { // Add a book
                        string new_book;
                        cout << "Enter the name of the book to add: ";
                        cin.ignore();
                        getline(cin, new_book);
                        Arabic_books.push_back(new_book);
                        cout << "Added: " << new_book << endl;
                        cout << "Updated Arabic book list:" << endl;
                        for (size_t i = 0; i < Arabic_books.size(); ++i) {
                            cout << i + 1 << ". " << Arabic_books[i] << endl;
                        }
                        break;
                    }
                    case 3: { // Delete a book
                        if (Arabic_books.empty()) {
                            cout << "No books available to delete in Arabic library." << endl;
                        } else {
                            int delete_index;
                            cout << "Enter the number of the book to delete: ";
                            cin >> delete_index;
                            if (delete_index >= 1 && delete_index <= Arabic_books.size()) {
                                cout << "Deleted: " << Arabic_books[delete_index - 1] << endl;
                                Arabic_books.erase(Arabic_books.begin() + delete_index - 1);
                                cout << "Updated Arabic book list:" << endl;
                                for (size_t i = 0; i < Arabic_books.size(); ++i) {
                                    cout << i + 1 << ". " << Arabic_books[i] << endl;
                                }
                            } else {
                                cout << "Invalid book number!" << endl;
                            }
                        }
                        break;
                    }
                    case 4: { // Borrow a book
                        int borrow_count;
                        cout << "Enter the number of books to borrow: ";
                        cin >> borrow_count;
                        if (borrow_count > 0) {
                            Ar_borrowed_books += borrow_count;
                            cout << "Borrowed " << borrow_count << " Arabic book(s)." << endl;
                            cout << "Total borrowed Arabic books: " << Ar_borrowed_books << endl;
                        } else {
                            cout << "Invalid number of books to borrow." << endl;
                        }
                        break;
                    }
                    case 5: { // Return a book
                        int return_count;
                        cout << "Enter the number of books to return: ";
                        cin >> return_count;
                        if (return_count > 0) {
                            if (return_count <= Ar_borrowed_books) {
                                Ar_borrowed_books -= return_count;
                                cout << "Returned " << return_count << " Arabic book(s)." << endl;
                                cout << "Remaining borrowed Arabic books: " << Ar_borrowed_books << endl;
                            } else {
                                cout << "You are trying to return more books than borrowed!" << endl;
                                cout << "Currently borrowed: " << Ar_borrowed_books << " books." << endl;
                            }
                        } else {
                            cout << "Invalid number of books to return." << endl;
                        }
                        break;
                    }
                    case 6: // Back to main menu
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
            } while (book != 6);
        } else if (choice == 3) { // Exit option
            cout << "Exiting the library. Goodbye!" << endl;
            break; // Exit the main loop and the program
        }
        else {
            cout << "Invalid library choice!" << endl;
        }
    } while (true); // Main loop continues until explicitly exited

    return 0;
}
