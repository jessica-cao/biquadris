#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

// class textdisplay Jessica's Note: not quite sure why this is here?

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
  // TextDisplay td;
  StateType state;
 protected:
  void setState(StateType newS);
 public:
  void attach(Observer<InfoType> *o);  
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
  StateType getState() const;
};

template <typename InfoType>
void Subject<InfoType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

// Jessica's Note: for now, state is not used
// Remove the following functions if necessary
template <typename InfoType>
void Subject<InfoType>::setState(StateType newS) { state = newS; }

template <typename InfoType>
StateType Subject<InfoType>::getState() const { return state; }

#endif

