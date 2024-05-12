// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Cage {
    bool light; // состояние лампочки
    Cage *next;
    Cage *prev;
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  Cage *first; // точка входа в поезд (первый вагон)
 public:
  Train(): countOp(0), first(nullptr) {}
  void addCage(bool light){
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
    } // добавить вагон с начальным состоянием лампочки
  int getLength(){
        if (!first) return 0;
        Cage* current = first;
        int length = 1;
        while (current->next != first) {
            length++;
            current = current->next;
        }
        return length;
    }        // вычислить длину поезда
  int getOpCount(){
        return countOp;
    }         // вернуть число переходов (из вагона в вагон)
};
#endif  // INCLUDE_TRAIN_H_
