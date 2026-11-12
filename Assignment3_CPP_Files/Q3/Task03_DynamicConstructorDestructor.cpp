#include <iostream>
#include <string>

class Auditorium {
    int rows;
    int seatsPerRow;
    char** seats;
    int booked;

public:
    Auditorium(int r, int s)
        : rows(r > 0 ? r : 0),
          seatsPerRow(s > 0 ? s : 0),
          seats(nullptr),
          booked(0) {
        if (rows > 0 && seatsPerRow > 0) {
            seats = new char*[rows];
            for (int i = 0; i < rows; ++i) {
                seats[i] = new char[seatsPerRow];
                for (int j = 0; j < seatsPerRow; ++j) seats[i][j] = 'O';
            }
        }
        std::cout << "Auditorium created: " << rows << " rows, "
                  << seatsPerRow << " seats per row.\n";
    }

    Auditorium(const Auditorium&) = delete;
    Auditorium& operator=(const Auditorium&) = delete;

    bool book(int row, int seat) {
        if (!valid(row, seat) || seats[row][seat] == 'X') return false;
        seats[row][seat] = 'X';
        ++booked;
        return true;
    }

    bool cancel(int row, int seat) {
        if (!valid(row, seat) || seats[row][seat] == 'O') return false;
        seats[row][seat] = 'O';
        --booked;
        return true;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < seatsPerRow; ++j)
                std::cout << seats[i][j] << ' ';
            std::cout << '\n';
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows; ++i) delete[] seats[i];
        delete[] seats;
        std::cout << "Auditorium closed. Seats currently booked: "
                  << booked << ". Memory released.\n";
    }

private:
    bool valid(int r, int s) const {
        return r >= 0 && r < rows && s >= 0 && s < seatsPerRow;
    }
};

int main() {
    std::cout << "1. Stack object\n";
    Auditorium mainHall(3, 4);
    mainHall.book(0, 1);
    mainHall.book(2, 3);
    mainHall.display();
    mainHall.cancel(0, 1);

    std::cout << "\n2. Heap object\n";
    Auditorium* seminarHall = new Auditorium(2, 3);
    seminarHall->book(1, 1);
    delete seminarHall;

    std::cout << "\n3. Block-scope object\n";
    {
        Auditorium temporaryHall(1, 2);
        temporaryHall.book(0, 0);
    }

    std::cout << "\n4. Zero-row object\n";
    Auditorium emptyHall(0, 5);
    return 0;
}
