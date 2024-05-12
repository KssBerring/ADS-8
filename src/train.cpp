// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage *newCage = new Cage{light, nullptr, nullptr};

    if (!first) {
        first = newCage;
        first->next = first;
        first->prev = first;
    } else {
        Cage *current = first;
        while (current->next != first) {
            current = current->next;
        }
        current->next = newCage;
        newCage->prev = current;
        newCage->next = first;
        first->prev = newCage;
    }

    countOp++;
}

int Train::getLength() {
    int length = 0;
    Cage *current = first;
    do {
        length++;
        current = current->next;
    } while (current != first);
    return length;
}

int Train::getOpCount() {
    return countOp;
}
