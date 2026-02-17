#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two indices such that nums[i] + nums[j] == target
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> num_map;
	for (int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];
		if (num_map.find(complement) != num_map.end()) {
			return {num_map[complement], i};
		}
		num_map[nums[i]] = i;
	}
	return {};
}

int main() {
	int n, target;
	cout << "Enter number of elements: ";
	cin >> n;
	vector<int> nums(n);
	cout << "Enter elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	cout << "Enter target: ";
	cin >> target;
	vector<int> result = twoSum(nums, target);
	if (!result.empty()) {
		cout << "Indices: " << result[0] << " " << result[1] << endl;
	} else {
		cout << "No solution found. try again" << endl;
	}
	return 0;
}
