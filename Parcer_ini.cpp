#include "Parcer_ini.h"

void Parcer_ini::IReaderFile(const std::string& file_name){

	std::ifstream path;
	path.open(file_name);
	std::string currenLine;
	std::string sectionTitle;
	std::string key;
	std::string value;

	// Количество строк в файле
	/*std::ifstream in("file.txt");
	int counter = 0;
	while (getline(in, str)){
		counter++;
	}
	in.close();
	std::cout << counter;*/
		
	//std::map <std::string, std::string> parameterValues;


	if (path.is_open()) {
		while (getline(path, currenLine)) {			
			if (currenLine[0] == '[') {
				sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
				_section[sectionTitle];
			}
			else {
				if (currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[') { //+проверитьна пустую строку
					for (int i = 0; i < currenLine.size(); i++) {
						if (currenLine[i] == '=') {
							key = currenLine.substr(0, currenLine.find('=') - 1);
							value = currenLine.substr(currenLine.find('=') + 1, currenLine.find(' ') - 1);
							//parameterValues[key] = value;
							//parameterValues[currenLine.substr(0, currenLine.find('=') - 1)] = currenLine.substr(currenLine.find('=') + 1);
							//_section[sectionTitle] = parameterValues;
							_section[sectionTitle][key] = value;
						}
					}
				}
			}
			for (const auto& section : _section) {
				std::cout << "[" << section.first << "]" << std::endl;
				for (const auto& element : section.second) {
					std::cout << "key: " << element.first << " " << "value: " << element.second << std::endl;
				}
			}
		}
	}
	else
		throw "Error open file";
	path.close();
}
