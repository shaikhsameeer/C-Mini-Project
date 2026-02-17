#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_SEATS = 50;

class Railway {
private:
    string seats[MAX_SEATS];
    
public:
    Railway() {
        for(int i = 0; i < MAX_SEATS; i++) {
            seats[i] = "Available";
        }
        loadFromFile();
    }
    
    void bookSeat(int seatNum, string name) {
        if(seatNum < 1 || seatNum > MAX_SEATS) {
            throw out_of_range("Invalid seat number!");
        }
        if(seats[seatNum-1] != "Available") {
            throw runtime_error("Seat already booked!");
        }
        seats[seatNum-1] = name;
        saveToFile();
        cout << "Seat " << seatNum << " booked for " << name << endl;
    }
    
    void cancelSeat(int seatNum) {
        if(seatNum < 1 || seatNum > MAX_SEATS) {
            throw out_of_range("Invalid seat number!");
        }
        if(seats[seatNum-1] == "Available") {
            throw runtime_error("Seat not booked!");
        }
        cout << "Cancelled booking for: " << seats[seatNum-1] << endl;
        seats[seatNum-1] = "Available";
        saveToFile();
    }
    
    void displaySeats() {
        cout << "\n=== Seat Status ===\n";
        for(int i = 0; i < MAX_SEATS; i++) {
            cout << "Seat " << (i+1) << ": " << seats[i] << endl;
        }
    }
    
    void saveToFile() {
        ofstream file("railway_data.txt");
        if(!file) {
            throw runtime_error("Cannot open file for writing!");
        }
        for(int i = 0; i < MAX_SEATS; i++) {
            file << seats[i] << endl;
        }
        file.close();
    }
    
    void loadFromFile() {
        ifstream file("railway_data.txt");
        if(file) {
            for(int i = 0; i < MAX_SEATS; i++) {
                getline(file, seats[i]);
            }
            file.close();
        }
    }
};

int main() {
    Railway system;
    int choice, seatNum;
    string name;
    
    while(true) {
        cout << "\n=== Railway Reservation System ===\n";
        cout << "1. Book Seat\n2. Cancel Seat\n3. Display Seats\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        try {
            switch(choice) {
                case 1:
                    cout << "Enter seat number (1-" << MAX_SEATS << "): ";
                    cin >> seatNum;
                    cout << "Enter passenger name: ";
                    cin.ignore();
                    getline(cin, name);
                    system.bookSeat(seatNum, name);
                    break;
                    
                case 2:
                    cout << "Enter seat number to cancel: ";
                    cin >> seatNum;
                    system.cancelSeat(seatNum);
                    break;
                    
                case 3:
                    system.displaySeats();
                    break;
                    
                case 4:
                    cout << "Thank you!\n";
                    return 0;
                    
                default:
                    cout << "Invalid choice!\n";
            }
        }
        catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    return 0;
}