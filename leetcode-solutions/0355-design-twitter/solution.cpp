class Twitter {
    //user_id --> list of follower id{}
    // int follower[500][500];
    vector<vector<int>> follower;
    vector<pair<int , int>> tweets;
    
public:
    
    Twitter() : follower(500 , vector<int>(500 , 0)) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // 0(1)
        tweets.insert(tweets.begin(), {userId, tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        // 0(n)
        vector<int> ans;
        for(auto tweet : tweets){

            if(ans.size() == 10) return ans;
            else{
                if(follower[userId][tweet.first] || tweet.first == userId) ans.push_back(tweet.second);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // 0(1)
        if(followerId == followeeId) return;
        follower[followerId][followeeId] = 1;
        return; 
    }
    
    void unfollow(int followerId, int followeeId) {
        // 0(1)
        follower[followerId][followeeId] = 0;
        return; 
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
