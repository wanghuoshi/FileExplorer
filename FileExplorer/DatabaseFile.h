#pragma once
#include <iostream>
#include "File.h"

class DatabaseFile : public File {
public:
	DatabaseFile(const std::string & path);
	virtual void fshow() const;
};