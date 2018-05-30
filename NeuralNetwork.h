#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


/**
 * 从文件中获取样本数据(get the sample data from file)
 * 
 * @param  filepath 文件路径(file's path)
 * @return          包含数据样本的向量,样本数据组< 单个的样本数据 <样本数据的行 <0,1数组> > > >(vector containing sample data,arrary of sample data< sample data <row of sample data <array of 0,1> > >)
 */
std::vector<std::vector <std::vector<int> > > getFormatDataGroupFromFile(std::string filepath);

/**
 * 将样本数据标准化(format the sample data)
 * @param  dataGroup 待标准化的数据组,数据组< 单个的数据 <数据的行 <0,1数组> > > >(the vector witch need to be formatted,arrary of data< data <row of data <array of 0,1> > >)
 * @return           标准化的样本数据,样本数据组< 单个的样本数据 <按行展开的0,1数组> > >(vector containing format sample data,arrary of sample data< sample data <array of 0,1 expanded by rows> >)
 */
std::vector<std::vector<int> > formatDataToOneRow(std::vector<std::vector <std::vector<int> > > dataGroup);

/**
 * 训练函数(The training function)
 * @param datas 训练数据(training data)
 * @param tn    训练的目标(the target for training)
 */
void training(std::vector <std::vector<int> > datas, int tn);

/**
 * 识别测试(Identification test)
 * @param datas 数据(data)
 * @param tn    目标结果(target result)
 */
void test(std::vector <std::vector<int> > datas, int tn);

/**
 * 用随机数初始化权重W(Initialization weight data with random)
 */
void initW();