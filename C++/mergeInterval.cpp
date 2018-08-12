/*
合并区间问题：
输入：
3
1,10;32,45
78,94;5,16
80,100;200,220;16,32

输出：
1,45;78,100;200,220
*/ 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctype.h>
#include<stdio.h>

using namespace std;
  
class Interval{  
public:  
    long long start, end;  
    //新定义的结构体属性;  
    Interval(const long long &a, const long long &b) :start(a), end(b){}; 
    bool operator<(const Interval &a){  
		return start < a.start;
    }
};  

class Solution{
public:
    static bool LessSort(Interval a,Interval b){
        return a.start<b.start;
    }
    vector<Interval> merge1(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), LessSort);
        long long len = intervals.size();
        vector<Interval> res;
        long long start(0);
        long long end(0);
        for (long long i = 0; i < len;){
            start = intervals[i].start;
            end = intervals[i].end;
            long long j = i + 1;
            for (; j < len; ++j){
                if (end < intervals[j].start) break;
                end = max(end, intervals[j].end);
			}
            res.push_back(Interval(start, end));
            i = j;
        }
        return res;
    }
    
    vector<Interval> merge2(vector<Interval>& intervals){
        if(intervals.size()<=1)
            return intervals;
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),LessSort);
        long long left = intervals[0].start;
        long long right = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<=right){
                right = max(intervals[i].end,right);
            }
            else{
                result.push_back(Interval(left,right));  
                left = intervals[i].start;
                right = intervals[i].end;  
            }
        }
        result.push_back(Interval(left,right));
        return result;
    }
    vector<Interval> merge3(vector<Interval>& ins) {
	    if (ins.empty()) return vector<Interval>{};
	    vector<Interval> res;
	    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
	    res.push_back(ins[0]);
	    for (int i = 1; i < ins.size(); i++) {
	        if (res.back().end < ins[i].start) res.push_back(ins[i]);
	        else
	            res.back().end = max(res.back().end, ins[i].end);
	    }
	    return res;
	}
};

void SplitString(const string& s, vector<string>& v, const string& c){
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2){
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
    if (pos1 != s.length())
    v.push_back(s.substr(pos1));
}

int main(){
	long long n;
	cin>>n;
	vector<Interval> intervals;
    for(size_t i = 0; i < n; ++i){
        string line;
        cin >> line; 
        vector<string> v;
        SplitString(line, v, ";");
        long long num = v.size();
        for(size_t j = 0; j < num; ++j){
            vector<string> pair;
            SplitString(v[j], pair, ",");
            Interval x(strtoll(pair[0].c_str(), NULL, 10), strtoll(pair[1].c_str(), NULL, 10));
            intervals.push_back(x);
		}
	}
	
	//for(size_t i = 0; i<intervals.size(); ++i){
    //    cout << intervals[i].start << ',' << intervals[i].end<<endl;
    //}
	
	Solution solver;
	//vector<Interval> result = solver.merge1(intervals);
	//vector<Interval> result = solver.merge2(intervals);
	vector<Interval> result = solver.merge3(intervals);

    long long len = result.size();
    for(size_t i = 0; i<len; ++i){
        cout << result[i].start << ',' << result[i].end;
        if(i != len - 1) cout<<';';
    }
	return 0;
}


