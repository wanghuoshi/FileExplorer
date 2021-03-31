#include <iostream>
#include <cstring>
#include "SystemView.h"
#include "Folder.h"
#include "TxtFile.h"
#include "ImageFile.h"
#include "VideoFile.h"
#include "DatabaseFile.h"
#include "ExeFile.h"

const char *operationList[] = { "cd", "create", "delete", "show", "find", "list", "exit"};
const char *typeList[] = { "folder", "txt", "video", "image", "database", "exe" };
const char *sortList[] = { "name", "size", "time" };

enum type { folder, txt, video, image, database, exe };
enum operation {cd, create, fdelete, show, find, list, exitSys};

int getLength(const char *array[]) {
	int i = sizeof(array);
	int j = sizeof(*array);
	return sizeof(array) / sizeof(*array);
}

int parseOperation(const std::string &oper) {
	int j = getLength(operationList);
	for (int i = 0; i < 7; i++) { //getLength(operationList)
		if(oper == operationList[i]){
			return i;
		}
	}
	return -1;
}

int parseType(const std::string &typeInput) {
	for (int i = 0; i < 6; i++) { //getLength(typeList)
		if (typeInput == typeList[i]) {
			return i;
		}
	}
	return -1;
}

int parseSort(const std::string &sortInput) {
	for (int i = 0; i < 3; i++) { //getLength(sortList)
		if (sortInput == sortList[i]) {
			return i;
		}
	}
	return -1;
}

SystemView::SystemView(const std::string root) {
	std::cout << "请输入根目录> ";
	if (std::cin.get() == '\n') {
		rootdir = root;
		currentFolder = new Folder(root);
	}
	else {
		std::string rootinput;
		std::cin >> rootinput;
		rootdir = rootinput;
		currentFolder = new Folder(rootinput);
	}
	std::string curFolderPath = currentFolder->getPath();
	fileList.addMember(currentFolder);
}

void SystemView::enterMainMenu() {
	bool key = true;
	while (key) {
		showLocation();
		std::string oper;
		std::cin >> oper;
		int operNum = parseOperation(oper);
		switch (operNum) {
		case cd: {
			if (std::cin.get() == '\n') {
				BasicFile *father = fileList.findByPath(rootdir);
				currentFolder = dynamic_cast<Folder*>(father);
				break;
			}
			std::string name;
			std::cin >> name;
			if (name == "..") {
				std::string path = currentFolder->getPath();
				int pos = path.find_last_of("\\");
				std::string fatherPath = path.substr(0, pos);
				BasicFile *father = fileList.findByPath(fatherPath);
				currentFolder = dynamic_cast<Folder*>(father);
				break;
			}
			std::string childPath = currentFolder->getPath() + "\\" + name;
			FileListManager *children = currentFolder->getChildren();
			BasicFile *child = currentFolder->getChildren()->findByPath(childPath);
			if (child != NULL) {
				currentFolder = dynamic_cast<Folder*>(child);
			}
			else {
				std::cout << "文件夹不存在" << std::endl;
			}
			break;
		}
		case create: {
			std::string type, name;
			std::cin >> type;
			std::cin >> name;
			int typeNum = parseType(type);
			switch (typeNum) {
			case folder: {
				std::string folderPath = currentFolder->getPath() + "\\" + name;
				if (currentFolder->getChildren()->findByPath(folderPath) != NULL) {
					std::cout << "文件夹已存在" << std::endl;
					std::cout << std::endl;
					break;
				}
				Folder *fp = new Folder(folderPath);
				fp->fcreate();
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break;
			}
			case txt:{
				TxtFile *fp = new TxtFile(currentFolder->getPath() + "\\" + name);
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break; 
			}
			case video: {
				VideoFile *fp = new VideoFile(currentFolder->getPath() + "\\" + name);
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break;
			}
			case image: {
				ImageFile *fp = new ImageFile(currentFolder->getPath() + "\\" + name);
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break;
			}
			case database: {
				DatabaseFile *fp = new DatabaseFile(currentFolder->getPath() + "\\" + name);
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break;
			}
			case exe: {
				ExeFile *fp = new ExeFile(currentFolder->getPath() + "\\" + name);
				BasicFile *bfp = fp;
				currentFolder->getChildren()->addMember(bfp);
				fileList.addMember(bfp);
				break;
			}
			default:
				std::cout << "没有" << type << "文件类型" << std::endl;
			}
			break;
		}
		case fdelete: {
			std::string name;
			std::cin >> name;
			std::string childPath = currentFolder->getPath() + "\\" + name;
			FileListManager *children = currentFolder->getChildren();
			BasicFile *child = currentFolder->getChildren()->findByPathAndDelete(childPath);
			if (child != NULL) {
				child->fdelete();
				delete child;
			}
			else {
				std::cout << "文件不存在" << std::endl;
			}
			break;
		}
		case show: {
			if (std::cin.get() == '\n') {
				currentFolder->showChildren();
				break;
			}
			std::string name;
			std::cin >> name;
			std::string childPath = currentFolder->getPath() + "\\" + name;
			FileListManager *children = currentFolder->getChildren();
			BasicFile *child = currentFolder->getChildren()->findByPath(childPath);
			if (child != NULL) {
				std::cout << std::endl;
				child->fshow();
			}
			else {
				std::cout << "文件不存在" << std::endl;
			}
			break;
		}
		case find: case list: {
			std::string name, sort;
			std::cin >> name;
			std::cin >> sort;
			int sortNum = parseSort(sort);
			std::vector<BasicFile*> result = currentFolder->getChildren()->findByNameAndSort(name, sortNum);
			for (auto m : result) {
				std::cout << m->getName() << std::endl;
			}
			break;
		}
		case exitSys:
			key = false;
			break;
		default:
			std::cerr << "未知命令。" << std::endl;
			break;
		}
		
	}
}

void SystemView::showLocation() const {
	std::cout << currentFolder->getPath() << "> ";
}

void SystemView::createFolder(const std::string& path, const std::string& type) {
}
