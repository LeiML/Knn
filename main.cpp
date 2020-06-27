#include "KNearestNeighbor.hpp"
#include "fileOption.hpp"
#include <string>
using namespace std;
/**
 * ������ǩ��vector
 * @param f ��ȡ�ļ������࣬�Ķ���
 * @param fileList �ļ��б�
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
 * �������ݼ��Ĵ���
 * @param data �ļ�·����vector��
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
    vector<int>Label = makeLabel(data);                                         //����Label��ǩ
    vector<int>testLabel = makeLabel(testData);                                 //����Label��ǩ
    vector<vector<float>>Sample = makeSample(data);                             //����Sample�����ݼ�
    vector<vector<float>>testSample = makeSample(testData);                     //����Sample�����ݼ�
    cout<<"��Success�����ݼ��������"<<endl;
    KNearest kNearest = KNearest(7);                                         //����KNN�㷨����Ķ���
    cout<<"���Ե��ļ�·����"<<testData.at(100)<<endl;
    cout<<"���Եı�ǩֵ��"<<testLabel.at(100)<<endl;
    int result = kNearest.predict(Sample, Label, testSample.at(100));
    cout<<"Ԥ������"<<result<<endl;
}
