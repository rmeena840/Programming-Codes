#include<bits/stdc++.h>
using namespace std;

class Point{
	int x;
	int y;
	public: 
		Point(int _x,int _y){
			x=_x;
			y=_y;
		}
		int getX() const {return x;}
		int getY() const {return y;}
};

class myComparator{
	public:
		int operator() (const Point& p1,const Point& p2){
			return p1.getX()>p2.getX();
		}
};

int main(void){
	
	cout<<"Max Heap:\n";
	//Max Heap
	priority_queue<int> p;
	p.push(1);
	p.push(2);
	p.push(3);
	cout<<p.top();
	p.pop();
	cout<<p.top();
	p.pop();
	cout<<p.top();
	p.pop();
	
	cout<<"\nMin Heap:\n";
	//Min Heap
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<q.top();
	q.pop();
	cout<<q.top();
	q.pop();
	cout<<q.top();
	q.pop();
	
	cout<<"Class Min Heap"<<endl;
	//Min heap of points
	priority_queue<Point,vector<Point>,myComparator > z;
	z.push(Point(10,2));
	z.push(Point(2,1));
	z.push(Point(1,5));
	while(!z.empty()){
		Point A=z.top();
		cout<<A.getX()<<" "<<A.getY()<<endl;
		z.pop();
	}
	return 0;
}
