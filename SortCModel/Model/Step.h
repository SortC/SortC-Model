#include <string>
#include <vector>

using namespace std;
enum operation {swap,  };

class Step
{
public:
	Step(vector<int> values, operation operation, unsigned int number, string explantion);
	
	Step(vector<int> values, operation operation, unsigned int number);
	
	~Step(void);


private:
	vector<int> values;
	operation op;
	int number;
	string explantion;
};

