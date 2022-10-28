/***************************************
Joust
Author: Well Moua
Date Created: 11-9-19
Description: A game of where two knights joust to see who win.
***************************************/

#include <iostream>
#include <random>
#include <chrono>
using namespace std;

namespace Random
{   
    static std::default_random_engine rng;
    static bool seeded = false;

    // Random class defintion
    class Random
    {
        private:
        std::uniform_int_distribution<int> _dist;

        public:
        Random(int low, int high) : _dist(low, high)
        { 
            seed();     
        }

        static void seed()
        {
            //we only want to seed once
            if (seeded)
            {
                return; 
            } 
            seeded = true;

            // Deriving seed from current system time
            auto generatedSeed = std::chrono::system_clock::now().time_since_epoch().count();
            rng.seed(generatedSeed);
        }

        int get()
        {
            return _dist(rng);
        }
    };
}

// Weapon Class
class Weapon
{
    private:
    Random::Random rand;
    int _staminaConsumption;
    int _hitChance; // represents percentage
    string _type;

    public: 
    Weapon(int hitChance, int staminaConsumption, string type) : _hitChance(hitChance), _staminaConsumption(staminaConsumption), _type(type), rand(1, 100)
    {
    }

    bool swing()
    {
        int hc = rand.get();
        if (hc < _hitChance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int staminaConsumed()
    {
        return _staminaConsumption;
    }
};

// Knight Class 
class Knight
{
    private:
    string name;
    int _stamina;
    string _name;
    Weapon _equipment;
    bool _onHorse;

    public:
    Knight(string name, int stamina, int hitChance, int staminaConsumption, string type) : _name(name), _stamina(stamina), _equipment(hitChance, staminaConsumption, type)
    {
    }

    bool joust()
    {
        bool hitOtherKnight = _equipment.swing();

        _stamina -= _equipment.getStaminaConsumed();

        return hitOtherKnight;
    }

    // Getters
    
    Weapon getWeapon()
    {
        return _equipment;
    }

};

Knight buildknight()
{
    string name;
    int stamina; 
    int hitChance;
    int staminaConsumption;
    string type;

    cout<<"What is the knight's name?"<<endl;
    getline(cin, name);
    
    cout<<"What is the knight's initial stamina?"<<endl;
    cin>>stamina;
    
    cout<<"What is the knight's weapon type?"<<endl;
    getline(cin, type);
    
    cout<<"What is the weapon's hit chance?"<<endl;
    cin>>hitChance;
    
    cout<<"What is the weapon's stamina cost?"<<endl;
    cin>>staminaConsumption;
    
    return Knight(name, stamina, hitChance, staminaConsumption, type);
}


int main()
{
    Knight k1 = buildKnight();
    Knight k2 = buildKnight();
    // Variables for Knight 1 Info. to be stored
    string knight1_name;
    int knight1_stamina;
    int knight1_hitChance;
    int knight1_staminaCost;
    bool knight1_onHorse = true;
    string knight1_weapon;
    
    // Variables for Knight 2 Info. to be stored
    string knight2_name;
    int knight2_stamina;
    int knight2_hitChance;
    int knight2_staminaCost;
    bool knight2_onHorse = true;
    string knight2_weapon;

    // Setting up Knight 1
    cout<<"Knight 1 Info"<<endl;
    cout<<"What is the knight's name?"<<endl;
    getline(cin, knight1_name);
    cout<<"What is the knight's initial stamina?"<<endl;
    cin>>knight1_stamina;
    cin.ignore();
    cout<<"What is the knight's weapon type?"<<endl;
    getline(cin, knight1_weapon);
    cout<<"What is the weapon's hit chance?"<<endl;
    cin>>knight1_hitChance;
    cin.ignore();
    cout<<"What is the weapon's stamina cost?"<<endl;
    cin>>knight1_staminaCost;
    cin.ignore();
    Knight knight1(knight1_name, knight1_stamina, knight1_hitChance, knight1_staminaCost, knight1_weapon); 

    // Setting up Knight 2
    // cout<<endl<<"Knight 2 Info"<<endl;
    // cout<<"What is the knight's name?"<<endl;
    // getline(cin, knight2_name);
    // cout<<"What is the knight's initial stamina?"<<endl;
    // cin>>knight2_stamina;
    // cin.ignore();
    // cout<<"What is the knight's weapon type?"<<endl;
    // getline(cin, knight2_weapon);
    // cout<<"What is the weapon's hit chance?"<<endl;
    // cin>>knight2_hitChance;
    // cin.ignore();
    // cout<<"What is the weapon's stamina cost?"<<endl;
    // cin>>knight2_staminaCost;
    // cin.ignore();
    // Knight knight2(knight2_name, knight2_stamina, knight2_hitChance, knight2_staminaCost, knight2_weapon); 

    while (knight1_stamina > 0 && knight2_stamina > 0 && knight1_onHorse == true && knight2_onHorse == true)
    {
        knight1_stamina -= knight1.getWeapon().staminaConsumed();
        knight2_stamina -= knight2.getWeapon().staminaConsumed();
        knight1_onHorse = knight1.getWeapon().swing();
        knight2_onHorse = knight2.getWeapon().swing();
        
        // If's statement for who win or it's a tie.
    //     if (knight1_stamina > 0 && knight2_stamina <= 0 && knight1_onHorse == true && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted and is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<<" stamina and has a "<<knight1_hitChance<<"% chance."<<endl;
            
    //         cout<<endl<<knight2_name<<" is exhausted and is still on the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight1_name<<" wins!"<<endl;
    //     }
        
    //     if (knight1_stamina <= 0 && knight2_stamina > 0 && knight1_onHorse == true && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is exhausted and is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<<" stamina and has a "<<knight1_hitChance<<"% chance."<<endl;
            
    //         cout<<endl<<knight2_name<<" is not exhausted and is still on the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight2_name<<" wins!"<<endl;
    //     }
        
    //     if (knight1_stamina > 0 && knight2_stamina > 0 && knight1_onHorse == false && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is not exhausted and is still on the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight2_name<<" wins!"<<endl;
    //     }
        
    //     if (knight1_stamina > 0 && knight2_stamina > 0 && knight1_onHorse == true && knight2_onHorse == false)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted and is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight1_name<<" wins!"<<endl;
    //     }
        
    //     if (knight1_stamina <= 0 && knight2_stamina > 0 && knight1_onHorse == false && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is exhausted and is knocked off the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is not exhausted and is still the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight2_name<<" wins!"<<endl;            
    //     }
        
    //     if (knight1_stamina > 0 && knight2_stamina <= 0 && knight1_onHorse == true && knight2_onHorse == false)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted and is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is exhausted and is knocked off the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<knight1_name<<" wins!"<<endl;                  
    //     }
        
    //     if (knight1_stamina <= 0 && knight2_stamina <= 0 && knight1_onHorse == true && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is exhausted but is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is exhausted but is still on the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<"It's a Tie!"<<endl;
    //     }
        
    //     if (knight1_stamina > 0 && knight2_stamina > 0 && knight1_onHorse == false && knight2_onHorse == false)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<"It's a Tie!"<<endl;
    //     }
        
    //     if (knight1_stamina <= 0 && knight2_stamina > 0 && knight1_onHorse == true && knight2_onHorse == false)
    //     {
    //         cout<<endl<<knight1_name<<" is exhausted but is still on the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<"It's a Tie!"<<endl;
    //     }
        
    //     if (knight1_stamina > 0 && knight2_stamina <= 0 && knight1_onHorse == false && knight2_onHorse == true)
    //     {
    //         cout<<endl<<knight1_name<<" is not exhausted but is knocked off the horse."<<endl;
    //         cout<<knight1_name<<" is using: "<<knight1_weapon<<" that requires "<<knight1_staminaCost<< " stamina and has a "<<knight1_hitChance<<"% chance."<<endl;

    //         cout<<endl<<knight2_name<<" is exhausted but is still on the horse."<<endl;
    //         cout<<knight2_name<<" is using: "<<knight2_weapon<<" that requires "<<knight2_staminaCost<<" stamina and has a "<<knight2_hitChance<<"% chance."<<endl;
    //         cout<<endl<<"It's a Tie!"<<endl;
    //     }
    // }
   return 0;
}
