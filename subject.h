#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

template <typename InfoType, typename StateType> class Observer;

template <typename InfoType, typename StateType> class Subject {
  std::vector<Observer<InfoType, StateType> *> observers;
  StateType state;
 protected:
  void setState(StateType newS);
 public:
  void detach(Observer<InfoType, StateType> *o);
  void attach(Observer<InfoType, StateType> *o);  
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
  StateType getState() const;
};

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::detach(Observer<InfoType, StateType> *o) {
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    if (*it == o) {
      observers.erase(it);
      break;
    }
  }
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::attach(Observer<InfoType, StateType> *o) {
  observers.emplace_back(o);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::setState(StateType newS) { state = newS; }

template <typename InfoType, typename StateType>
StateType Subject<InfoType, StateType>::getState() const { return state; }
#endif

