#include "hash_list.h"
#include <iostream>
hash_list::hash_list() : size(0), head(NULL) {}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {
    node* target = head;

    // Search list for any matching key
    while (target != NULL) {
        std::cout << target->key << " , " << target->value << std::endl;
        if (target->key == key) {
            // Updating the key if there is a match
            target->value = value; 
            return;
        }
        target = target->next;
    }

    //If the key doesn't exist, insert new node
    node* newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    size++;
}

std::optional<float> hash_list::get_value(int key) const {
    // Setting the index to the start of the list
    node* current = head;

    // increment to the end of the list
    while (current != NULL) {
        // If the current indexed key is the correct value, then return
        if (current->key == key) {
            return current->value;
        }
        // Else increment to the next node
        current = current->next;
    }
    // Optional return if the value isn't found
    return std::nullopt; 
    }

bool hash_list::remove(int key) { 
    // Checking if first node is the key match
    if (head != nullptr && head->key == key) {
        node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // Going through list to find node to remove
    node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->key == key) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }

    // Key wasn't found
    return false; 
}

size_t hash_list::get_size() const { 
    
    return size; 
}

hash_list::~hash_list() {}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
