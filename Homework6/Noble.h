#ifndef Noble_h
#define Noble_h

//Author : Jaeha Huh
//File name : Noble.h

#include <string>
#include <vector>

namespace WarriorCraft {

	class Warrior;

	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
	public:
		Noble(const std::string& name);

		~Noble();

		void hire(Warrior& warrior);

		void fire(Warrior& warrior);

		void battle(Noble& aNoble);

		void adjustNobleAndArmy(double ratio);

		double getArmyStr() const;

		bool checkArmy(const Warrior& warrior);

		void findAndRemoveWarrior(const Warrior& warrior);

		bool lifeStatus() const;

		std::string getName() const;

	private:
		std::vector<Warrior*> army;
		std::string name;
		bool alive = true;
	};
}


#endif 
