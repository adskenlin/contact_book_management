#include <iostream>
#include <string>
# define max 1000
using namespace std;

// Struct
struct Person{
    string m_Name;
    int m_gender; // 1. man 2. woman
    int m_age;
    string m_number;
    string m_address;
};

struct ContactBook{
    struct Person personArray[max];
    int m_size;
};

// Function
int nameexist(ContactBook * p, string name){
    for (int i=0;i<p->m_size;i++){
        if (p->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void showMenu(){
    cout << "Welcome to your contact book" << endl;
    cout << "*****************************" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Show Contact List" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Find Contact" << endl;
    cout << "5. Edit Contact" << endl;
    cout << "6. Clean Contact List" << endl;
    cout << "0. Quit" << endl;
}

void addContact(ContactBook * p){
    
    if (p->m_size == max){
        cout << "Your contack book is out of memory" << endl;
        return;
    
    }else{
        string name;
        cout << "Please type in name: " << endl;
        cin >> name;
        p->personArray[p->m_size].m_Name = name;

        int gender = 0;
        cout << "Please type in gender: " << endl;
        cout << "1.man 2.woman" << endl;
        while (true){
            cin >> gender;
            if (gender == 1 || gender == 2){
                p->personArray[p->m_size].m_gender = gender;
                break;
            }else{
                cout << "please type in correct number" << endl;
            }
        }

        int age = 0;
        cout << "Please type in age: " << endl;
        while (true) {
            cin >> age;
            if (age < 150 && age > 0){
                p->personArray[p->m_size].m_age = age;
                break;
            }else{
                cout << "Please type in correct age" << endl;
            }
        }

        string phone_number;
        cout << "Please type in phone number: " << endl;
        cin >> phone_number;
        p->personArray[p->m_size].m_number = phone_number;

        string address;
        cout << "Please type in address: " << endl;
        cin >> address;
        p->personArray[p->m_size].m_address = address;

        p->m_size++;
        cout << "Contact added!" << endl;

        system("pause");
        system("cls");

    }
}

void showContact(ContactBook * p){
    if (p->m_size == 0){
        cout << "There is no contact in your contact book" << endl;
    }else{
        for (int i=0; i<p->m_size;i++){
            cout << "name: " << p->personArray[i].m_Name
                 << "\tgender: " << (p->personArray[i].m_gender == 1? "man":"woman")
                 << "\tage: " << p->personArray[i].m_age
                 << "\tphone number: " << p->personArray[i].m_number
                 << "\taddress: " << p->personArray[i].m_address
                 << endl;
        }
    }
    system("pause");
    system("cls");

}

void deleteContact(ContactBook * p){
    cout << "please type in the name that you want to delete: " << endl;
    string name;
    cin >> name;

    int is_exist = nameexist(p, name);
    if (is_exist != -1){
        for (int i=is_exist; i<p->m_size; i++){
            p->personArray[i] = p->personArray[i+1];
        }
        p->m_size--;
        cout << "Deleted!" << endl;

    }else{
        cout << "There is no "<< name <<" in your contact book" << endl;
    }
    system("pause");
    system("cls");

}

void findContact(ContactBook * p){
    string name;
    cout << "please type in the name you want to find: " << endl;
    cin >> name;
    int is_exist = nameexist(p, name);
    if (is_exist != -1){
         cout << "name: " << p->personArray[is_exist].m_Name
              << "\tgender: " << (p->personArray[is_exist].m_gender == 1? "man":"woman")
              << "\tage: " << p->personArray[is_exist].m_age
              << "\tphone number: " << p->personArray[is_exist].m_number
              << "\taddress: " << p->personArray[is_exist].m_address
              << endl;
    }else{
        cout << "There is no "<< name <<" in your contact book" << endl;
    }
    system("pause");
    system("cls");
}

void editContact(ContactBook * p){
    
    string name;
    cout << "please type in the name you want to edit: " << endl;
    cin >> name;
    int is_exist = nameexist(p, name);
    if (is_exist != -1){
        cout << "name: " << p->personArray[is_exist].m_Name
              << "\tgender: " << (p->personArray[is_exist].m_gender == 1? "man":"woman")
              << "\tage: " << p->personArray[is_exist].m_age
              << "\tphone number: " << p->personArray[is_exist].m_number
              << "\taddress: " << p->personArray[is_exist].m_address
              << endl;
        string new_name;
        cout << "please type in new name: " << endl;
        cin >> new_name;
        p->personArray[is_exist].m_Name = new_name;

        int new_gender = 0;
        cout << "Please type in new gender: " << endl;
        cout << "1.man 2.woman" << endl;
        while (true){
            cin >> new_gender;
            if (new_gender == 1 || new_gender == 2){
                p->personArray[is_exist].m_gender = new_gender;
                break;
            }else{
                cout << "please type in correct number" << endl;
            }
        }

        int new_age = 0;
        cout << "Please type in new_age: " << endl;
        while (true) {
            cin >> new_age;
            if (new_age < 150 && new_age > 0){
                p->personArray[is_exist].m_age = new_age;
                break;
            }else{
                cout << "Please type in correct age." << endl;
            }
        }

        string new_phone_number;
        cout << "Please type in new phone number: " << endl;
        cin >> new_phone_number;
        p->personArray[is_exist].m_number = new_phone_number;

        string new_address;
        cout << "Please type in new address: " << endl;
        cin >> new_address;
        p->personArray[is_exist].m_address = new_address;

    }else{
        cout << "There is no "<< name <<" in your contact book" << endl;
    }
    system("pause");
    system("cls");

}

void clean(ContactBook * p){
    p->m_size = 0;
    cout << "Cleaned!" << endl;
    system("pause");
    system("cls");
}

int main(){

    // initialize contack book
    ContactBook cbs;
    cbs.m_size = 0;

    // initialize the selection of user
    int select = 0;

    while (true){

        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            addContact(&cbs);
            break;
        case 2:
            showContact(&cbs);
            break;
        case 3:
            deleteContact(&cbs);
            break;
        case 4:
            findContact(&cbs);
            break;
        case 5:
            editContact(&cbs);
            break;
        case 6:
            clean(&cbs);
            break;
        case 0:
        {
            cout << "See You" << endl;
            system("pause");
            return 0;
        }
        default:
            cout << "please type number in 0-6." << endl;
            break;
        }
    }
    system("pause");
    return 0;
}