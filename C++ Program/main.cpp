#include <bits/stdc++.h>
using namespace std;

#define MAX 1300

int main()
{
	fstream f;
	f.open("E:\\TT\\c432.pat");
	if(!f.is_open())
		cout<<"Not opened\n";
	else
	{
		cout<<"File opened\n";
	}

	string line = "";
	int n = 0;
	vector<string> vs;
	while(getline(f, line))
	{
			n += 1;
			cout<<"Line : " << line << endl;
	//		n = std::stoi(line);
			int i=0, cnt=0;
			while(cnt < 3)
			{
				while(line[i] != ' ')
				{
					i += 1;
				}
				cnt += 1;
				i += 1;
			}

			vs.push_back(line.substr(i));
	}
	bool vis[MAX][MAX];
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			vis[i][j] = false;


	vector<pair<int, int> >same;
	cout<<"Total number of eligible single stuck-at faults:"<<n<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
				continue;
			if(vs[i][j] != vs[i][i])   // comarision of focus fault with fault under consideration
			{
				same.push_back(make_pair(i+1, j+1));
				vis[i][j] = true;
			}
		}
	}
	f.close();
	ofstream fout("E:\\TT\\c432_pot_undetected.txt");

	vector<pair<int, int> >::iterator it;
	for(it=same.begin(); it!=same.end(); it++)
		fout<<it->first<<","<<it->second<<endl;
	fout.close();

	ofstream fout3("E:\\TT\\c432_detected.txt");
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			if(vis[i][j] != vis[j][i] && vis[i][j] == true)
				fout3<<(i+1)<<","<<(j+1)<<endl;
		}
	}
	fout3.close();

	ofstream fout2("E:\\TT\\c432_undetected.txt");
	vector<pair<int, int> >::iterator it2;
	for(it=same.begin(); it!=same.end(); it++)
	{
		for(it2=it+1; it2!=same.end(); it2++)
		{
			if((it2->second == it->first) && (it2->first == it->second))
			{
			//	cout<<"here\n";
				fout2<<it->first<<","<<it->second<<endl;
				fout2<<it->second<<","<<it->first<<endl;
			}
		}
	}


//	for(it=diff.begin(); it!=diff.end(); it++)
//		fout2<<it->first<<","<<it->second<<endl;
	fout2.close();
	cout<<"Diff file closed\n";
	return 0;
}
