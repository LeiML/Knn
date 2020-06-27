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
 * 自定义异常处理类
 */
class MyExcept: public exception{
public:
    explicit MyExcept(const char* error):exception(error){};
};
/**
 * 构建Knn的类
 */
class KNearest{
public:
    explicit KNearest(const int&k=3);                                       //设定默认值是3，并且设定k作为可选参数
    ~KNearest() = default;
    virtual int predict(const vector<vector<float>> &sample, const vector<int> &label, const vector<float>& testSample);
private:
    int k;                                                                  //用于K近邻算法中所取值的K
    virtual float distance(const vector<float>&p1, const vector<float>&p2); //用于计算数据的距离
    virtual int maxDistance(const vector<float>&distance);
    virtual int countLabel(const vector<int>&label, const int&value);        //计算某个label的值的个数
};

#endif //KNN_KNearestNeighbor_Hpp
