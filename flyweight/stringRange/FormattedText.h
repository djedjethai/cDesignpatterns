#ifndef FORMATTEDTEXT_H
#define FORMATTEDTEXT_H

#include <cctype>
#include<iostream>
#include <ostream>
#include<string>
#include<vector>

class BetterFormattedText{
public:
	struct TextRange{
		int start, end;
		bool capitalize;
		// other options here, e.g. bold, italic, etc.

 		bool covers(int position) const;
	};

	BetterFormattedText(std::string str);

	TextRange& get_range(int start, int end);

	friend std::ostream& operator<<(std::ostream& os, const BetterFormattedText& obj);

private:
	std::string plain_text;
	std::vector<TextRange> formatting;
	
};

#endif
