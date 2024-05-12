// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage *newCage = new Cage;
    newCage->light = light;
    if (first == nullptr) {
        first = newCage;
        newCage->next = newCage;
        newCage->prev = newCage;
    } else {
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }

    Cage *current = first->next;
    int length = 1;
    while (current != first) {
        length++;
        current = current->next;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
