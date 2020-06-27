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
    virtual void readFolderFile(vs &data);                      //��ȡ�ļ��������ÿ���ļ�������
    virtual vs splitStr(const string& s, const string&c);       //�ַ����ķָ�
    static vs findDigital(const string& s);                    //Ѱ���ַ������������
    static vs readText(const string& file);                    //��ȡtext���ļ�����
private:
    string filePath;                                            //˽�л��ļ���·��
};

#endif //KNN_FileOption_HPP
