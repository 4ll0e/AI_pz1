#include <iostream>
#include <string>
#include <vector>

class MustHaveDatabase {
public:
    struct Entry {
        std::string subject;
        std::string verb;
        std::string object;
    };

private:
    std::vector<Entry> must;
    const size_t MAX = 100;  // You can adjust the size limit
    size_t must_pos = 0;

public:
    void assertMust(const std::string& n, const std::string& v, const std::string& o) {
        if (must_pos < MAX) {
            must.push_back({ n, v, o });
            must_pos++;
        }
        else {
            std::cout << "Out of memory for must have database\n";
        }
    }

    // Optional: Print all entries to check the stored data
    void printEntries() const {
        for (const auto& entry : must) {
            std::cout << "Subject: " << entry.subject
                << ", Verb: " << entry.verb
                << ", Object: " << entry.object << std::endl;
        }
    }
};

int main() {
    MustHaveDatabase db;
    db.assertMust("John", "likes", "apples");
    db.assertMust("Alice", "owns", "car");

    // Print the database entries
    db.printEntries();

    return 0;
}
