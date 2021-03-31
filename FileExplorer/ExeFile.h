#pragma once
#include <iostream>
#include "File.h"

class ExeFile : public File {
public:
	ExeFile(const std::string & path);
	virtual void fshow() const;
};