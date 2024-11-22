#include <iostream>
#include "../include/immutable/HashMap.h"

int main() {
    // Create an empty immutable HashMap
    immutable::HashMap<std::string, int> map;

    // Test: Inserting key-value pairs
    auto map1 = map.insert("Alice", 30);
    auto map2 = map1.insert("Bob", 25);
    auto map3 = map2.insert("Charlie", 35);

    // Print values after insertion
    std::cout << "After insertions:\n";
    std::cout << "Alice: " << map3.getValue("Alice") << "\n"; // Should print 30
    std::cout << "Bob: " << map3.getValue("Bob") << "\n";     // Should print 25
    std::cout << "Charlie: " << map3.getValue("Charlie") << "\n"; // Should print 35

    // Test: Updating an existing key
    auto map4 = map3.insert("Alice", 40);
    std::cout << "\nAfter updating Alice's value:\n";
    std::cout << "Alice: " << map4.getValue("Alice") << "\n"; // Should print 40
    std::cout << "Bob (unchanged): " << map4.getValue("Bob") << "\n"; // Should print 25

    // Test: Checking existence of keys
    std::cout << "\nKey existence tests:\n";
    std::cout << "Does Alice exist? " << (map4.exists("Alice") ? "Yes" : "No") << "\n"; // Should print Yes
    std::cout << "Does Bob exist? " << (map4.exists("Bob") ? "Yes" : "No") << "\n";     // Should print Yes
    std::cout << "Does David exist? " << (map4.exists("David") ? "Yes" : "No") << "\n"; // Should print No

    // Test: Deleting a key
    auto map5 = map4.del("Alice");
    std::cout << "\nAfter deleting Alice:\n";
    std::cout << "Does Alice exist? " << (map5.exists("Alice") ? "Yes" : "No") << "\n"; // Should print No
    std::cout << "Does Bob exist? " << (map5.exists("Bob") ? "Yes" : "No") << "\n";     // Should print Yes

    // Test: Handling missing keys
    std::cout << "\nHandling missing keys:\n";
    try {
        std::cout << "David: " << map5.getValue("David") << "\n";
    } catch (const std::out_of_range &e) {
        std::cout << "Error: " << e.what() << "\n"; // Should print "Key not found"
    }

    // Test: IsEmpty function
    std::cout << "\nIsEmpty tests:\n";
    std::cout << "Is original map empty? " << (map.isEmpty() ? "Yes" : "No") << "\n";   // Should print Yes
    std::cout << "Is map5 empty? " << (map5.isEmpty() ? "Yes" : "No") << "\n";         // Should print No

    return 0;
}
