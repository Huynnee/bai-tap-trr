#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define max 10

struct adj
{
	int str;
	int end;
};

typedef adj adja;
adja temp[20];


int data[max][max] = {0};
int socanh = 0, sodinh;

void nhap() {
	ifstream ifs("input2_1.txt");
	string str;
	getline( ifs, str );
	istringstream buffer(str);
	buffer >> sodinh >> socanh;
	for (int i = 1; i <= sodinh; i++)
	{
		getline( ifs, str );
		istringstream buffer(str);
		int val;
		while (!buffer.eof())
		{

			buffer >> val;
			data[i][val] = 1;
		}
	}
}

void DSCanh()
{
	ofstream ofs("output2_1.txt");
	ofs << sodinh << "\t" << socanh << endl;
	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= max; j++)
		{
			if (data[i][j] == 1)
			{
				ofs << i << "\t" << j;
				ofs << "\n";
			}
		}
	}

}


void MaTranKe()
{
	ofstream ofs("output2_1.txt");
	ofs << sodinh << endl;
	for (int i = 1; i <= sodinh; i++)
	{
		for (int j = 1; j <= sodinh; j++)
		{
			ofs << data[i][j] << "\t";
		}
		ofs << "\n";
	}
}

void CanhMaTran()
{
	int count = 0;
	for (int i = 1; i <= max; i++)
	{
		for ( int j = 1; j <= max; j++ )
		{
			if (data[i][j] == 1)
			{
				count++;
				temp[count].str = i;
				temp[count].end = j;
			}
		}
	}
}

void MaTranDinhCanh()
{
	CanhMaTran();
	ofstream ofs("output2_1.txt");
	ofs << sodinh << "\t" << socanh << endl;
	for (int i = 1; i <= sodinh; i++)
	{
		for (int j = 1; j <= socanh; j++)
		{
			if (i == temp[j].str) ofs << "  1";
			else if (i == temp[j].end) ofs << " -1";
			else ofs << "  0";
			ofs << " ";
		}
		ofs << "\n";
	}
}

int main(int argc, char const *argv[])
{
	nhap();
	MaTranKe();
	DSCanh();
	MaTranDinhCanh();
	return 0;
}
