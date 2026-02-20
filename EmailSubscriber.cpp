#include "EmailSubscriber.h"
#include <iostream>

EmailSubscriber::EmailSubscriber(const std::string& email)
    : email_(email) {}

void EmailSubscriber::update(const VideoEvent& event) {
    std::cout << "  [Email ] " << email_
              << " notified: " << event.channelName
              << " -> " << event.title << "\n";
}

std::string EmailSubscriber::getId() const {
    return email_;
}