#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class MustHaveDatabase {
public:
    struct Entry {
        std::string subject;
        std::string verb;
        std::string object;
        bool active = true; // Default to active
    };

private:
    std::vector<Entry> may;
    std::vector<Entry> must;
    const size_t MAX = 100;  // Limit for the database size

public:
    void assertMust(const std::string& n, const std::string& v, const std::string& o) {
        if (must.size() < MAX) {
            must.push_back({ n, v, o });
        }
        else {
            std::cout << "Out of memory for must-have database\n";
        }
    }

    void restrict(const std::string& ms, const std::string& mv, const std::string& mo){
        std::string temp = mv.substr(0, 3);
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

        if (temp != "not") {
            return;
        }

        for (auto& entry : may) {
            if (entry.active && entry.verb == mv.substr(4) && entry.subject == ms && entry.object == mo) {
                assertMust(entry.subject, entry.verb, entry.object);
                entry.active = false; // Remove from list by marking inactive
                return;
            }
        }
    }

        // Optional: Print the 'may' and 'must' lists
        void printMay() const {
        for (const auto& entry : may) {
            if (entry.active) {
                std::cout << "May - Subject: " << entry.subject
                    << ", Verb: " << entry.verb
                    << ", Object: " << entry.object << std::endl;
            }
        }
    }

    void printMust() const {
        for (const auto& entry : must) {
            std::cout << "Must - Subject: " << entry.subject
                << ", Verb: " << entry.verb
                << ", Object: " << entry.object << std::endl;
        }
    }

    // Populate 'may' list with some entries (for testing purposes)
    void addMayEntry(const std::string& subject, const std::string& verb, const std::string& object) {
        may.push_back({ subject, verb, object });
    }
};

int main() {
    MustHaveDatabase db;

    // Add some entries to 'may' list
    db.addMayEntry("John", "likes", "apples");
    db.addMayEntry("Alice", "owns", "car");

    // Restrict an entry from 'may' to 'must' list
    db.restrict("John", "not likes", "apples");

    // Print the lists
    std::cout << "May List:\n";
    db.printMay();

    std::cout << "\nMust List:\n";
    db.printMust();

    return 0;
}
