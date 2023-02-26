#include <iostream>


class IMessageSender {
public:
    virtual void sendMessage(std::string message) = 0;
};


class EmailSender : public IMessageSender {
public:
    void sendMessage(std::string message) override {
        std::cout << "Sending email message: " << message << std::endl;
    }
};


class MessageService {
public:
    MessageService(IMessageSender* sender) : sender_(sender) {}

    void sendMessage(std::string message) {
        sender_->sendMessage(message);
    }

private:
    IMessageSender* sender_;
};

int main() {
    IMessageSender* sender = new EmailSender();
    MessageService service(sender);
    service.sendMessage("Hello, World!");
    return 0;
}
