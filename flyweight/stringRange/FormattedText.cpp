#include"FormattedText.h"

#include<string>
#include<vector>


// bool BetterFormattedText::TextRange::covers(int position) const {
bool BetterFormattedText::TextRange::covers(int position) const {
	return position >= start && position <= end;
};


BetterFormattedText::BetterFormattedText(std::string str):plain_text{str}{};

BetterFormattedText::TextRange& BetterFormattedText::get_range(int start, int end) {
	formatting.emplace_back(TextRange{start, end}); 
	// We don’t really check duplicate ranges in the preceding 
	// implementation—something that would also be in the spirit of Flyweightbased space economy.
	return *formatting.rbegin();	
};

std::ostream& operator<<(std::ostream& os, const BetterFormattedText& obj){
	std::string s;

	for(size_t i = 0; i < obj.plain_text.length(); i++){
		auto c = obj.plain_text[i];
		for(const auto& rng: obj.formatting){
			if(rng.covers(i) && rng.capitalize){
				c = std::toupper(c);
				s += c;
			}
		}
	}
	return os << s;
}


