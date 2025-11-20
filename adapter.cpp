#include <iostream>
using namespace std;

// Цільовий інтерфейс //
class IMessage {
public:
    virtual void send(const string& text) = 0;
    virtual ~IMessage() = default;
};

// Стара реалізація //
class LegacyPrinter {
public:
    void printText(const string& text) {
        cout << "LegacyPrinter: " << text << endl;
    }
};

// адаптер //
class PrinterAdapter : public IMessage {
private:
    LegacyPrinter* legacy;
public:
    PrinterAdapter(LegacyPrinter* lp) : legacy(lp) {}

    void send(const string& text) override {
        // викликаємо старий метод через адаптер//
        legacy->printText(text);
    }
};

int main() {
    //старий принтер//
    LegacyPrinter oldPrinter;
    PrinterAdapter adapter(&oldPrinter);
    adapter.send("Hello from the adapter pattern!");

    return 0;
}