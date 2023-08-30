#include <iostream>
#include <vector>

using namespace std;

#define NUM_MOVIES 3
#define NUM_ROWS 5
#define NUM_COLS 5
#define TICKET_PRICE 10.00

class Cinema {
private:
    struct Movie {
        string title;
        bool seats[NUM_ROWS][NUM_COLS] = {{false}};  
    };
    vector<Movie> movies;

public:
    Cinema() {
        movies.push_back({"Oh My God 2", {}});
        movies.push_back({"Dream Girl 2", {}});
        movies.push_back({"Mission Impossible", {}});
    }

    void displayMovies() {
        cout << "Available movies:" << endl;
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].title << endl;
        }
    }

    void displaySeats(int movieIndex) {
        cout << "Seating for " << movies[movieIndex].title << ":" << endl;
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                cout << (movies[movieIndex].seats[i][j] ? "X" : "O") << " ";
            }
            cout << endl;
        }
    }

    bool bookSeat(int movieIndex, int row, int col) {
        if (movies[movieIndex].seats[row][col]) {
            cout << "Seat is already booked!" << endl;
            return false;
        }
        movies[movieIndex].seats[row][col] = true;
        return true;
    }
};

int main() {
    Cinema cinema;

        while (true) {
        cinema.displayMovies();
        cout << "Enter movie number (or 0 to exit): ";

        int movieChoice;
        cin >> movieChoice;

        if (movieChoice == 0) 
        break;

        cinema.displaySeats(movieChoice - 1);
        cout << "Enter row and column to book (e.g. 2 3 for 2nd row, 3rd seat): ";

        int row, col;
        cin >> row >> col;

        if (cinema.bookSeat(movieChoice - 1, row - 1, col - 1)) {
            cout << "Seat booked successfully! Cost: $" << TICKET_PRICE << endl;
            } 
        else {
            cout << "Failed to book seat!" << endl;
            }
    }
    return 0;
}