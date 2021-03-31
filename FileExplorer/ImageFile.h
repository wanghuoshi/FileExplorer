#pragma once
#include <iostream>
#include "File.h"

class ImageFile : public File {
public:
	ImageFile(const std::string & path);
	virtual void fshow() const;
};