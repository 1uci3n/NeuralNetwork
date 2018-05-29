/*
* @Author: 1uci3n
* @Date:   2018-05-28 16:36:26
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-05-29 13:04:32
*/
#include "NeuralNetwork.h"

#define TRAINING_DATA_COUNT 100
#define T_FOR_ZERO -1
#define T_FOR_ONE 1
#define ERROR_BOUND 1

using namespace std;

//initial weight value
vector<double> w(256, 0);

int main(int argc, char const *argv[])
{
	//get the data(The first 100 are samples, the remaining 60 are tests)
	vector<vector <vector<int> > > data0 = getFormatDataGroupFromFile("sample/data0.dat");
	vector<vector <vector<int> > > data1 = getFormatDataGroupFromFile("sample/data1.dat");
	vector<vector<int> > formatData0 = formatDataToOneRow(data0);
	vector<vector<int> > formatData1 = formatDataToOneRow(data1);
	cout << "----訓練スタート----" << endl;
	cout << "0の訓練スタート" <<endl;
	training(formatData0, T_FOR_ZERO);
	cout << "1の訓練スタート" <<endl;
	training(formatData1, T_FOR_ONE);
	cout << "----識別スタート----" << endl;
	cout << "0の";
	test(formatData0, T_FOR_ZERO);
	cout << "1の";
	test(formatData1, T_FOR_ONE);
	return 0;
}

void training(vector <vector<int> > datas, int tn){
	vector<int> data;
	vector<int> errorIndex;
	int countError = 0;
	double errorSum = 0;
	vector<int>::iterator it = errorIndex.end();
	double result = 0;
	while(true){
		for (int i = 0; i < TRAINING_DATA_COUNT; ++i)
		{
			data = datas[i];
			for (int j = 0; j < 256; ++j)
			{
				result += data[j] * w[j];
			}
			if ((result * tn) < 0)
			{
				errorIndex.insert(it, i);
				it = errorIndex.end();
			}
			result = 0;
		}

		for (vector<int>::iterator i = errorIndex.begin(); i != errorIndex.end(); ++i)
		{
			data = datas[*i];
			for (int j = 0; j < 256; ++j)
			{
				w[j] += tn * data[j];
				errorSum += data[j] * w[j];
			}
			errorSum = abs(errorSum);
		}
		cout << "誤りは" << errorIndex.size() << "個" << endl;
		if(((errorSum/errorIndex.size()) < ERROR_BOUND) || errorIndex.size() == 0){
			break;
		}
		errorSum = 0;
		vector <int>().swap(errorIndex);
		it = errorIndex.end();
	}	
}

void test(vector <vector<int> > datas, int tn){
	vector<int> data;
	double result = 0;
	double sumErr = 0;
	for (int i = TRAINING_DATA_COUNT; i < 160; ++i)
	{
		data = datas[i];
		for (int j = 0; j < 256; ++j)
		{
			result += data[j] * w[j];
		}
		if((result * tn) < 0){
			sumErr ++;
		}
		//cout << result << endl;
		result = 0;
	}
	cout << "識別の誤り率は" << sumErr / 60 << endl;
}

