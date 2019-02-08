#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include "Job.h"

#define ID 5361

using namespace std;

vector<Job> rand_list();
vector<Job> bhz_list();
int circular(unsigned int, vector<Job>);
int priority(unsigned int, vector<Job>);
int get_i(int*, int);
double mean(vector<int>);
double stdev(vector<int>, double);

int main(void){

    srand(time(nullptr)); // use current time for rand seed
    
    // Define number of processors
    int processors = ID%3 + 2;

    vector<int> stats;
    for(int i=0;i<100;++i){
        vector<Job> current_list = rand_list();
        stats.push_back(circular(processors, current_list) );
    }
    double stat_mean = mean(stats);

    cout << "CIRCULAR ALGORITHM" << endl;
    cout << "__STATS FOR RANDOM SCHEDULES__" << endl;
    cout << "Minimum: " << *min_element(begin(stats), end(stats)) << endl;
    cout << "Maximum: " << *max_element(begin(stats), end(stats)) << endl;
    cout << "Mean: " << stat_mean << endl;
    cout << "Standard Deviation: " << stdev(stats, stat_mean) << endl; 

    cout << "Total turnaround time for BHZ case: " << 
        circular(processors, bhz_list()) << endl << endl;

    cout << "MY ALGORITHM" << endl;
        
    stats.clear();
    for(int i=0;i<100;++i){
        vector<Job> current_list = rand_list();
        stats.push_back(priority(processors, current_list) );
    }
    stat_mean = mean(stats);

    cout << "__STATS FOR RANDOM SCHEDULES__" << endl;
    cout << "Minimum: " << *min_element(begin(stats), end(stats)) << endl;
    cout << "Maximum: " << *max_element(begin(stats), end(stats)) << endl;
    cout << "Mean: " << stat_mean << endl;
    cout << "Standard Deviation: " << stdev(stats, stat_mean) << endl; 
    
    cout << "Total turnaround time for BHZ case: " <<
        priority(processors, bhz_list()) <<endl;

    return 0;
}

// Generate list of jobs.
vector<Job> rand_list(){
    vector<Job> list;
    for(int i=0;i<100;i++){
        int ptime=rand()%499 + 1;
        list.push_back(Job(i,ptime)); 
    }
    return list;
}

// Generate BHZ's list
vector<Job> bhz_list(){
    vector<Job> list;
    list.push_back(Job(4,9));
    list.push_back(Job(15,2));
    list.push_back(Job(18,16));
    list.push_back(Job(20,3));
    list.push_back(Job(26,29));
    list.push_back(Job(29,198));
    list.push_back(Job(35,7));
    list.push_back(Job(45,170));
    list.push_back(Job(57,180));
    list.push_back(Job(83,178));
    list.push_back(Job(88,73));
    list.push_back(Job(95,8));
    
    return list;
}   

// Scheduling procedure.
int circular(unsigned int num_proc, vector<Job> list){
    int turnaround = 0; // total turnaround time
    int first = list[0].m_a_time; // arrival time of first job
    int jobs[num_proc] = {0}; // total processing time per processor
   
    for(unsigned int i=0; i<list.size(); ++i){
        turnaround++; // increment for scheduling time
        // Handle the case in which a processor has time unused
        if(list[i].m_a_time > jobs[i%num_proc]){
            jobs[i%num_proc] = list[i].m_a_time;
        }
        jobs[i%num_proc] += list[i].m_p_time;
    }

    return turnaround + *max_element(jobs, jobs + num_proc) - first;
}

// My procedure schedules new processes to the LEAST booked processor.
int priority(unsigned int num_proc, vector<Job> list){
    int turnaround = 0;
    int first = list[0].m_a_time;
    int jobs[num_proc] = {0};

    for(unsigned int i=0; i < list.size(); ++i){
        turnaround ++;
        if(list[i].m_a_time > jobs[i%num_proc]){
            jobs[i%num_proc] = list[i].m_a_time;
        }
        jobs[get_i(jobs,num_proc)] += list[i].m_p_time;
    }
    return turnaround + *max_element(jobs, jobs + num_proc) - first;
}

// Find index of lowest number in vector
int get_i(int* list, int size){
    int i = 0;
    int min = INT_MAX;
    for(int j=0; j<size; j++){
        if(list[j] < min){
            min = list[j];
            i = j;
        }
    }
    return i;
}
// Calculate mean
double mean(vector<int> stats){
    int sum = 0;
    vector<int>::iterator i;
    for(i = stats.begin(); i != stats.end(); ++i){
        sum += *i;
    }
    return (double) sum/stats.size(); 
}

// Calculate standard dev
double stdev(vector<int> stats, double mean){
    int sum = 0;
    vector<int>::iterator i;
    for(i = stats.begin(); i != stats.end(); ++i){
        sum += pow(*i - mean, 2);
    }
    return sqrt((double)sum / stats.size());
}
