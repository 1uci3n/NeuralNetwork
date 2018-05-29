#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


/**
 * 从文件中获取数据样本(get the sample data from file)
 * 
 * @param  filepath 文件路径(file's path)
 * @return          包含数据样本的向量,样本数据组< 单个的样本数据 <样本数据的行> > >(Vector containing sample data,arrary of sample data< sample data <row of sample data> >)
 */
std::vector<std::vector <std::vector<int> > > getFormatDataGroupFromFile(std::string filepath);

std::vector<std::vector<int> > formatDataToOneRow(std::vector<std::vector <std::vector<int> > > dataGroup);

void training(std::vector <std::vector<int> > datas, int tn);

void test(std::vector <std::vector<int> > datas, int tn);