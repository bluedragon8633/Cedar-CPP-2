#include<iostream>
#include"game.h"
#include"basicObjs.h"
#include"interactiveObj.h"
#include"enemy.h"



FireWorm::FireWorm() {
	name = "Fire Worm";
}

Octorok::Octorok() {
	name = "Octorok";
}

Rock::Rock() {
	//((abs(player.x - var(i, "x")) * abs(player.x - var(i, "x"))) + (abs(player.y - var(i, "y")) * abs(player.y - var(i, "y"))) < rockSensingDist * rockSensingDist)
}

void Rock::process() {
	/*
	if ((abs(player.x - var(i, "x")) * abs(player.x - var(i, "x"))) + (abs(player.y - var(i, "y")) * abs(player.y - var(i, "y"))) < rockSensingDist * rockSensingDist) {
		if (var(i, "animationID") == 0) { //resting
			setNewAnimation(i, 1);
		}
		else if (var(i, "animationID") == 1) { //opening mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 2);
			}
		}
		else if (var(i, "animationID") == 2) { //mouth is open
			if (player.x < var(i, "x")) {
				setvar(i, "flip", false);
				move(i, -2, 0, true);
			}
			else {
				setvar(i, "flip", false);
				move(i, 2, 0, true);
			}
		}
	}
	else {
		if (var(i, "animationID") == 1) { //opening mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 3);
			}
		}
		else if (var(i, "animationID") == 2) { //starts closing mouth
			setNewAnimation(i, 3);

		}
		else if (var(i, "animationID") == 3) { //closing mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 0);
			}
		}
	}
	
	*/
}