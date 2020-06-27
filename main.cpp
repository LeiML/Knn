#include "KNearestNeighbor.hpp"
#include "fileOption.hpp"
#include <string>
using namespace std;
/**
 * 制作标签的vector
 * @param f 获取文件操作类，的对象
 * @param fileList 文件列表
 * @return
 */
vector<int> makeLabel(const vs&fileList){
    vector<int>label;
    for(const string&s: fileList) {
        int result = stoi(FileOption::findDigital(s).at(1));
        label.push_back(result);
    }
    return label;
}
/**
 * 进行数据集的创建
 * @param data 文件路径的vector表
 * @return
 */
vector<vector<float>>makeSample(const vs&data){
    vector<vector<float>>sample;
    for(const string&s: data){
        vector<float>temp;
        vs tempLines = FileOption::readText(s);
        for(auto & tempLine : tempLines){
            for(char line : tempLine){
                if(line == '\n')
                    continue;
                temp.push_back(stof(string(1, line)));
            }
        }
        sample.push_back(temp);
    }
    return sample;
}

int main(int argc, char **argv) {
    FileOption file = FileOption(R"(E:\BasicProgram\ML_Data\Ch02\digits\trainingDigits)");
    FileOption file2 = FileOption(R"(E:\BasicProgram\ML_Data\Ch02\digits\testDigits)");
    vs data, testData;
    file.readFolderFile(data);
    file2.readFolderFile(testData);
    vector<int>Label = makeLabel(data);                                         //构建Label标签
    vector<int>testLabel = makeLabel(testData);                                 //构建Label标签
    vector<vector<float>>Sample = makeSample(data);                             //构建Sample的数据集
    vector<vector<float>>testSample = makeSample(testData);                     //构建Sample的数据集
    cout<<"【Success】数据集构建完毕"<<endl;
    KNearest kNearest = KNearest(7);                                         //创建KNN算法的类的对象
    cout<<"测试的文件路径："<<testData.at(100)<<endl;
    cout<<"测试的标签值："<<testLabel.at(100)<<endl;
    int result = kNearest.predict(Sample, Label, testSample.at(100));
    cout<<"预测结果："<<result<<endl;
}
