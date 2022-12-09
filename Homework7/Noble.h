//Author: Jaeha Huh
//Name of File: noble.h

#ifndef Noble_h
#define Noble_h
#include <string>
#include <vector>

namespace WarriorCraft {

	class Protector;

	class Noble {
	public:
		Noble(const std::string& name = "s");
		const std::string& getName() const;
		bool lifeStatus() const;
		virtual float getStrength() const = 0;
		virtual void setStrength(float ratio) = 0;
		virtual void setAlive(bool status) = 0; 
		virtual void defend() const = 0; 
		void battle(Noble& aNoble);
	private:
		std::string name;
		bool alive;
	};

	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight(const std::string& name, float strength);
		virtual float getStrength() const;
		virtual void setStrength(float ratio);
		virtual void defend() const { return; }
		virtual void setAlive(bool status);
	private:
		float strength;
	};


	class Lord : public Noble {
	public:
		Lord(const std::string& name);
		virtual float getStrength() const;
		virtual void setStrength(float ratio);
		virtual void setAlive(bool status); //set protector's alive status
		virtual void defend() const;
		void hires(Protector& aProtector);
		void fires(Protector& aProtector);
		void findAndRemoveProtector(const Protector& aProtector);
	private:
		std::vector<Protector*> army;
		bool ifAProtectorInArmy(const Protector& aProtector) const;
	};

}


#endif /* Noble_h */
