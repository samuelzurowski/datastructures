#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Actor{
protected:
    int level; 
    string name; 
    int health; 
    int damage; 
    bool dead; 
    string type; 
public:
    Actor(string name, int level):name{name}, level{level}
    {} 
    virtual void Attack(Actor& actor) = 0;
    virtual void Hit(int damage){
        health -= damage; 
        health = max(0, health);
        if(health == 0)
            dead = true; 
    } 
    bool IsDead(){ return this->dead;}
    string GetInfo(){ return name + "(level " + to_string(level) + " " + type + ")";}
    friend ostream& operator<<(ostream& out, const Actor& a); 
};

ostream& operator<<(ostream& out, const Actor& a){
    out << a.type << " level: " << a.level << ", health: " << a.health; 
    if(a.dead)
        out << " (deceased)"; 
    return out; 
}

class Knight: public Actor{
private:
    int armor; 
public:
    Knight(string name, int level):Actor(name, level){
        type = "Knight";
        armor = level * 20; 
        health = level * 50 + armor;
        damage = 10; 
        dead = false; 
    }
    void Attack(Actor& actor){
        actor.Hit(damage * level);
    }
};

class Ghost: public Actor{
private:
    int spellBonus; 
public:
    Ghost(string name, int level):Actor(name, level){
        type = "Ghost"; 
        health = level * 50;
        spellBonus = level * 5;
        damage = 5;
        dead = false; 
    }
    void Attack(Actor& actor){
        actor.Hit(spellBonus + (damage * level)); 
    }
};

int main(void){
    vector<Actor*> actors; 
    actors.push_back(new Knight("Lazerus", 4)); 
    actors.push_back(new Ghost("Casper", 5)); 

    cout << *actors[0] << endl;
    cout << *actors[1] << endl;

    while(!actors[0]->IsDead() && !actors[1]->IsDead())
    {
        actors[0]->Attack(*actors[1]); 
        actors[1]->Attack(*actors[0]); 
        
        cout << *actors[0] << endl;
        cout << *actors[1] << endl;
    }

    cout << "Winner is: " << actors[actors[0]->IsDead()? 1 : 0]->GetInfo() << endl;
}