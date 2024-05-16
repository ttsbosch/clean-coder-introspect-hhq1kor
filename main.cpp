#include "processor.h"
#include <fstream>
#include <iostream>

int main()
{
    Processor processor;
    std::ifstream file("/home/hhq1kor/Documents/clean_code/clean-coder-introspect-hhq1kor/trades.txt");
    if (file.is_open())
    {
        processor.process(file);
        file.close();
    }
    else
    {
        std::cout << "Failed to open file" << std::endl;
    }
    return 0;
}
