#include <io.h>
#include <direct.h> 
#include <iostream>
#include <string>
#include <cstdio>
#include <chrono>
#include <iomanip>
#include "File.h"
#include "BasicFile.h"

const int MAX_PATH_LENGTH = 256;

void File::setSize() {
	FILE *fp = fopen(this->getPath().c_str(), "r");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fclose(fp);
	this->fsize = size;
}

int File::getSize() const {
	return fsize;
}

void File::setFileName() {
	int pos = this->getPath().find_last_of('\\');
	this->setName(this->getPath().substr(pos + 1));
}

void File::setFileTime() {
	time_t rawtime;
	struct tm info;
	char buffer[80];
	time(&rawtime);
	localtime_s(&info, &rawtime);
	strftime(buffer, 80, "%Y/%m/%d %H:%M", &info);
	this->setTime(buffer);
}

void File::fcreate() {
	int pathLength = this->getPath().length();
	if (pathLength > MAX_PATH_LENGTH) {
		std::cout << "路径太长" << std::endl;
		std::cout << std::endl;
	}
	if (access(this->getPath().c_str(), 0) != 0) {
		FILE *pFile;
		pFile = fopen(this->getPath().c_str(), "w");
		if (pFile != NULL) {
			std::cout << "创建成功" << std::endl;
			std::cout << std::endl;
			fclose(pFile);
		}
		else {
			std::cout << "创建失败" << std::endl;
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "文件已存在" << std::endl;
		std::cout << std::endl;
	}
}

void File::fdelete() {
	if (access(this->getPath().c_str(), 0) == 0) {
		int result = remove(this->getPath().c_str());
		if (!result) {
			std::cout << "删除成功." << std::endl;
			std::cout << std::endl;
		}
		else {
			std::cout << "删除失败." << std::endl;
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "文件不存在" << std::endl;
		std::cout << std::endl;
	}
}