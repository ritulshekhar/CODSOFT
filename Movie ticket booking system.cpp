#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SEATS = 50; // Maximum number of seats in the theater
const double REGULAR_SEAT_PRICE = 10.0; // Price of a regular seat
const double PREMIUM_SEAT_PRICE = 15.0; // Price of a premium seat
const string THEATRE_PASSWORD = "26072020"; // Password for theatre worker

struct Movie {
    string name;
    string timing;
};

void theatreWorkerPanel(stack<Movie>& AvailableMovies) {
    string password;
    cout << "Enter password for authentication: ";
    cin >> password;

    if (password == THEATRE_PASSWORD) {
        char choice;
        string movieName, movieTiming;
        Movie currentMovie;

        do {
            cout << "Enter the name of the movie to add: ";
            getline(cin >> ws, movieName);
            cout << "Enter the timing of the movie: ";
            getline(cin, movieTiming);

            currentMovie.name = movieName;
            currentMovie.timing = movieTiming;

            AvailableMovies.push(currentMovie);

            cout << "Do you want to add another movie? (y/n): ";
            cin >> choice;
            cin.ignore(); // Clear the input buffer
        } while (choice == 'y' || choice == 'Y');
    }
    else {
        cout << "Authentication failed. Incorrect password." << endl;
    }
}

void customerPanel(stack<Movie>& AvailableMovies) {
    cout << "\nWelcome to the theater!" << endl;

    int selectedSeats;
    char seatType;
    double totalPrice = 0.0;
    stack<Movie> selectedMovie;

    cout << "\nAvailable movies to choose from:" << endl;
    cout << "1. Crew" << endl;
    cout << "2. Picnic" << endl;
    cout << "3. RRR" << endl;
    cout << "4. Telescope" << endl;

    int movieChoice;
    cout << "Enter the index of the movie you want to watch (1-4): ";
    cin >> movieChoice;

    switch (movieChoice) {
    case 1:
        selectedMovie.push({ "Crew", "10:00 AM" });
        break;
    case 2:
        selectedMovie.push({ "Picnic", "1:00 PM" });
        break;
    case 3:
        selectedMovie.push({ "RRR", "4:00 PM" });
        break;
    case 4:
        selectedMovie.push({ "Telescope", "7:00 PM" });
        break;
    default:
        cout << "Invalid movie choice. Exiting..." << endl;
        return;
    }

    cout << "\nYou've chosen to watch \"" << selectedMovie.top().name << "\" at " << selectedMovie.top().timing << "." << endl;

    do {
        cout << "\nAvailable seats: ";
        bool seats[MAX_SEATS] = { false }; // Initialize all seats as empty
        for (int i = 0; i < MAX_SEATS; ++i) {
            if (!seats[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << "\nEnter the seat number you want to book (0 to exit): ";
        cin >> selectedSeats;

        if (selectedSeats > 0 && selectedSeats <= MAX_SEATS) {
            if (seats[selectedSeats - 1]) {
                cout << "Sorry, this seat is already booked. Please select another seat." << endl;
            }
            else {
                cout << "Enter seat type (R for Regular, P for Premium): ";
                cin >> seatType;

                if (seatType == 'R' || seatType == 'r') {
                    totalPrice += REGULAR_SEAT_PRICE;
                }
                else if (seatType == 'P' || seatType == 'p') {
                    totalPrice += PREMIUM_SEAT_PRICE;
                }
                else {
                    cout << "Invalid seat type. Please try again." << endl;
                    continue;
                }

                seats[selectedSeats - 1] = true;
                cout << "Seat " << selectedSeats << " booked successfully!" << endl;
            }
        }
        else if (selectedSeats != 0) {
            cout << "Invalid seat number. Please try again." << endl;
        }

    } while (selectedSeats != 0);

    cout << fixed << setprecision(2);
    cout << "\nTotal Price for booked seats: $" << totalPrice << endl;

    cout << "\nThank you for booking with us!" << endl;
}

int main() {
    stack<Movie> AvailableMovies;
    AvailableMovies.push({ "Crew", "10:00 AM" });
    AvailableMovies.push({ "Picnic", "1:00 PM" });
    AvailableMovies.push({ "RRR", "4:00 PM" });
    AvailableMovies.push({ "Telescope", "7:00 PM" });

    int userType;
    cout << "Select User Type:" << endl;
    cout << "1. Theatre Worker" << endl;
    cout << "2. Customer" << endl;
    cout << "Enter your choice: ";
    cin >> userType;

    if (userType == 1) {
        theatreWorkerPanel(AvailableMovies);
    }
    else if (userType == 2) {
        customerPanel(AvailableMovies);
    }
    else {
        cout << "Invalid user type. Exiting..." << endl;
    }

    return 0;
}