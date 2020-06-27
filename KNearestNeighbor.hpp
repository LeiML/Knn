//
// Created by LeiLei on 2020/5/21.
//

#ifndef KNN_KNearestNeighbor_Hpp
#define KNN_KNearestNeighbor_Hpp
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <filesystem>
using namespace std;

typedef map<int, int> Map;

/**
 * �Զ����쳣������
 */
class MyExcept: public exception{
public:
    explicit MyExcept(const char* error):exception(error){};
};
/**
 * ����Knn����
 */
class KNearest{
public:
    explicit KNearest(const int&k=3);                                       //�趨Ĭ��ֵ��3�������趨k��Ϊ��ѡ����
    ~KNearest() = default;
    virtual int predict(const vector<vector<float>> &sample, const vector<int> &label, const vector<float>& testSample);
private:
    int k;                                                                  //����K�����㷨����ȡֵ��K
    virtual float distance(const vector<float>&p1, const vector<float>&p2); //���ڼ������ݵľ���
    virtual int maxDistance(const vector<float>&distance);
    virtual int countLabel(const vector<int>&label, const int&value);        //����ĳ��label��ֵ�ĸ���
};

#endif //KNN_KNearestNeighbor_Hpp
