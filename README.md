# cowboy_vs_ninja_b

A battle between ninjas and cowboys

### Point
First, we'll write a class that will help us save a position on the game board. The position is given as two double coordinates that keep the position of the unit along the x and y axes accordingly. The department interface must support the following operations:

- Constructor receives the two coordinates -

- distance receives a point and calculates the distance between the two points -

- Print print prints the two coordinates between brackets. -

- moveTowards gets a source point, a destination point and a distance. The function returns the closest point to the destination point, - which is at most the given distance from the source point


###  Character
This class specifies a character. A character has a location (of type Point), hit points (represented by an integer) and a name represented by a character string. Functions defined on a character:

- isisAlive() returns a boolean value is the character alive (that is, has more than zero hit points) – –

- distance receives a pointer to another character and returns the distance between the characters (– – double.)

- Hit gets an integer. Subtracts the appropriate amount of hit points from the character. returns nothing. –

- name getName() returns the name of the character. -

- location getLocation() returns the location of the character. -

- Printing print() prints the name of the character, the number of its hit points, and the point where the character is. If the character dies a number of - - hit points will not be printed, and the character's name will appear in parentheses. Before the name will appear a letter indicating the type of character: N for ninja and C for morning.

- For cowboys, the parameter "amount of bullets" (whole number) is also defined. A cowboy is always created with six bullets and 110 hit points. - The following functions are defined for cowboys only:

  - shoot shoot gets a pointer to the enemy. If the morning is not dead and has bullets left, the morning shoots the enemy, subtracting 10 hit points from the enemy - and losing 1 bullet. Otherwise, no damage will be done to the enemy.

  - Checking the cartridge hasboolets() returns a Boolean indicating whether there are any bullets left in this morning's gun.

  - Reloading reload() reloads the gun with six new bullets.

- For ninjas the speed parameter is set (an integer) The following functions are set for ninjas only:

  - move receives a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed. –

  - slash() – – receives a pointer to the enemy. If the ninja is alive and the enemy is less than 1 meter away, the ninja will deal 40 damage to the enemy. Otherwise, no damage will be done to the enemy.

  - There are three types of ninjas:

    - YoungNinja move at speed 14. Generated with 100 hit points. –

    - TrainedNinja move at speed 12. Generated with 120 hit points. –

    - OldNinja move at speed 8. Spawn with 150 hit points.



### team
This class is a group of up to ten fighters, where a fighter can be a ninja or a warrior. Each group is assigned a leader who is one of the fighters. When a group is created, it gets a leader pointer. Functions defined about a group:

- Adding add() takes a pointer to a morning or ninja, and adds it to the group. –

- attack() receives a pointer to an enemy group. Attacking the enemy group will be done in the following way: - First check if the leader of the attacking group is alive. Otherwise, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader. Then the group will choose a victim from among the enemy group. The victim is the member of the living enemy group who is closest to the leader of the attacking group. All living members of the attacking group will attack the chosen victim. Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons. Ninjas within 1 meter of the victim will kill the victim, and ninjas further away will advance towards the victim. At each stage, if the victim If dead, a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking group). If there are no living members in the attacking group or the enemy group the attack will end. –

- Is my life stillAlive() returns an integer number the number of members of the group left alive. – –

- Print print() goes through all the characters in the group and prints their details. –

- A destructor frees the memory allocated to all members of the group. –

- Going over all members of the group (for attacking, printing, or comparing) will always be done in the following order: first go over all the cowboys, then go over all the ninjas. Within each group, the transition will be made according to the order in which the characters were added. The purpose of the requirement to split between - - cowboys and ninjas in this section is to make it easier for you. If you find that the requirement complicates the implementation, think about another implementation. - When looking for the closest character, and two characters are at the same distance, the first character that was checked between them will be selected.

### team2
The same as team, but the transition to the characters will be according to the order of addition without distinguishing cowboys or ninjas


### SmartTeam
The same for the team. The transition of the characters will be according to your choice in whatever order you see fit. It is allowed and desirable at this stage to "ask"  the other team about the positions of their forces and their status as well as take into account the situation of the attacking team in order to maximize damage.
