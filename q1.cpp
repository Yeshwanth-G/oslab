#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include<queue>
#include <unordered_map>
#define mod 998244353
using namespace std;
int main()
{
  int n = 5, b, a;
  vector<pair<int, int>> v;
  vector<pair<int,int>>ar;
  vector<pair<int,int>>bt;
  for (int i = 0; i < n; i++)
  {
    cin >> b >> a;
    pair<int, int> p = make_pair(a, b);
    v.push_back(p);
    pair <int,int>p1=make_pair(a,i);
    ar.push_back(p1);
    pair <int,int>p2=make_pair(a,b);
    bt.push_back(p2);
  }
    sort(bt.begin(),bt.end());

  sort(ar.begin(),ar.end());
  vector<int> cmp(n);
  vector<int>trn(n);//cmp-a
  vector<int>wt(n);//trn-bt
 
  int qm;
  cin >> qm;
  sort(v.begin(), v.end());
  int it = 0;
  queue<int> q;
  int t = v[0].first;
  int temp;
  while (it < n || !q.empty())
  {
    if (q.empty() && it < n)
    {
      q.push(it);
      it++;
    }
    if (!q.empty())
    {
      temp = v[q.front()].second;
    }
    while (it<n&&v[it].first <= t + min(temp, qm))
    {
      q.push(it);
      it++;
    }
    int s=v[q.front()].second;
    v[q.front()].second = v[q.front()].second - qm;
    if (v[q.front()].second <= 0)
    {
      int temp = q.front();
      q.pop();
      cmp[temp] = t+min(qm,s);
      t =t+min(qm,s);
    }
    else
    {
      int temp = q.front();
      q.pop();
      q.push(temp);
      t =t+min(qm,s);
    }
  }
  int atrn=0,awt=0;
  for(int i=0;i<n;i++)
  {
    trn[i]=cmp[i]-v[i].first;
    atrn+=trn[i];
    wt[i]=trn[i]-bt[i].second;
    awt+=wt[i];
  }
  cout<<"Process\t"<<"TurnAround:\t"<<"Waiting Time:"<<endl;;
  for(int i=0;i<n;i++){
    cout<<"P"<<ar[i].second+1<<"\t\t"<<trn[i]<<"\t\t"<<wt[i]<<endl;
  }
  cout<<"Average Turn Around Time:"<<atrn/5.0<<endl<<"Average Waiting Time:"<<awt/5.0<<endl;;
  return 0;
}
