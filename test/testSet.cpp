#include "../include/immutable/Set.h"
#include <iostream>

int main() {
    immutable::Set<int> set;

    // Insert elements into the set
    immutable::Set<int> set1 = set.insert(10);
    immutable::Set<int> set2 = set1.insert(20);
    immutable::Set<int> set3 = set2.insert(30);
    immutable::Set<int> set4 = set3.del(20);

    // Test existence of elements
    std::cout << "Set contains 10: " << (set4.exists(10) ? "Yes" : "No") << "\n";
    std::cout << "Set contains 20: " << (set4.exists(20) ? "Yes" : "No") << "\n";
    std::cout << "Set contains 30: " << (set4.exists(30) ? "Yes" : "No") << "\n";

    // Test size of the set
    std::cout << "Set size: " << set4.size() << "\n";

    // Test immutability: original sets remain unchanged
    std::cout << "Set1 contains 10: " << (set1.exists(10) ? "Yes" : "No") << "\n";
    std::cout << "Set1 contains 20: " << (set1.exists(20) ? "Yes" : "No") << "\n";
    std::cout << "Set1 size: " << set1.size() << "\n";

    return 0;
}
