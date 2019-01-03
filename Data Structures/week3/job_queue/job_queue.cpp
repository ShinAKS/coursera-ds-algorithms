#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;

class assignthread{
	public:
		int threadno;
		long long time;
		assignthread(int x){
			threadno=x;
			time=0;
		}
};

class Compare{
	public:
		bool operator()(assignthread &a,assignthread &b){
			if (a.time==b.time)return a.threadno>b.threadno;
			else return a.time>b.time;
		}
		
};

/* As to why the above classes have been created, refer this link:
	https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
*/

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }
  
  void AssignJobsFaster(){
  	assigned_workers_.resize(jobs_.size());
  	start_times_.resize(jobs_.size());
  	priority_queue<assignthread,vector<assignthread>,Compare> pq;
  	for (int i=0;i<num_workers_;i++){
  		pq.push(assignthread(i));
	  }
	for (int j=0;j<jobs_.size();j++){
		assignthread x=pq.top();
		pq.pop();
		assigned_workers_[j]=x.threadno;
		start_times_[j]=x.time;
		x.time+=jobs_[j];
		pq.push(x);
	}
  	
  }

 public:
  void Solve() {
    ReadData();
    //AssignJobs();
    AssignJobsFaster();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
