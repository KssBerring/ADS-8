// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(){countOp = 0;
    first = nullptr;}

void Train::addCage(bool light) {
        Cage* newCage = new Cage{ light, nullptr, nullptr };
        if (!first) {
            first = newCage;
            newCage->next = newCage;
            newCage->prev = newCage;
        }
        else {
            newCage->next = first;
            newCage->prev = first->prev;
            first->prev->next = newCage;
            first->prev = newCage;
        }
    }

int Train::getLength() {
        if (!first) return 0;
        Cage* current = first;
        int length = 1;
        while (current->next != first) {
            length++;
            current = current->next;
        }
        return length;
    }

int Train::getOpCount() {
  return countOp;
}
