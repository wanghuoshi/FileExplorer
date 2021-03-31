#pragma once
#include <iostream>
#include "File.h"

class VideoFile : public File {
public:
	VideoFile(const std::string & path);
	virtual void fshow() const;
};