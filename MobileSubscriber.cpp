#include "MobileSubscriber.h"
#include <iostream>

MobileSubscriber::MobileSubscriber(const std::string& username)
    : username_(username) {}

void MobileSubscriber::update(const VideoEvent& event) {
    std::cout << "  [Mobile] @" << username_
              << " notified: " << event.channelName
              << " -> " << event.title << "\n";
}

std::string MobileSubscriber::getId() const {
    return "@" + username_;
}