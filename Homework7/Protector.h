//Author: Jaeha Huh
//Name of File: Protector.h

#ifndef Protector_h
#define Protector_h

#include "Noble.h"

namespace WarriorCraft {
	class Protector {
		
	public:
		Protector(const std::string& name, float strength);

		virtual void defend() const = 0;
		const std::string& getName() const;
		float getStrength() const;
		bool hireStatus() const;
		bool lifeStatus() const;
		void setStrength(float inputStrength);
		void setHire(bool status);
		void setAlive(bool status);
		void setBoss(Lord* aLord);
		void runaway();
	private:
		std::string name;
		float strength;
		bool alive;
		bool hired;
		Lord* boss;
	};

	class Wizard : public Protector {
	public:
		Wizard(const std::string& name, float strength);
		
		virtual void defend() const;
	private:
	};

	class Warrior : public Protector {
	public:
		Warrior(const std::string& name, float strength);
		
	private:
	};
	class Archer : public Warrior {
	public:
		Archer(const std::string& name, float strength);
		virtual void defend() const;
	private:
	};
	class Swordsman : public Warrior {
	public:
		Swordsman(const std::string& name, float strength);
		virtual void defend() const;
	private:
	};
}


#endif /* Protector_h */
