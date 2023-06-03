#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program){
	std::unordered_map<std::string, int> result;
	std::string command;
	std::string variable;
	
	for (int i = 0; i < program.size(); i++) {

		command = program[i].substr(0, 3);
		variable = program[i].substr(4, 1);

		if (command == "mov") {
			if (program[i][6] - int('a') >= 0 && program[i][6] - int('a') < 26) result[variable] = result[program[i].substr(6, 1)];
			
			else result[variable] = std::stoi(program[i].substr(6));
			
		}
		else if (command == "inc") result[variable]++;
		
		else if (command == "dec") result[variable]--;
		
		else if(command == "jnz" && result.find(variable) != result.end()) {
			
			if (result[variable] == 0) continue;
			
			if (result.find(program[i].substr(6)) == result.end()) i += std::stoi(program[i].substr(6));
			
			else i += result[variable];
			
			i--;
		}
		else if (command == "jnz" && variable != "0") {

			if (result.find(program[i].substr(6)) == result.end()) i += std::stoi(program[i].substr(6));
			
			else i += result[variable];
			
			i--;
		}
	}
	return result;
}
