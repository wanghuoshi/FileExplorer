#include <iostream>
#include <time.h>
#include <fstream>
#include "BasicFile.h"

const std::string& BasicFile::getName() const {
	return fname;
}

void BasicFile::setName(const std::string& name) {
	this->fname = name;
}

const std::string& BasicFile::getTime() const {
	return ftime;
}

void BasicFile::setTime(const std::string& time) {
	this->ftime = time;
}

const std::string& BasicFile::getPath() const {
	return fpath;
}

void BasicFile::setPath(const std::string& path) {
	this->fpath = path;
}

int BasicFile::getType() const {
	return ftype;
}

void BasicFile::setType(int type) {
	this->ftype = type;
}

int BasicFile::getSize() const {
	return fsize;
}

void BasicFile::setSize(int size) {
	this->fsize = size;
}