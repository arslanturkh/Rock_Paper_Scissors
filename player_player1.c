rps player_player1(int round, rps *myhist, rps *opphist) {
	


	time_t t;
	int i, j, k, counter;
	
	if (round < 5) {
		srand((unsigned)time(&t));
		int i = rand() % 3;
		switch (i) {
		case 0: return Rock;
		case 1: return Scissors;
		}
		return Paper;
	}

	else {
		for (i = 4; i > 0; i--) {
			for (j = round-1; j > i; j--) {
				counter = 0;

				for (k = j; k > j - (i); k--) {
					
					counter++;
					if (opphist[k - 1] != opphist[round - counter-1]){ break;}

					if (counter == i) {
						if (opphist[j+1] == Rock) {return Paper;}
						else if (opphist[j+1] == Scissors) {return Rock;}
						else if (opphist[j+1] == Paper)  {return Scissors;}
					}
				}
			}
		}
	}
}

register_player(player_player1, "player1");
