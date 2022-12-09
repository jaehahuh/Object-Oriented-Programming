//Author : Jaeha Huh
//File name : Warrior.h

#ifndef Warrior_h
#define Warrior_h

#include "Noble.h"

namespace WarriorCraft {

	class Warrior {
		friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
	public:
		Warrior(const std::string& name, double strength);

		std::string getName() const;

		double getStrength() const;

		bool hireStatus() const;

		bool lifeStatus() const;

		void setStrength(double inputStrength);

		void setHire(bool status);

		void setAlive(bool status);

		void setBoss(Noble* aNoble);

		void runaway();

	private:
		std::string name;
		double strength;
		bool alive = true;
		bool hired = false;
		Noble* boss;
	};
}

#endif