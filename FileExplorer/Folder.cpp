#include <io.h>
#include <direct.h> 
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "Folder.h"

const int MAX_PATH_LENGTH = 256;

enum type { folder, txt, video, image, database, exe };

Folder::Folder(const std::string & path) {
	this->setPath(path);
	this->setFolderName();
	this->setFolderTime();
	this->setType(folder);
}

Folder::~Folder() {
	delete children;
}

void Folder::fcreate() {
	int pathLength = this->getPath().length();
	if (pathLength > MAX_PATH_LENGTH) {
		std::cout << "·��̫��" << std::endl;
		std::cout << std::endl;
	}
	else {
		if (access(this->getPath().c_str(), 0) != 0) {
			int ret = mkdir(this->getPath().c_str());
			if (ret < 0 ) {
				std::cout << "����ʧ��" << std::endl;
				std::cout << std::endl;
			}
			else {
				std::cout << "�����ɹ�" << std::endl;
				std::cout << std::endl;
			}
		}
		else {
			std::cout << "�ļ����Ѵ���" << std::endl;
			std::cout << std::endl;
		}
	}
	
}

void Folder::fdelete() {
	int result = rmdir(this->getPath().c_str());
	if (!result) {
		std::cout << "ɾ���ɹ�." << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "ɾ��ʧ��." << std::endl;
		std::cout << std::endl;
	}
}

void Folder::fshow() const {
	std::cout << "Name:   " << this->getName() << std::endl;
	std::cout << "Path:   " << this->getPath() << std::endl;
	std::cout << "Type:   " << "folder" << std::endl;
	std::cout << "Time:   " << this->getTime() << std::endl;
	std::cout << std::endl;
}

void Folder::setFolderName() {
	int pos = this->getPath().find_last_of('\\');
	this->setName(this->getPath().substr(pos + 1));
}

void Folder::setFolderTime() {
	time_t rawtime;
	struct tm info;
	char buffer[80];
	time(&rawtime);
	localtime_s(&info, &rawtime);
	strftime(buffer, 80, "%Y/%m/%d %H:%M", &info);
	this->setTime(buffer);
}

FileListManager* Folder::getChildren() const {
	return children;
 }

void Folder::showChildren() const {
	for (auto& member : children->getList()) {
		std::cout << member->getName() << std::endl;
	}
}