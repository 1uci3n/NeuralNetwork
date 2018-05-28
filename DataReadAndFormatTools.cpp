/*
* @Author: 1uci3n
* @Date:   2018-05-27 19:06:06
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-05-28 13:27:54
*/
#include "NeuralNetwork.h"

using namespace std;

vector<vector <vector<int> > > getFormatDataGroupFromFile(string filepath){
	//用来存储多组手写数字
	vector<vector <vector<int> > > formatDataGroup;
	//存储一个手写数字,按行存储
	vector< vector<int> > formatData;
	//
	vector<int> row(16);
	vector<vector <int> >::iterator dataEnd = formatData.end();
	vector<vector <vector<int> > >::iterator groupEnd = formatDataGroup.end();
	vector<int> *p = new vector<int>;
	ifstream infile(filepath);
	if (!infile.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	int number;
	while(! infile.eof())
	{
		infile >> number;
		p->push_back(number);
	}
	p->pop_back();
	int index = 0;
	int rowSum = 0;
	for (vector<int>::iterator i = p->begin(); i != p->end(); ++i)
	{
		row[index] = *i;
		index++;
		if(index == 16){
			index = 0;
			formatData.insert(dataEnd, row);
			rowSum++;
			if(rowSum == 16){
				rowSum = 0;
				formatDataGroup.insert(groupEnd, formatData);
				groupEnd = formatDataGroup.end();
				formatData.clear();
			}
			dataEnd = formatData.end();
		}
	}
	//cout << ((formatDataGroup.at(0)).at(0)).at(0) << endl;
	return formatDataGroup;
}