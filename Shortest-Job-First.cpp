// Note - Tasks will be executed only if they are sheduled means,
// when they are pushed into priority queue
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Total tasks = m
        int m = tasks.size();

        // MinHeap to store next task with minimum processing time
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<> > nextTask;

        // Sorted tasks bases upon there enqueue timing, processing time, index
        vector< array<int,3> > sortedTasks;

        // sorting tasks based on there enqueue time
        for(int i=0;i<m;i++) sortedTasks.push_back({tasks[i][0],tasks[i][1],i});

        sort(sortedTasks.begin(),sortedTasks.end());

        // Answer vector to be returned or the processingOrder vector
        vector<int> res;

        // Clock time ~ current
        long long currTime = 0;

        // Task index
        int index = 0;

        // Processor will keep executing tasks while there are some tasks
        // remained to be sheduled( means to push in to priority queue) or
        // or there are some tasks already remained in queue
        while( index < sortedTasks.size() || !nextTask.empty() ){

            // Ready queue is empty (no tasks present currently to execute)
            // Jump to that time where next task will come
            if( nextTask.empty() && currTime < sortedTasks[index][0] ){
                currTime = sortedTasks[index][0];
            }

            // Push all the tasks whose enqueueTime <= currtTime into the heap.
            while (index < sortedTasks.size() && currTime >= sortedTasks[index][0]) {
                nextTask.push({sortedTasks[index][1], sortedTasks[index][2]});
                ++index;
            }

            auto [processTime, indexx] = nextTask.top();
            nextTask.pop();

            // Complete this task and increment currTime.
            currTime += processTime;
            res.push_back(indexx);

        }

        return res;
    }
};
