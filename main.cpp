#include "tinyxml2.h"
#include <iostream>
#include <string>
#include "userinfo.hpp"

using namespace uams;


void GetFiles(const char* dir)
{

}


void CreatXML(const char* xmlName)
{
    //create a new document
    tinyxml2::XMLDocument xmlDoc;
    //create a root node
    tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("Root");
    //insert a root node to doc
    xmlDoc.InsertFirstChild(pRoot);
    //saving the xml document to a xml file
    xmlDoc.SaveFile(xmlName);
}

void ShowIterms(const char* xmlName)
{
    //create a user info
    UserInfo userInfo;
	//create a new document
	tinyxml2::XMLDocument xmlDoc;
	//loading an existing xml file
	xmlDoc.LoadFile(xmlName);
	//getting a root node
    tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
    //getting the 1st child node of root node
    tinyxml2::XMLElement* pListElement = pRoot->FirstChildElement("User");

    //getting all the items
    while (pListElement != nullptr) {
        userInfo.iterm.id = pListElement->Attribute("id");
        userInfo.iterm.username = pListElement->Attribute("username");
        userInfo.iterm.password = pListElement->Attribute("password");
        userInfo.iterm.website = pListElement->Attribute("website");
        userInfo.iterm.email = pListElement->Attribute("email");
        userInfo.iterm.application = pListElement->Attribute("application");
        userInfo.iterms.push_back(userInfo.iterm);
        pListElement = pListElement->NextSiblingElement("User");
    }
    std::cout << "numbers of iterms = " << userInfo.GetItermsNums() << std::endl;
    userInfo.PrintUserInfo();
}

void InsertIterm(const char* xmlName, UserBaseInfo& userInfo)
{
    int id = 0;
	//create a new document
	tinyxml2::XMLDocument xmlDoc;
	//loading an existing xml file
	xmlDoc.LoadFile(xmlName);
	//getting a root node
    tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
    //getting the 1st child node of root node
    tinyxml2::XMLElement* pListElement = pRoot->FirstChildElement("User");
    //getting all the items
    while (pListElement != nullptr) {
        id ++;
        pListElement = pListElement->NextSiblingElement("User");
    }
    id += 1;
    //inserting a new node
    //create a new element
    tinyxml2::XMLElement* pElement;
    pElement = xmlDoc.NewElement("User");
    pElement->SetAttribute("id", id);
    pElement->SetAttribute("username", userInfo.baseInfo.username.c_str());
    pElement->SetAttribute("password", userInfo.baseInfo.password.c_str());
    pElement->SetAttribute("website", userInfo.baseInfo.website.c_str());
    pElement->SetAttribute("email", userInfo.baseInfo.email.c_str());
    pElement->SetAttribute("application", userInfo.baseInfo.application.c_str());
    pRoot->InsertEndChild(pElement);
    //saving the xml document to a xml file
    xmlDoc.SaveFile(xmlName);
}
void DeleteIterm(const char* xmlName, std::string id)
{
    //create a new document
	tinyxml2::XMLDocument xmlDoc;
	//loading an existing xml file
	xmlDoc.LoadFile(xmlName);
	//getting a root node
    tinyxml2::XMLNode* pRoot = xmlDoc.FirstChild();
    //getting the 1st child node of root node
    tinyxml2::XMLElement* pListElement = pRoot->FirstChildElement("User");

    //deleting specific iterm and re-order other iterms
    while (pListElement != nullptr) {
        if(pListElement->Attribute("id") == id) {
            pRoot->DeleteChild(pListElement);
        }
        pListElement = pListElement->NextSiblingElement("User");
    }
    //getting the 1st child node of root node
    pListElement = pRoot->FirstChildElement("User");
    int itermCount = 0;
    while (pListElement != nullptr) {
        itermCount ++;
        pListElement->SetAttribute("id", itermCount);
        pListElement = pListElement->NextSiblingElement("User");
    }
    //saving the xml document to a xml file
    xmlDoc.SaveFile(xmlName);
}

int main(int argc, char *argv[])
{
    const char* fileName = "Savedata.xml";
    std::cout << "uams v1.01 @copyright Hou Shuo 2016-2017" << std::endl;
    std::string cmd;
    std::string id = "";

    std::cout << argv[0] << std::endl;

    while(1) {
        cmd = "";
        std::cout << ">>";
        std::cin >> cmd;
        if (cmd == "help" || cmd == "h") {
            std::cout << "Commands: help / h\n"
                      << "          show / sh\n"
                      << "          delete / d\n"
                      << "          quit / q\n"
                      << "          insert / in\n"
                      << "          new / n\n";
        }
        else if (cmd == "delete" || cmd == "d") {
            std::cout << "input the iterm's id that you want to delete(cc to quit):";
            std::cin >> id;
            if (id != "cc") {
                DeleteIterm("Savedata.xml", id);
            }
            else {
                continue;
            }
        }
        else if (cmd == "show" || cmd == "sh") {
            ShowIterms("Savedata.xml");
        }
        else if (cmd == "quit" || cmd == "q") {
            break;
        }
        else if (cmd == "insert" || cmd == "in") {
			UserBaseInfo userInfo("hou", "dsgfdhgkj", "www.hao234.com", "email.com", "5522");
			InsertIterm(fileName, userInfo);
        }
        else if (cmd == "new" || cmd == "n") {
			std::cout << "input the file's name that you want to create(cc to quit):";
			CreatXML(fileName);
        }
        else {
            std::cout << "no such command!" << std::endl;
        }
    }
    return 0;
}
