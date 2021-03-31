#include <io.h>
#include <direct.h> 
#include <iostream>
#include <string>
#include <cstdio>
#include "DatabaseFile.h"

enum type { folder, txt, video, image, database, exe };

DatabaseFile::DatabaseFile(const std::string & path) {
	this->setPath(path + ".sql");
	this->setFileName();
	this->setFileTime();
	this->setType(database);
	this->fcreate();
	this->setSize();
}

void DatabaseFile::fshow() const {
	std::cout << "Name:   " << this->getName() << std::endl;
	std::cout << "Path:   " << this->getPath() << std::endl;
	std::cout << "Type:   " << "database" << std::endl;
	std::cout << "Size:   " << this->getSize() << " bytes" << std::endl;
	std::cout << "Time:   " << this->getTime() << std::endl;
	std::cout << std::endl;
}