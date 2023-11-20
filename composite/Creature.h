#ifndef CREATURE_H
#define CREATURE_H

#include<array>
#include<numeric>
#include<algorithm>

class Creature{
	enum Abilities{str, agl, intl, count};
	std::array<int, count> abilities;

	int getStrength() { return abilities[str]; };
	int setStrength(int value) { abilities[str] = value; };

	int getAgility() { return abilities[agl]; };
	int setAgility(int value) { abilities[agl] = value; };

	int getIntelligence() { return abilities[intl]; };
	int setIntelligence(int value) { abilities[intl] = value; };

	int sum() const {
		return std::accumulate(abilities.begin(), abilities.end(), 0);
	};

	double average() const {
		return sum() / (double)count;
	};

	int max() const {
		return *std::max_element(abilities.begin(), abilities.end());
	};
};

#endif
