# Observer Design Pattern — Channel / Subscribers (C++)

## Overview
This project demonstrates the **Observer** design pattern with a concrete and simple example:
a **Channel** (Subject / Publisher) notifies its **Subscribers** (Observers) when a new content is published.

- **Subject**: `Channel`
- **Observers**: `MobileSubscriber`, `EmailSubscriber`
- **Event data**: `VideoEvent` (channel name, title, type)

The demo includes:
- **Subscription** (attach)
- **Unsubscription** (detach)
- **Notification** of all subscribed observers (notify → update)

---

## Project structure
Design_Pattern/
├── Channel.h / Channel.cpp
├── MobileSubscriber.h / MobileSubscriber.cpp
├── EmailSubscriber.h / EmailSubscriber.cpp
├── ISubject.h
├── IObserver.h
├── VideoEvent.h
├── main.cpp
└── Makefile
└── Readme.md


---

## How to build
From the project folder:

```bash
make
```

This creates the executable:
- observer_demo

To clean object files and the executable:
```bash
make clean
```

How to run :
```bash
./observer_demo
```

Expected output :
The exact formatting can vary slightly, but you should observe:

    - Subscription of Mobile + Email
    Publish #1 → both observers receive the notification

    - Unsubscription of Email
    Publish #2 → only Mobile receives the notification

Example:
=== Subscription ===
[Subscribe] @alice subscribed
[Subscribe] bob@mail.com subscribed

=== Publish #1 (VIDEO) ===
[Channel] DesignPatternTV published: "Observer in 5 minutes" (VIDEO)
  [Mobile] @alice notified: DesignPatternTV -> Observer in 5 minutes
  [Email ] bob@mail.com notified: DesignPatternTV -> Observer in 5 minutes

=== Unsubscription (Email) ===
[Unsubscribe] bob@mail.com unsubscribed

=== Publish #2 (LIVE) ===
[Channel] DesignPatternTV published: "LIVE Q&A" (LIVE)
  [Mobile] @alice notified: DesignPatternTV -> LIVE Q&A


## How the Observer pattern is implemented

### Roles

#### Channel (Subject / Publisher)
- Stores a list of observers (`observers_`)
- Provides:
  - `attach(IObserver*)` to subscribe
  - `detach(IObserver*)` to unsubscribe
  - `notify(const VideoEvent&)` to broadcast an event

#### Subscribers (Observers)
- Implement:
  - `update(const VideoEvent&)` to react to a publication
  - `getId()` to display who subscribed or unsubscribed  
    (e.g. `@alice`, `bob@mail.com`)

---

### Why it is useful
Without the Observer pattern, `Channel` would need to directly call each subscriber type, which creates **tight coupling**.

With Observer:
- `Channel` depends only on the `IObserver` interface
- Adding a new subscriber type does **not** require modifying `Channel`
- Subscribers can be **added or removed dynamically** at runtime

---

### Notes / Design choices
- The `Channel` stores observers as **non-owning pointers** (`IObserver*`)
- For this small demo, the lifetime of observers is managed in `main.cpp`
- In larger projects, smart pointers can be used to avoid lifetime issues