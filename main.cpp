#include <iostream>
#include <fstream>
#include <iostream>
#include <memory> 
#include <string>
#include "IParcer.h"
#include "Parcer_ini.h"



/*int main(int argc, char** argv) {
    //Аргументы командной строки
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            std::string s = std::string(argv[i]);
            std::cout << s << std::endl;
        }
        std::string filename = std::string(argv[1]);
        std::cout << filename << std::endl; //в проекте выводить не надо
        std::ifstream fin(filename); // тоже самое std::ifstream fin("filename.ini");
    }
    else {
        std::cout << "Only one argument was provided" << std::endl;
    }
    return 0;
}*/

int main() {

    std::ifstream in("file.txt");
    std::string currentLine;
    int counter = 0;
    while (getline (in, currentLine)) {
        counter++;
    }
    in.close();
    std::cout << counter;


    return 0;
}




std::map <std::string, std::map < std::string, std::string>> sections;
section["sectionName"]["keyName"] = "value";

auto it = sections.find(sectionName);
auto keyValueIT = it->second.find("keyName");
std::cout << keyValueIT->first;

for (const auto& section : _section) {
    std::cout << "[" << section.first << "]" << std::endl; 
    for (const auto& element : section) {
        std::cout << "key: " << element.first << " " << "value: " << element.second << std::endl;
    }
}




std::string currenLine;
char c = "/";
std::string sectionName;
while (c != " ") {
    std::getline(fin, currenLine);
    sectionName = parseSection(currenLine);
    if (sectionName != 0)



}