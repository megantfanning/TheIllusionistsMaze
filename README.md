# The Illusionist's Maze
###Theme:
You are a aging showgirl, and you've had just about enough of these magicians and illusionists, you know how to stack a deck and get cut in half with the best of them it's time they let you in on their secrets. The Illusionist you've working for has told you to meet him at the warehouse he practices at and says he'll teach you magic, IF you can successfully identify magic and illusion.
Upon entering his warehouse you find yourself in a hall of mirrors were you must find an exit.
In the center of the room is a pile of your stage equipment you must identify the exit.
In the next room there is a merry go round that is in the center of four rooms, use the merry go round to enter all four rooms and collect the props for tonight's show. Each of the four rooms opens to another room, some of the entrances  require a key to open and some just keen observation.
The acts for tonight are sawing the lady in half, the underwater escape and a bullet catch trick a live gun. Collect to the props needed for each trick without getting fooled by the illusions.
The show is at 8pm tonight but it's already 6pm, can you escape the maze of illusions in time?

###Structure:
maze is created using a linked list of structs with multiple pointers, the maze is made using a vector to ensure the deletion of dynamically allocated memory. Each room has 4 pointers and a vector which holds the items in the room. There are several types of rooms which utilize inheriantance to provide specific features. Mirrored rooms don't show which directions are available to the user, the locked rooms link to another room but require a specific item to link the rooms together. The Carosel is especially unique since its pointers "swivel" so the user could go north but end up in the room that would have orginally been to the south.

Megan Fanning 
4/4/2015
