// This is basically a K-way merge. Although we simplify it here
// since we know there are 10 tweets max per person, and a maximum
// of 500 people.
//
// For an arbitrarily large set of people and number of tweets,
// we want to use hashmaps/hashsets rather than arrays, and a
// K-way merge using a priority queue rather than an insertion sort.
class Twitter {
  // Pair of (ts, id). Using std::pair rather than custom struct
  // so that we have a default comparator.
  using Tweet = std::pair<int, int>;

  static constexpr int MAX_USERS = 500;
  static constexpr int FEED_SIZE = 10;

  // A simple circular buffer.
  class Tweets {
    std::array<Tweet, FEED_SIZE> tweets_{};
    int cur_index{};

  public:
    void push(Tweet &&t) {
      tweets_[cur_index] = std::move(t);
      cur_index = (cur_index + 1) % FEED_SIZE;
    }

    std::array<Tweet, FEED_SIZE> get() { return tweets_; }
  };

  bool followers_[MAX_USERS + 1][MAX_USERS + 1]{};
  Tweets tweets_[MAX_USERS + 1]{};

  int ts_{};

public:
  Twitter() {
    // Each person should follow themself.
    for (int i{1}; i <= MAX_USERS; ++i) {
      follow(i, i);
    }
  }

  void postTweet(int userId, int tweetId) {
    tweets_[userId].push({++ts_, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    // Basically a K-way merge. Simply done with an insertion sort.
    Tweet feed[FEED_SIZE]{};
    for (int followee{1}; followee <= MAX_USERS; ++followee) {
      if (!followers_[userId][followee]) {
        continue;
      }
      for (const auto &tweet : tweets_[followee].get()) {
        if (!tweet.first) {
          break;
        }

        // Insertion sort.
        int i{};
        while (i < FEED_SIZE && feed[i].first >= tweet.first) {
          ++i;
        }
        if (i < FEED_SIZE) {
          for (int j{FEED_SIZE - 1}; j > i; --j) {
            feed[j] = feed[j - 1];
          }
          feed[i] = tweet;
        }
      }
    }

    // Extract timestamps from feed.
    std::vector<int> res;
    for (const auto [ts, tweet_id] : feed) {
      if (!ts) {
        break;
      }
      res.push_back(tweet_id);
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    followers_[followerId][followeeId] = true;
  }

  void unfollow(int followerId, int followeeId) {
    followers_[followerId][followeeId] = false;
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
