#pragma once
#include <iostream>

class BasicFile {
public:
	virtual void fcreate() = 0;
	virtual void fdelete() = 0;
	virtual void fshow() const = 0;
	const std::string& getName() const;
	void setName(const std::string& name);
	const std::string& getTime() const;
	void setTime(const std::string& time);
	const std::string& getPath() const;
	void setPath(const std::string& path);
	int getType() const;
	void setType(int type);
	int getSize() const;
	void setSize(int size);

private:
	std::string fname;
	std::string ftime;
	std::string fpath;
	int ftype = -1;
	int fsize = 0;
};