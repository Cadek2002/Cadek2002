#include <string>

class SAQuestion {
	string message;

public:
	class InvalidQuestionValueException {
		string what() {
		}
		InvalidQuestionValueException(string m = "ERROR: Invalid value. See class documentation.") {
			message = m;
		}
	};
	

};