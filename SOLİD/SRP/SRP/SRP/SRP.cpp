#include <iostream>
#include <string>
using namespace std;

class User {
public:
    User(const string& name) : m_name(name) {}

    void printName() {
        cout << "Name: " << m_name << endl;
    }

private:
    string m_name;
};

class UserRepository {
public:
    void saveUser(const User& user) {
        cout << "Saving user to the database..." << endl;
        // ...
    }
};

int main() {
    User user("John");
    user.printName();

    UserRepository userRepository;
    userRepository.saveUser(user);

    return 0;
}