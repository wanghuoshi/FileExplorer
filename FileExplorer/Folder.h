#pragma once
#include <iostream>
#include <vector>
#include "BasicFile.h"
#include "FileListManager.h"

class Folder : public BasicFile {
public:
	Folder(const std::string & path);
	~Folder();
	virtual void fcreate();
	virtual void fdelete();
	virtual void fshow() const;

	virtual void setFolderName();
	virtual void setFolderTime();
	virtual void showChildren() const;

	virtual FileListManager* getChildren() const;
private:
	FileListManager *children = new FileListManager();
};