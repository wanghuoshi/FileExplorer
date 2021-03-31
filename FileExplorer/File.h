#pragma once
#include <iostream>
#include "BasicFile.h"

class File : public BasicFile {
public:
	virtual void setSize();
	virtual int getSize() const;
	virtual void setFileName();
	virtual void setFileTime();
	virtual void fdelete();
	virtual void fcreate();
	virtual void fshow() const = 0;
private:
	int fsize = 0;
};
