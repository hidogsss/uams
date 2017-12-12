#ifndef _USERINFO_H_
#define _USERINFO_H_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

namespace uams
{
class UserBaseInfo
{
public:
    struct Info {
        std::string id;
        std::string username;
        std::string password;
        std::string website;
        std::string email;
        std::string application;
    };
    UserBaseInfo();
    UserBaseInfo(const char* un,
				 const char* pw,
				 const char* ws,
				 const char* em,
                 const char* app);
    ~UserBaseInfo();
    Info baseInfo;
};

class UserInfo : public UserBaseInfo
{
public:
    UserInfo();
    ~UserInfo();
    int GetItermsNums();
    void PrintUserInfo();
    Info iterm;
    std::vector<Info> iterms;
};

}

#endif // _USERINFO_H_
