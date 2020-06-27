//
// Created by LeiLei on 2020/5/21.
//

#include "KNearestNeighbor.hpp"

KNearest::KNearest(const int &k) {
    this->k = k;
}

/**
 * 进行数据的训练，让每一组的sample与label具有较大的对应关系
 * @param Sample 样本数据
 * @param Label 样本类别
 */
int KNearest::predict(const vector<vector<float>> &Sample, const vector<int> &Label, const vector<float>& testSample) {
    vector<float>allDistance;
    int sampleSize = Sample.size();
    for(int i=0;i<sampleSize;i++){
        const vector<float>& sample = Sample.at(i);                     //获取每一组样本
        allDistance.push_back(this->distance(sample, testSample));      //获取每一组数据之间的距离
    }
    vector<float>tempDistance = allDistance;
    vector<int>label;
    for(int i=0;i<this->k;i++){
        int maxIndex = this->maxDistance(tempDistance);
        label.push_back(Label.at(maxIndex));
        tempDistance.erase(tempDistance.begin() + maxIndex);
    }
    set<int>setLabel(label.begin(), label.end());
    Map possibility;
    for(auto&temp: setLabel){
       auto data = make_pair(temp, this->countLabel(label, temp));
       possibility.insert(data);
    }
    float tempData = 0.0f;
    int result;
    for(const auto&p: possibility) {
        cout<<p.first<<'\t'<<p.second<<endl;
       if((p.second / float(this->k)) > tempData){
           tempData = (p.second / float(this->k));
           result = p.first;
       }
    }
    return result;
}
/**
 * 计算两个点之间的距离，也可以是两个样本
 * @param p1 样本1
 * @param p2 样本2
 * @return 距离
 */
float KNearest::distance(const vector<float>&p1, const vector<float>&p2) {
    try{
        if (p1.size() != p2.size())
            throw MyExcept("两个样本的维度不一致");
    }
    catch (MyExcept &e) {
        cerr<<e.what()<<endl;
        return 0;
    }
    float sum = 0.0;
    for(int i=0;i<p1.size();i++)
         sum += (p1.at(i) - p2.at(i)) * (p1.at(i) - p2.at(i));
    return sqrt(sum);
}

/**
 * 进行距离的最大值的确定
 * @param distance
 * @return
 */
int KNearest::maxDistance(const vector<float> &distance) {
    float result = 10000000.0f;
    int index = 0;
    for(int i=0;i<distance.size();i++){
        if (distance.at(i) < result) {
            result = distance.at(i);
            index = i;
        }
    }
    return index;
}

/**
 * 求取在label里面的value的个数
 * @param label 标签的数组
 * @param value 需要查找的值
 * @return
 */
int KNearest::countLabel(const vector<int>& label, const int &value) {
    int result = 0;
    for(int temp : label){
        if (temp == value)
            result ++;
    }
    return result;
}

