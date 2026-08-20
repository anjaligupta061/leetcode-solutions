class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets; //time->tweetid
    unordered_map<int, unordered_set<int>> following; //1->2,3,5..........
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq;

        //User's own latest tweet
        if(!tweets[userId].empty()){
            int idx = tweets[userId].size()-1;

            auto[time, tweetId] = tweets[userId][idx];
            pq.push({time, tweetId, userId, idx});
        }

        //followers's feed

        for(int followee : following[userId]){
            if(!tweets[followee].empty()){
                int idx = tweets[followee].size() - 1;

                auto[time, tweetId] = tweets[followee][idx];
                pq.push({time, tweetId, followee, idx});
            }
        }

        //Final news feed
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            auto[time, tweetId, user, idx] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            if(idx>0){
                idx--;

                auto[prevTime, prevTweetId] = tweets[user][idx];

                pq.push({prevTime, prevTweetId, user, idx});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */