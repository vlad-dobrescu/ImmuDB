#include "../include/immutable/HashMap.h"

template <typename K, typename V>
immutable::HashMap<K, V>::HashMap() : bucketList(32, nullptr), bucketsCount(32) {}

template <typename K, typename V>
immutable::HashMap<K, V>::HashMap(std::vector<Node*> list, size_t count)
    : bucketList(list.size(), nullptr), bucketsCount(count) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i] != nullptr) {
            bucketList[i] = copyList(list[i]);
        }
    }
}

template <typename K, typename V>
immutable::HashMap<K, V>::HashMap(const HashMap<K, V>& other)
    : bucketList(other.bucketsCount, nullptr), bucketsCount(other.bucketsCount) {
    for (size_t i = 0; i < bucketsCount; i++) {
        if (other.bucketList.at(i) != nullptr) {
            bucketList.at(i) = copyList(other.bucketList.at(i));
        }
    }
}

template <typename K, typename V>
immutable::HashMap<K, V>::~HashMap() {
    for (size_t i = 0; i < bucketList.size(); ++i) {
        deleteList(bucketList[i]);
    }
}


template <typename K, typename V>
typename immutable::HashMap<K, V>::Node* immutable::HashMap<K, V>::copyList(Node* list) const {
    if (list == nullptr)
        return nullptr;

    Node* head = new Node(list->key, list->value);
    Node* newList = head;
    Node* oldList = list->next;

    while (oldList) {
        newList->next = new Node(oldList->key, oldList->value);
        newList = newList->next;
        oldList = oldList->next;
    }
    return head; 
}

template <typename K, typename V>
void immutable::HashMap<K, V>::deleteList(Node* list) const {
    while (list != nullptr) {
        Node* temp = list->next;
        delete list;
        list = temp;
    }
}

template <typename K, typename V>
typename immutable::HashMap<K, V> immutable::HashMap<K, V>::insert(const K& key, const V& val) const {
    size_t index = std::hash<K>()(key) % bucketsCount;

    Node* insertHere = copyList(bucketList.at(index));
    Node* current = insertHere;

    while (current != nullptr) {
        if (current->key == key) {
            current->value = val; 
            std::vector<Node*> newBucketList = bucketList;
            newBucketList.at(index) = insertHere;
            return HashMap(newBucketList, bucketsCount);
        }
        current = current->next;
    }

    Node* newNode = new Node(key, val);
    newNode->next = insertHere;

    std::vector<Node*> newBucketList = bucketList;
    newBucketList.at(index) = newNode;

    return HashMap(newBucketList, bucketsCount);
}

template <typename K, typename V>
typename immutable::HashMap<K, V> immutable::HashMap<K, V>::del(const K& key) const {
    size_t index = std::hash<K>()(key) % bucketsCount;

    Node* current = bucketList[index];
    Node* newBucket = nullptr;
    Node** tail = &newBucket;

    while (current != nullptr) {
        if (current->key != key) {
            *tail = new Node(current->key, current->value);
            tail = &((*tail)->next);
        }
        current = current->next;
    }

    std::vector<Node*> newBucketList = bucketList;
    newBucketList[index] = newBucket;

    return HashMap(newBucketList, bucketsCount);
}

template <typename K, typename V>
V immutable::HashMap<K, V>::getValue(const K& key) const {
    size_t index = std::hash<K>()(key) % bucketsCount;

    Node* current = bucketList[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    throw std::out_of_range("Key not found");
}

template <typename K, typename V>
bool immutable::HashMap<K, V>::exists(const K& key) const {
    size_t index = std::hash<K>()(key) % bucketsCount;

    Node* current = bucketList[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}

template <typename K, typename V>
bool immutable::HashMap<K, V>::isEmpty() const {
    for (size_t i = 0; i < bucketList.size(); ++i) {
        if (bucketList.at(i) != nullptr) {
            return false;
        }
    }
    return true;
}
