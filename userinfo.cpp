#include "userinfo.h"


namespace uams
{
UserBaseInfo::UserBaseInfo() {}
UserBaseInfo::UserBaseInfo(const char* un,
						   const char* pw,
						   const char* ws,
						   const char* em,
						   const char* app) {
	this->baseInfo.username = un;
	this->baseInfo.password = pw;
	this->baseInfo.website = ws;
	this->baseInfo.email = em;
	this->baseInfo.application = app;
}
UserBaseInfo::~UserBaseInfo() {}

UserInfo::UserInfo() {}
UserInfo::~UserInfo() {}

void UserInfo::PrintUserInfo() {
	std::cout << std::left << std::setw(10) << "\\ID"
			  << std::left << std::setw(15) << "\\USERNAME"
			  << std::left << std::setw(20) << "\\PASSWORD"
			  << std::left << std::setw(20) << "\\WEBSITE"
			  << std::left << std::setw(30) << "\\EMAIL"
			  << std::left << std::setw(30) << "\\APPLICATION"
			  << std::endl;
	int countIterms = iterms.size();
	for(int i = 0; i < countIterms; i ++) {
		std::cout << std::left << std::setw(10) << " " + this->iterms.at(i).id
				  << std::left << std::setw(15) << " " + this->iterms.at(i).username
				  << std::left << std::setw(20) << " " + this->iterms.at(i).password
				  << std::left << std::setw(20) << " " + this->iterms.at(i).website
				  << std::left << std::setw(30) << " " + this->iterms.at(i).email
				  << std::left << std::setw(30) << " " + this->iterms.at(i).application
				  << std::endl;
	}
}

int UserInfo::GetItermsNums() {
	return this->iterms.size();
}


}


