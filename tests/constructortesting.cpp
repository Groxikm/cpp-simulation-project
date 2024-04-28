//
// Created by groxikm on 28.04.2024.
//
#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
    Component(string companyName){
        printf("Component constructor called!\n");
        this->companyName = companyName;
    }
    string companyName;
};

class GPU : public Component
{
public:
    GPU(string companyName)
            : Component(companyName){
        printf("GPU constructor called!\n");
        //this->parameters = parameters;
    }
    string parameters;
};

class Memory : public Component
{
public:
    Memory(string companyName)
            : Component(companyName){
        printf("Memory constructor called!\n");
        //this->parameters = parameters;
    }
    string parameters;
};

class GraphicCard : public GPU, public Memory
{
public:
    GraphicCard(string gpuCompanyName, string memoryCompanyName)
            : GPU(gpuCompanyName), Memory(memoryCompanyName){
        printf("Graphic card constructor called!\n");
        //this->parameters = parameters;
    }
    string model;
};

int main(){
    string gpu, mem = "kal";
    GraphicCard(gpu,mem);
    return 0;
}