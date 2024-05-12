#include <iostream>
class ConsoleOutput {
public:
    // Constructor that accepts pairs of information strings and values
    template<typename... Args>
    ConsoleOutput(Args&&... args) {
        output(std::forward<Args>(args)...);
        n_outputs_called = 0;
    }
    int how_many_outputs_called(){
        return n_outputs_called;
    }

private:
    int n_outputs_called;
    // Function to output information strings and values to the console
    template<typename T>
    void output(const std::string& info, const T& value) {
        std::cout << info << ": " << value << std::endl;
        n_outputs_called++;

    }

    template<typename T, typename... Args>
    void output(const std::string& info, const T& value, Args&&... args) {
        std::cout << info << ": " << value << std::endl;
        output(std::forward<Args>(args)...);
        n_outputs_called++;
    }

};