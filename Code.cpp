#include<queue>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

cclass PCS  
{
public:
int preference;
int processNo;
int tBurst;
int tArrival;
int tRemaining;
int x;
int y;
};
struct checkMe
{
bool operator()(const PCS& a, const PCS& b) const
{
int temp1=a.preference;
int temp2=b.preference;
bool temp3;
temp3=temp1 > temp2;
return temp3;
}
};
int main()
{
int NOP,sum;
sum=0;
cin>>NOP;
int pid=0,arrivalTime=0;
int burstTime=0,preference=0,m=0;
PCS* que=(PCS*)malloc(sizeof(PCS)*(NOP+1));
int slice=0,number=0;
int timeSlice=4,remSlice=4;
int tt=0;
int* view=(int *)malloc(sizeof(int)*1010);		
memset(view,0,1010);
priority_queue<PCS, vector<PCS>, checkMe> queue1;
queue<PCS> queue2;
while(m<NOP)
{
cin>>pid;
cin>>arrivalTime;
cin>>burstTime;
cin>>preference;
que[m].preference=preference;
que[m].processNo = pid;
que[m].tBurst=burstTime;
que[m].tArrival=arrivalTime;
que[m].tRemaining=burstTime;
sum +=burstTime;
m++;
}
m=0;
while(m<NOP)
{
int n=0;
while(n<NOP)
{
if(que[m].tArrival<que[n].tArrival)
{
int identity=0,arrival=0,burst=0,tpriority=0,remaining=0;
identity = que[m].processNo;
arrival = que[m].tArrival;
burst = que[m].tBurst;
tpriority=que[m].preference;
remaining = que[m].tRemaining;
que[m].processNo=que[n].processNo;
que[m].tArrival = que[n].tArrival;
que[m].tBurst  = que[n].tBurst;
que[m].preference = que[n].preference;
que[m].tRemaining = que[n].tRemaining;
que[n].processNo=identity;
que[n].tArrival = arrival;
que[n].tBurst  = burst;
que[n].preference = tpriority;
que[n].tRemaining = remaining;
}
n++;
}
m++;
}
while((number<NOP)||(queue2.empty()==false)||(queue1.empty()==false)||(tt==0))
{
while((number<NOP) && (que[number].tArrival==slice))
{
int temp1=que[number].preference;
if(timeSlice!=4&&(temp1<queue1.top().preference))
{
queue2.push(queue1.top());
queue1.pop();
timeSlice=4;
}
PCS var=que[number];
queue1.push(var);
number++;
tt=1;
}
if(queue1.empty()==false)
{
if((remSlice!=4)&&(queue2.empty()==false))
{
PCS tempp=queue2.front();
queue2.push(tempp);
remSlice=4;
queue2.pop();
}
PCS cur = queue1.top();
view[slice]=cur.processNo;
cur.tRemaining--;
queue1.push(cur);
queue1.pop();
timeSlice--;
if(queue1.top().tRemaining==0)
{
queue1.pop();
timeSlice=4;
}
else if(timeSlice==0)
{	
int z=queue1.top().tRemaining;	
if(z>0)
{
queue2.push(queue1.top());
}
queue1.pop();
timeSlice=4;
}
}
else if(queue2.empty()==false)
{
queue2.front().tRemaining--;
int temp3=queue2.front().processNo;
view[slice]=temp3;
remSlice=remSlice-1;
if(queue2.front().tRemaining==0)
{
queue2.pop();
remSlice=4;
}
else if(remSlice==0)
{
PCS temp=queue2.front();
queue2.push(temp);
queue2.pop();
remSlice=4;
}
}	
slice++;
}
int d=0;
while(d<NOP)
{
int tt=0;
int curpid = que[d].processNo;
int c=0;
while(c<slice)
{
if(view[c]==curpid)
{
if(tt!=0)
{
que[d].y=c+1;
}
else
{
que[d].x=c;
tt=1;
}
}
c++;
}
d++;
}
int p=0;
while(p<NOP)
{
int q=0;
while(q<NOP)
{
if(que[p].processNo<que[q].processNo)
{
int identity=0,arrival=0,burst=0,tpriority=0,remaining=0,t1=0,t2=0;
tpriority=que[p].preference;
identity = que[p].processNo;
burst = que[p].tBurst;
arrival = que[p].tArrival;
t2 = que[p].y;
remaining = que[p].tRemaining;
t1 = que[p].x;
que[p].preference = que[q].preference;
que[p].processNo=que[q].processNo;
que[p].tBurst  = que[q].tBurst;
que[p].tArrival = que[q].tArrival;
que[p].y=que[q].y;
que[p].tRemaining = que[q].tRemaining;
que[p].x=que[q].x;
que[q].preference = tpriority;
que[q].processNo=identity;
que[q].tBurst=burst;
que[q].tArrival=arrival;
que[q].y=t2;
que[q].tRemaining = remaining;
que[q].x=t1;
}
q++;
}
p++;
}
int k=0;
cout<<"Output:";
while(k<NOP)
{
int processNum=0,remaining=0;
int wtime=0,ftime=0,temp=0;
remaining =(que[k].x)-(que[k].tArrival);
processNum=que[k].processNo;
temp=(que[k].y)-(que[k].tArrival);
wtime =temp - que[k].tBurst;
ftime=que[k].y;
cout<<endl<<processNum<<" ";
cout<<remaining<<" ";
cout<<ftime<<" ";
cout<<wtime;
k++;
}
cout<<endl;
}	


