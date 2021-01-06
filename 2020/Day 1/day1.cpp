# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <algorithm> 


std::vector<int> readFile(std::string file) 
{
	// Out vector
	std::vector<int> out;

	// Instantiate input file and open file 
	std::ifstream inFile;
	inFile.open(file);

	// Read file line by line as int and push into result vector
	int count;
	while (inFile >> count) {
		out.push_back(count);
	}

	// Close and return vector
	inFile.close();
	return out;
}


int combinations(std::vector<int>& input, int count) {
	std::vector<bool> mask(input.size());
	std::fill(mask.end() - count, mask.end(), true);
	do {
		int temp = 0;
		int result = 1;
		for (int i = 0; i < input.size(); ++i) {
			if (mask[i]) {
				temp += input[i];
				result *= input[i];
			}
		}
		if (temp == 2020) {
			return result;
		}
	} while (std::next_permutation(mask.begin(), mask.end()));
	return 0;
}


int main() {
	std::vector<int> expenseReport = readFile("src/2020/Day 1/input1.txt");
	int first = combinations(expenseReport, 2);
	int second = combinations(expenseReport, 3);
	std::cout << first << second;
	
}