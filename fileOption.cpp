//
// Created by LeiLei on 2020/5/22.
//

#include "fileOption.hpp"

FileOption::FileOption(const string &path) {
    this->filePath = path;
}

/**
 * ���캯����filepath�趨�����ļ��е�·����ʱ�򣬿���ʹ���������
 * @param data: �ռ��ļ�������ĵ��ļ���������Ŀ¼��
 */
void FileOption::readFolderFile(vs &data) {
    try{
        if (!is_directory(this->filePath))
            throw MyExcept("��Error��the file path is not folder, can't use the function 'readFolderFile'");
    }
    catch (MyExcept & e) {
        cerr<<e.what()<<endl;
        return;
    }
    directory_iterator list(this->filePath);
    for(auto &d: list) {
        try {
            if (!is_directory(this->filePath))
                throw MyExcept("��Error��the file path is not folder, can't use the function 'readFolderFile'");
        }
        catch (MyExcept & e) {
            cerr<<"��Error��the file is the folder, not file! can't save it to the value 'data'"<<endl;
            continue;
        }
        data.push_back(d.path().parent_path().string() + "\\" + d.path().filename().string());
    }
}
/**
 * �����ַ����ķָ�
 * @param s ��Ҫ�ָ���ַ���
 * @param c �ָ��λ��
 * @return �ָ�֮��Ľ��
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
 * ʹ��������ʽ��ȡ���ַ������������
 * @param s ��Ҫ����������ȡ���ַ���
 * @return ��ȡ�����ֵĽ����vector
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
 * ����text�ļ��Ķ�ȡ
 * @param file �ļ���·��
 * @return ��ȡ�Ľ��
 */
vs FileOption::readText(const string &file) {
    fstream fs(file);
    try{
        if (!is_regular_file(file))
            throw MyExcept("��Error��the path is not file");
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
