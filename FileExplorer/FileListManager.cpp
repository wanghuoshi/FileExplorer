#include <iostream>
#include <vector>
#include <string>
#include "FileListManager.h"
#include "BasicFile.h"
#include <algorithm>

enum sortList { fname, fsize, ftime };

bool sortByName(BasicFile* m1, BasicFile* m2) {
	return m1->getName() < m2->getName();
}

bool sortByTime(BasicFile* m1, BasicFile* m2) {
	return m1->getTime() < m2->getTime();
}

bool sortBySize(BasicFile* m1, BasicFile* m2) {
	return m1->getSize() < m2->getSize();
}

void FileListManager::addMember(BasicFile *fp) {
	list.push_back(fp);
}

FileListManager::~FileListManager() {
	for (const auto& member : list) {
		delete member;
	}
}

std::vector<BasicFile*> FileListManager::findByNameAndSort(const std::string& name, int sort) const{
	std::vector<BasicFile*> result;
	for (const auto& member : list) {
		if (member->getName().find(name) != std::string::npos) {
			result.push_back(member);
		}
	}
	switch (sort) {
	case fname:
		std::sort(result.begin(), result.end(), sortByName);
		break;
	case fsize:
		std::sort(result.begin(), result.end(), sortBySize);
		break;
	case ftime:
		std::sort(result.begin(), result.end(), sortByTime);
		break;
	}
	return result;
}

BasicFile* FileListManager::findByPath(const std::string& path) const{
	for (const auto& member : list) {
		if (member->getPath() == path) {
			return member;
		}
	}
	BasicFile *fp = NULL;
	return fp;
}

std::vector<BasicFile*> FileListManager::getList() const {
	return list;
}

BasicFile* FileListManager::findByPathAndDelete(const std::string& path) {
	;
	for (auto iter = begin(list); iter != end(list); ++iter) {
		if ((*iter)->getPath() == path) {
			BasicFile* found = *iter;
			list.erase(iter);
			return found;
		}
	}
	BasicFile *fp = NULL;
	return fp;
}