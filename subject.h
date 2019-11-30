#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

// class textdisplay Jessica's Note: not quite sure why this is here?

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
  std::vector<std::unique_ptr<Observer>> observers{new Observer};
  InfoType info;
 protected:
  void setState(InfoType newS);
 public:
  void attach(Observer<InfoType> *o);
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
  InfoType getState() const;
};

template <typename InfoType>
void Subject<InfoType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

// Jessica's Note: for now, state is not used
// Remove the following functions if necessary
template <typename InfoType>
void Subject<InfoType>::setState(InfoType newI) { info = newI; }

template <typename InfoType>
InfoType Subject<InfoType>::getState() const { return info; }

#endif

