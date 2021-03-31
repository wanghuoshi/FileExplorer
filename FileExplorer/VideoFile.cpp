#include <io.h>
#include <direct.h> 
#include <iostream>
#include <string>
#include <cstdio>
#include "VideoFile.h"

enum type { folder, txt, video, image, database, exe };

VideoFile::VideoFile(const std::string & path) {
	this->setPath(path + ".mp4");
	this->setFileName();
	this->setFileTime();
	this->setType(video);
	this->fcreate();
	this->setSize();
}

void VideoFile::fshow() const {
	std::cout << "Name:   " << this->getName() << std::endl;
	std::cout << "Path:   " << this->getPath() << std::endl;
	std::cout << "Type:   " << "video" << std::endl;
	std::cout << "Size:   " << this->getSize() << " bytes" << std::endl;
	std::cout << "Time:   " << this->getTime() << std::endl;
	std::cout << std::endl;
}