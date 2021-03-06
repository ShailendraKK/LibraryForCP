#include <algorithm>
#include <regex>
#include <sstream>
#include <vector>

namespace string_helper {
	std::vector<std::string> split(const std::string& str,
								   const char separator) {
		std::vector<std::string> results;
		std::stringstream iss(str);
		std::string token;
		while (std::getline(iss, token, separator)) {
			if (not token.empty()) results.push_back(token);
			token = "";
		}
		return results;
	}

	std::vector<std::string> regexSplit(const std::string& str,
										const std::regex& pattern) {
		std::vector<std::string> results;
		std::copy(
			std::sregex_token_iterator(str.begin(), str.end(), pattern, -1),
			std::sregex_token_iterator(), std::back_inserter(results));
		return results;
	}
}  // namespace string_helper
