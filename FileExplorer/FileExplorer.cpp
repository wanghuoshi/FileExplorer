#include <iostream>
#include <string>
#include <vld.h>
#include "Folder.h"
#include "TxtFile.h"
#include "ImageFile.h"
#include "VideoFile.h"
#include "DatabaseFile.h"
#include "ExeFile.h"
#include "SystemView.h"

const std::string root = "D:\\Code\\CppProject\\FileExplorer\\root";

int main() {
	SystemView view(root);
	view.enterMainMenu();

	system("pause");
	return 0;
}