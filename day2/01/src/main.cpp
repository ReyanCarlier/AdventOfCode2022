#include <vector>
#include <fstream>
#include <iostream>

/*
The Elves begin to set up camp on the beach. To decide whose tent gets to be closest to the snack storage, a giant Rock Paper Scissors tournament is already in progress.

Rock Paper Scissors is a game between two players. Each game contains many rounds; in each round, the players each simultaneously choose one of Rock, Paper, or Scissors using a hand shape. Then, a winner for that round is selected: Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.

Appreciative of your help yesterday, one Elf gives you an encrypted strategy guide (your puzzle input) that they say will be sure to help you win. "The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors. The second column--" Suddenly, the Elf is called away to help with someone's tent.

The second column, you reason, must be what you should play in response: X for Rock, Y for Paper, and Z for Scissors. Winning every time would be suspicious, so the responses must have been carefully chosen.

The winner of the whole tournament is the player with the highest score. Your total score is the sum of your scores for each round. The score for a single round is the score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).

Since you can't be sure if the Elf is trying to help you or trick you, you should calculate the score you would get if you were to follow the strategy guide.

For example, suppose you were given the following strategy guide:

A Y
B X
C Z

This strategy guide predicts and recommends the following:

    In the first round, your opponent will choose Rock (A), and you should choose Paper (Y). This ends in a win for you with a score of 8 (2 because you chose Paper + 6 because you won).
    In the second round, your opponent will choose Paper (B), and you should choose Rock (X). This ends in a loss for you with a score of 1 (1 + 0).
    The third round is a draw with both players choosing Scissors, giving you a score of 3 + 3 = 6.

In this example, if you were to follow the strategy guide, you would get a total score of 15 (8 + 1 + 6).

What would your total score be if everything goes exactly according to your strategy guide?

*/
std::vector<std::string>	get_filecontent(std::string filename)
{
	std::vector<std::string>	content;
	std::fstream				file;
	std::string					line;

	file.open(filename.c_str(), std::ios::in);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			content.push_back(line);
		}
		file.close();
	}
	return content;
}

// Rock = X, Paper = Y, Scissors = Z
int		get_winner(char player1, char player2)
{
	int		winner = 0;

	if (player1 == player2)
		return (0);
	if (player1 == 'X' && player2 == 'Y')
		winner = 2;
	else if (player1 == 'X' && player2 == 'Z')
		winner = 1;
	else if (player1 == 'Y' && player2 == 'X')
		winner = 1;
	else if (player1 == 'Y' && player2 == 'Z')
		winner = 2;
	else if (player1 == 'Z' && player2 == 'X')
		winner = 2;
	else if (player1 == 'Z' && player2 == 'Y')
		winner = 1;
	return winner;
}

int		get_score(int winner)
{
	int		score = 0;

	if (winner == 0)
		score = 3;
	else if (winner == 2)
		score = 6;
	else if (winner == 1)
		score = 0;
	return score;
}

int		get_additionnal_score(char action)
{
	if (action == 'X')
		return 1;
	else if (action == 'Y')
		return 2;
	else
		return 3;
}


int main(void)
{
	std::vector<std::string>	content = get_filecontent("input.txt");
	int							score = 0;
	int							winner = 0;
	char						player1 = 0;
	char						player2 = 0;
	
	for (std::vector<std::string>::iterator it = content.begin(); it != content.end(); ++it)
	{
		for (std::string::iterator it2 = it->begin(); it2 != it->end(); ++it2)
		{
			if (*it2 == 'A')
				*it2 = 'X';
			else if (*it2 == 'B')
				*it2 = 'Y';
			else if (*it2 == 'C')
				*it2 = 'Z';
		}
	}

	for (std::vector<std::string>::iterator it = content.begin(); it != content.end(); ++it)
	{
		player1 = it->at(0);
		player2 = it->at(2);
		winner = get_winner(player1, player2);
		score += get_score(winner) + get_additionnal_score(player2);
		std::cout << "Player1: " << player1 << " Player2: " << player2 << " Winner: " << winner << " Score: " << get_score(winner) << " Additionnal score: " << get_additionnal_score(player2) << std::endl;
	}
	std::cout << "Your score is " << score << std::endl;
	return 0;
}