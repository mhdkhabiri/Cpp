# 🧪 Abstract Factory Pattern – Network Protocol Example (C++)

This project demonstrates the **Abstract Factory Design Pattern** in C++ using a network client that can switch between **TCP** and **UDP** protocols without changing client logic.

---

## 📦 Overview

In networking applications, it's common to support multiple transport protocols (e.g., TCP, UDP). This example shows how to use the **Abstract Factory pattern** to:

- Create protocol-specific socket and packet classes
- Allow easy switching between TCP and UDP
- Keep the client code clean and independent of protocol logic

---

## 🧱 Class Structure

### 🔧 Abstract Products

| Class    | Description                         |
|----------|-------------------------------------|
| `Socket` | Abstract interface for connections  |
| `Packet` | Abstract interface for sending data |

### 🚀 Concrete Products

#### TCP

- `TCP_socket`: Implements connection using TCP
- `TCP_packet`: Implements data sending using TCP

#### UDP

- `UDP_socket`: Implements connection using UDP
- `UDP_packet`: Implements data sending using UDP

### 🏭 Factories

| Class            | Description                                     |
|------------------|-------------------------------------------------|
| `Protocol_factory` | Abstract factory for creating sockets/packets |
| `TCP_factory`      | Creates TCP socket and packet                 |
| `UDP_factory`      | Creates UDP socket and packet                 |

### 👨‍💻 Client

- `Network_client`: Uses a factory to create protocol objects and communicates with the network without knowing if it's TCP or UDP.

---

## ▶️ How It Works

In the `main()` function:

```cpp
Protocol_factory* factory = new TCP_factory;
Network_client client(factory);
client.run("192.168.0.10", "Hello Network!");
delete factory;
