#pragma once

// Pattern Observer

#include <iostream>
#include <list>

class IObserver {
public:
	virtual ~IObserver() {};
	virtual void OnUpdate(const std::string& msg_from_subject) = 0;
};

class ISubject {
public:
	virtual ~ISubject() {};
	virtual void OnAttach(IObserver* observer) = 0;
	virtual void OnDetach(IObserver* observer) = 0;
	virtual void OnNotify() = 0;
};

class ASubject : public ISubject {
public:
    virtual ~ASubject() {
        std::cout << "MSG: Subject destroyed...\n";
    }

    // Subscription methods.

    void OnAttach(IObserver* observer) override {
        list_observers.push_back(observer);
    }
    void OnDetach(IObserver* observer) override {
        list_observers.remove(observer);
    }
    void OnNotify() override {
        std::list<IObserver*>::iterator iterator = list_observers.begin();
        GetAllObservers();
        while (iterator != list_observers.end()) {
            (*iterator)->OnUpdate(msg);
            ++iterator;
        }
    }

    void CreateMessage(std::string msg_from = "Empty") {
        msg = msg_from;
        OnNotify();
    }
    void GetAllObservers() {
        std::cout << "MSG: " << list_observers.size() << " observers in the list.\n";
    }

    void AnyLogic() {
        msg = "any msg";
        OnNotify();
        std::cout << "Any action from me.\n";
    }

private:
    std::list<IObserver*> list_observers;
    std::string msg;
};

class Observer : public IObserver {
public:
    Observer(ASubject& subject) : subject(subject) {
        this->subject.OnAttach(this);
        std::cout << "MSG: Observer -" << ++Observer::static_number << "- created.\n";
        number = Observer::static_number;
    }
    virtual ~Observer() {
        std::cout << "MSG: Observer -" << number << "- destroyed.\n";
    }

    void OnUpdate(const std::string& msg_from) override {
        msg_from_subject = msg_from;
        PrintInfo();
    }
    void RemoveFromList() {
        subject.OnDetach(this);
        std::cout << "MSG: Observer -" << number << "- removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "MSG: Observer -" << number << "-: a new message --> " << msg_from_subject << "\n";
    }

private:
    std::string msg_from_subject;
    ASubject& subject;
    static int static_number;
    int number;
};

int Observer::static_number = 0;

