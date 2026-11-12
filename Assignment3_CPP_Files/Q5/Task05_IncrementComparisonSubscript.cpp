#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Time {
    int totalSeconds;

public:
    explicit Time(int seconds = 0) : totalSeconds(seconds < 0 ? 0 : seconds) {}

    Time& operator++() { // Prefix
        ++totalSeconds;
        return *this;
    }

    Time operator++(int) { // Postfix
        Time old = *this;
        ++totalSeconds;
        return old;
    }

    bool operator==(const Time& other) const {
        return totalSeconds == other.totalSeconds;
    }

    bool operator<(const Time& other) const {
        return totalSeconds < other.totalSeconds;
    }

    void display() const {
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        std::cout << h << ':' << (m < 10 ? "0" : "") << m
                  << ':' << (s < 10 ? "0" : "") << s;
    }
};

class Playlist {
    std::vector<std::string> tracks;

public:
    Playlist(std::initializer_list<std::string> items) : tracks(items) {}

    std::string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw std::out_of_range("Playlist index out of range");
        return tracks[index];
    }

    const std::string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw std::out_of_range("Playlist index out of range");
        return tracks[index];
    }

    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(3599);
    Time a = t++;
    Time b = ++t;

    std::cout << "a = "; a.display();
    std::cout << "\nb = "; b.display();
    std::cout << "\nt = "; t.display();
    std::cout << "\n";

    Playlist playlist{"Track One", "Track Two", "Track Three"};
    std::cout << "Playing: " << playlist[0] << '\n';
    playlist[1] = "Updated Track Two";
    std::cout << "Updated: " << playlist[1] << '\n';

    try {
        std::cout << playlist[playlist.size()] << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}
