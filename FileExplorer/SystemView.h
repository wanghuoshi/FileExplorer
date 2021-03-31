#pragma once
#include <iostream>
#include <vector>
#include "Folder.h"
#include "FileListManager.h"

class SystemView {
public:
	SystemView(const std::string root);
	void enterMainMenu();
	void showLocation() const;
	void createFolder(const std::string& path, const std::string& type);
private:
	std::string rootdir;
	Folder *currentFolder;
	FileListManager fileList;
};