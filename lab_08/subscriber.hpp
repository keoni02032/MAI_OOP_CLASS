#ifndef D_SUBSCRIBER_HPP_
#define D_SUBSCRIBER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "subs.hpp"

class PrintC : public sub {
public:
	void Print(std::vector<std::shared_ptr<figure>>& v) override {
		for (unsigned int i = 0; i < v.size(); ++i) {
			v[i]->print(std::cout);
		}
	}
};

class PrintF : public sub {
private:
	int count = 1;
public:
	void Print(std::vector<std::shared_ptr<figure>>& v) override {
		std::string filename = "";
		filename = "file_" + std::to_string(count) + ".txt";
		count += 1;
		std::ofstream file(filename);
		for (unsigned int i = 0; i < v.size(); i++) {
			v[i]->print(file);
		}
	}
};

#endif //D_SUBSCRIBER_HPP_