class Solution {
  using VVI = std::vector<std::vector<int>>;

public:
  // At first glance, this feels like a topological
  // sort problem. We have directed edges given by a set
  // of constraints. Thoughts:
  // - The person i in front must have k_i == 0.
  // - If a person has k_i == 0, then it doesn't matter if
  //   there are any people in front with a shorter height.
  //   I.e., the partial order is not defined between these
  //   two people, and thus there may be no total order defined
  //   (which again feels like a topological sort).
  //
  // Thus, we proceed as follows:
  // 1. Gather all people who have k == 0.
  // 2. Choose the shortest person who has k == 0.
  // 3. Decrease the k of anybody remaining who is taller.
  // 4. Repeat step 2 until there are no people left.
  //
  // Note that for the people who have k == 0, we have to go
  // from shortest to tallest. E.g., if we have two people
  // with k == 0 and the first person has height 1 and the
  // second person has height 2, then putting the second person
  // first would make the first person's k==1, which would be
  // a contradiction. To keep the indegree zero people sorted,
  // we use a priority queue.
  //
  // This algorithm is O(n*log(n) + n^2) = O(n^2) time
  // (we add each person to the priority queue once, and we loop
  // over all people for each person once they have k == 0).
  // It is O(n) space.
  //
  // There are neater and more clever ways of doing this:
  // @StefanPochmann has a beautiful solution as usual with
  // a sort+insert algorithm. It is still O(n^2) time and O(1)
  // space but it is much more elegant.
  VVI reconstructQueue(VVI &people) {
    int n(people.size());

    // Use a priority queue to keep track of the indegree zero elements
    // since we need to keep them sorted. Each element of the priority
    // queue is a std::pair of the height and the index of the person.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;

    // Get people with indegree zero.
    for (int i{}; i < n; ++i) {
      auto h{people[i][0]}, k{people[i][1]};

      // Store the original value of k at people[i][k], since
      // we will be modifying k (k is used as the indegree value
      // and it will change over time).
      people[i].push_back(k);

      // Add initial people with indegree 0 to the priority queue.
      if (!k) {
        pq.push({h, i});
      }
    }

    // Topological sort.
    VVI res;
    while (pq.size()) {
      auto [unused, ind] = pq.top();
      pq.pop();

      // Get the person's height and original k.
      auto h{people[ind][0]}, k{people[ind][2]};
      res.push_back({h, k});

      // Find people who are shorter, and decrease their k (indegree).
      for (int j{}; j < n; ++j) {
        if (j == ind || people[j][0] > h) {
          continue;
        }
        if (!--people[j][1]) {
          pq.push({people[j][0], j});
        }
      }
    }
    return res;
  }
};
