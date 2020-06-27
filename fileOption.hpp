//
// Created by LeiLei on 2020/5/22.
//

#ifndef KNN_FileOption_HPP
#define KNN_FileOption_HPP
#include <filesystem>
#include <iostream>
#include <regex>
#include <fstream>
#include "KNearestNeighbor.hpp"

typedef vector<string> vs ;

using namespace std;
using namespace std::filesystem;

class FileOption{
public:
    explicit FileOption(const string&path);
    virtual void readFolderFile(vs &data);                      //读取文件夹下面的每个文件的名称
    virtual vs splitStr(const string& s, const string&c);       //字符串的分割
    static vs findDigital(const string& s);                    //寻找字符串里面的数字
    static vs readText(const string& file);                    //读取text的文件内容
private:
    string filePath;                                            //私有化文件的路径
};

#endif //KNN_FileOption_HPP
