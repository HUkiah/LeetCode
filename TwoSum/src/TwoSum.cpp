//============================================================================
// Name        : TwoSum.cpp
// Author      : ukiah
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> value;

        for(int i=0;i<nums.size();i++){
            for(int j=nums.size()-1;j>i;j--){
            if(target==nums[j]+nums[i]){
                value.push_back(i);
                value.push_back(j);
            }
            }
        }
        return value;//错误处理
    }
};

int main() {

	vector<int> b{1,2,4,5};
	Solution *sa=new Solution();

	for(auto i : sa->twoSum(b,6)){
		cout<<i<<"--";
	}
	cout<<endl;
	return 0;
}
