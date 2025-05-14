#include <iostream>

// Abstract Products

class Socket {
public:
    virtual void connect(const std::string& address) = 0;
    virtual ~Socket() = default;
};


class Packet {
public:
    virtual void send_data(const std::string& data) = 0;
    virtual ~Packet() = default;
};


// Concrete Products: TCP
class TCP_socket : public Socket {
public:
    void connect(const std::string& address) override {
        std::cout << "Connecting via TCP to " << address << std::endl;
    }
};


class TCP_packet : public Packet {
public:
    void send_data(const std::string& data) override {
        std::cout << "Sending TCP packet:" << data << std::endl;
    }
};


// Concrete Products: UDP
class UDP_socket : public Socket {
public:
    void connect(const std::string& address) override {
        std::cout << "Connecting via UDP to " << address << std::endl;
    }
};


class UDP_packet : public Packet {
public:
    void send_data(const std::string& data) override {
        std::cout << "Sending UDP packet:" << data << std::endl;
    }
};


// Abstract Factory
class Protocol_factory {
public:
    virtual Socket* create_socket() = 0;
    virtual Packet* create_packet() = 0;
    virtual ~Protocol_factory() = default;
};


// Concrete Factory
class TCP_factory : public Protocol_factory {
public:
    Socket* create_socket() override {
        return new TCP_socket;
    }
    Packet* create_packet() override {
        return new TCP_packet;
    }
};


class UDP_factory : public Protocol_factory {
public:
    Socket* create_socket() override {
        return new UDP_socket;
    }
    Packet* create_packet() override {
        return new UDP_packet;
    }
};


// Client Code
class Network_client {
private:
    Socket* socket;
    Packet* packet;
public:
    Network_client(Protocol_factory* factory) {
        socket = factory->create_socket();
        packet = factory->create_packet();
    }

    void run(const std::string& address, const std::string& message) {
        socket->connect(address);
        packet->send_data(message);
    }

    ~Network_client() {
        delete socket;
        delete packet;
    }
};


int main() {
    Protocol_factory* facrory = new TCP_factory;
    Network_client client(facrory);
    client.run("192.168.0.10", "Hello Network!");
    delete facrory;
}