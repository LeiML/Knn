//
// Created by LeiLei on 2020/5/22.
//

#include "fileOption.hpp"

FileOption::FileOption(const string &path) {
    this->filePath = path;
}

/**
 * 构造函数的filepath设定的是文件夹的路径的时候，可以使用这个函数
 * @param data: 收集文件夹下面的的文件名（单层目录）
 */
void FileOption::readFolderFile(vs &data) {
    try{
        if (!is_directory(this->filePath))
            throw MyExcept("【Error】the file path is not folder, can't use the function 'readFolderFile'");
    }
    catch (MyExcept & e) {
        cerr<<e.what()<<endl;
        return;
    }
    directory_iterator list(this->filePath);
    for(auto &d: list) {
        try {
            if (!is_directory(this->filePath))
                throw MyExcept("【Error】the file path is not folder, can't use the function 'readFolderFile'");
        }
        catch (MyExcept & e) {
            cerr<<"【Error】the file is the folder, not file! can't save it to the value 'data'"<<endl;
            continue;
        }
        data.push_back(d.path().parent_path().string() + "\\" + d.path().filename().string());
    }
}
/**
 * 进行字符串的分割
 * @param s 需要分割的字符串
 * @param c 分割的位置
 * @return 分割之后的结果
 */
vs FileOption::splitStr(const string &s, const string &c) {
    vs result;
    string temp = s;
    int strLen = s.size();
    int posLen = c.size();
    int index;
    while((index=temp.find(c))!=string::npos){
        result.push_back(s.substr(0, index));
        temp = temp.substr(index+posLen, strLen);
    }
    result.push_back(temp);
    return result;
}
/**
 * 使用正则表达式提取出字符串里面的数字
 * @param s 需要进行数字提取的字符串
 * @return 提取的数字的结果的vector
 */
vs FileOption::findDigital(const string &s) {
    regex pattern("\\d+");
    smatch sm;
    vs result;
    string temp = s;
    while(regex_search(temp, sm, pattern)){
        result.push_back(sm.str());
        temp = sm.suffix();
    }
    return result;
}
/**
 * 进行text文件的读取
 * @param file 文件的路径
 * @return 读取的结果
 */
vs FileOption::readText(const string &file) {
    fstream fs(file);
    try{
        if (!is_regular_file(file))
            throw MyExcept("【Error】the path is not file");
    }
    catch (MyExcept &e) {
        cerr<<e.what()<<endl;
        exit(-1);
    }
    vs result;
    string line;
    while(getline(fs, line))
        result.push_back(line);
    return result;
}
