class Solution {
public:
  int numTriplets(vector<int> &nums1, vector<int> &nums2) {

    // store all of the left in a histogram hashmap
    unordered_map<long, int> n1h;
    unordered_map<long, int> n1sh;
    for (int i = 0; i < nums1.size(); ++i) {
      n1h[nums1[i]]++;
      n1sh[(long)nums1[i] * nums1[i]]++;
    }

    // store squares of all the right in a histogram hashmap
    unordered_map<long, int> n2h;
    unordered_map<long, int> n2sh;
    for (int i = 0; i < nums2.size(); ++i) {
      n2h[nums2[i]]++;
      n2sh[(long)nums2[i] * nums2[i]]++;
    }

    // iterate over the left hashmap, try to find matches in right hashmap
    int numTrips = 0;
    for (int i = 1; i < nums1.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        // cout << nums1[i] << " " << nums1[j] << " " << n2sh[nums1[i] *
        // nums1[j]] << endl;
        numTrips += n2sh[(long)nums1[i] * nums1[j]];
      }
    }

    // cout << endl;
    for (int i = 1; i < nums2.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        // cout << nums2[i] << " " << nums2[j] << " " << n1sh[nums2[i] *
        // nums2[j]] << endl;
        numTrips += n1sh[(long)nums2[i] * nums2[j]];
      }
    }

    //         for (auto it = n1h.begin(), end = n1h.end(); it != end; ++it) {
    //             for (auto it2 = n1h.begin(); it2 != end; ++it2) {
    //                 cout << it->first << " " << it2->first << endl;
    //                 if (it->first == it2->first)
    //                     continue;
    //                 // try to find match
    //                 numTrips += it->second * it2->second * n2sh[it->first *
    //                 it2->first]; if (it->second * it2->second *
    //                 n2sh[it->first * it->second] > 0)
    //                     cout << (it->first) << " " << (it2->first) << " " <<
    //                     (it->second * it2->second * n2sh[it->first *
    //                     it2->first]) << endl;
    //             }
    //         }

    //         for (auto it = n2h.begin(), end = n2h.end(); it != end; ++it) {
    //             for (auto it2 = n2h.begin(); it2 != end; ++it2) {
    //                 if (it->first == it2->first)
    //                     continue;
    //                 // try to find match
    //                 numTrips += it->second * it2->second * n1sh[it->first *
    //                 it2->first]; if (it->second * it2->second *
    //                 n1sh[it->first * it->second] > 0)
    //                     cout << (it->first) << " " << (it2->first) << " " <<
    //                     (it->second * it2->second * n1sh[it->first *
    //                     it2->first]) << endl;
    //             }
    //         }

    return numTrips;
  }
};
