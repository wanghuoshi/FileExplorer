#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BasicFile.h"

class FileListManager {
public:
	~FileListManager();
	void addMember(BasicFile *fp);
	std::vector<BasicFile*> findByNameAndSort(const std::string& name, int sort) const;
	BasicFile* findByPath(const std::string& path) const;
	BasicFile* findByPathAndDelete(const std::string& path);
	std::vector<BasicFile*> getList() const;
private:
	std::vector<BasicFile*> list;
};