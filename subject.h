#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class textdisplay

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
  // TextDisplay td;
  StateType state;
 protected:
  void setState(StateType newS);
 public:
  void attach(Observer<InfoType> *o);  
  void notifyObserver();
  virtual InfoType getInfo() const = 0;
  StateType getState() const;
};

template <typename InfoType>
void Subject<InfoType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

template <typename InfoType>
void Subject<InfoType>::setState(StateType newS) { state = newS; }

template <typename InfoType>
StateType Subject<InfoType>::getState() const { return state; }
#endif

