#pragma once
#include <iostream>
#include "File.h"

class TxtFile : public File {
public:
	TxtFile(const std::string & path);
	virtual void fshow() const;
};