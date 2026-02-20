#include "Channel.h"
#include "IObserver.h"
#include <iostream>

Channel::Channel(const std::string& name) : name_(name) {}

std::string Channel::getName() const {
    return name_;
}

void Channel::attach(IObserver* obs) {
    if (obs == 0) return;

    for (size_t i = 0; i < observers_.size(); i++) {
        if (observers_[i] == obs) return;
    }

    observers_.push_back(obs);
    std::cout << "[Subscribe] " << obs->getId() << " subscribed\n";
}

void Channel::detach(IObserver* obs) {
    if (obs == 0) return;

    for (size_t i = 0; i < observers_.size(); i++) {
        if (observers_[i] == obs) {
            observers_.erase(observers_.begin() + i);
            std::cout << "[Unsubscribe] " << obs->getId() << " unsubscribed\n";
            return;
        }
    }
}

void Channel::notify(const VideoEvent& event) {
    for (size_t i = 0; i < observers_.size(); i++) {
        observers_[i]->update(event);
    }
}

void Channel::publish(const std::string& title, const std::string& type) {
    VideoEvent event;
    event.channelName = name_;
    event.title = title;
    event.type = type;

    std::cout << "\n[Channel] " << name_ << " published: \"" << title << "\" ("
              << type << ")\n";

    notify(event);
}