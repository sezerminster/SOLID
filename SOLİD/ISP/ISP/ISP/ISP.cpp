#include <iostream>


class ILogger {
public:
    virtual void log(const std::string& message) = 0;
};

class IFileLogger : public ILogger {
public:
    virtual void logToFile(const std::string& message) = 0;
};

class IConsoleLogger : public ILogger {
public:
    virtual void logToConsole(const std::string& message) = 0;
};

class FileLogger : public IFileLogger {
public:
    void log(const std::string& message) override {
        logToFile(message);
    }
    void logToFile(const std::string& message) override {
        
    }
};

class ConsoleLogger : public IConsoleLogger {
public:
    void log(const std::string& message) override {
        logToConsole(message);
    }
    void logToConsole(const std::string& message) override {
        // Implementation of logging to console
    }
};
int main() {
   
    std::unique_ptr<IFileLogger> fileLogger = std::make_unique<FileLogger>();
    std::unique_ptr<IConsoleLogger> consoleLogger = std::make_unique<ConsoleLogger>();

    fileLogger->log("This message is logged to a file");

    consoleLogger->log("This message is logged to the console");

    return 0;
}