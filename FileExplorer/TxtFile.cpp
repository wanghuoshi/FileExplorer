#include <io.h>
#include <direct.h> 
#include <iostream>
#include <string>
#include <cstdio>
#include "TxtFile.h"

const int MAX_PATH_LENGTH = 256;

enum type { folder, txt, video, image, database, exe };

TxtFile::TxtFile(const std::string & path) {
	this->setPath(path + ".txt");
	this->setFileName();
	this->setFileTime();
	this->setType(txt);
	this->fcreate();
	this->setSize();
}

void TxtFile::fshow() const {
	std::cout << "Name:   " << this->getName() << std::endl;
	std::cout << "Path:   " << this->getPath() << std::endl;
	std::cout << "Type:   " << "txt" << std::endl;
	std::cout << "Size:   " << this->getSize() << " bytes" << std::endl;
	std::cout << "Time:   " << this->getTime() << std::endl;
	std::cout << std::endl;
}