#include <iostream>
#include "../console-interface/f-coursor-handler.cpp"
class ConsoleOutput {
public:
    // Constructor that accepts pairs of information strings and values
    template<typename... Args>
    ConsoleOutput(Args&&... args) {
        setCursorPosition(0,0);
        output(std::forward<Args>(args)...);
    }

private:
    // Function to output information strings and values to the console
    template<typename T>
    void output(const std::string& info, const T& value) {
        std::cout << info << ": " << value << std::endl;
    }

    template<typename T, typename... Args>
    void output(const std::string& info, const T& value, Args&&... args) {
        std::cout << info << ": " << value << std::endl;
        output(std::forward<Args>(args)...);
    }

};