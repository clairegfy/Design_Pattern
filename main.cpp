#include "Channel.h"
#include "MobileSubscriber.h"
#include "EmailSubscriber.h"
#include <iostream>

int main() {
    Channel channel("DesignPatternTV");

    MobileSubscriber mob("alice");
    EmailSubscriber email("bob@mail.com");

    std::cout << "=== Subscription ===\n";
    channel.attach(&mob);
    channel.attach(&email);

    std::cout << "\n=== Publish #1 (VIDEO) ===\n";
    channel.publish("Observer in 5 minutes", "VIDEO");

    std::cout << "\n=== Unsubscription (Email) ===\n";
    channel.detach(&email);

    std::cout << "\n=== Publish #2 (LIVE) ===\n";
    channel.publish("LIVE Q&A", "LIVE");

    return 0;
}