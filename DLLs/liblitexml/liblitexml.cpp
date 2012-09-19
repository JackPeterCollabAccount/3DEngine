#pragma once

#include "liblitexml.h"
#include <stdexcept>
#include <fstream>

namespace LiteXML {

	liblitexml::liblitexml(std::string f) {
		this->memblock = NULL;
		std::fstream file;
		try {
		file.open (f, std::ios::in);
		if(file.is_open()) {
			std::ifstream::pos_type size;
			size = file.tellg();
			this->memblock = new char[size];
			file.read(this->memblock, size);
			worked = 1;
		} else {
			worked = 0;
		}
		file.close();
		} catch(...) {
			worked = 0;
		}
	}

	liblitexml::~liblitexml() {
		if(this->memblock != NULL)
		delete[] this->memblock;
	}

	double liblitexml::Add(double a, double b) {
		return a + b;
	}
}