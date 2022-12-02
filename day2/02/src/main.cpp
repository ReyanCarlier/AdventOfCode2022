#include <vector>
#include <fstream>
#include <iostream>

/*
The Elf finishes helping with the tent and sneaks back over to you. "Anyway, the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"

The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. The example above now goes like this:

    In the first round, your opponent will choose Rock (A), and you need the round to end in a draw (Y), so you also choose Rock. This gives you a score of 1 + 3 = 4.
    In the second round, your opponent will choose Paper (B), and you choose Rock so you lose (X) with a score of 1 + 0 = 1.
    In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = 7.

Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of 12.

Following the Elf's instructions for the second column, what would your total score be if everything goes exactly according to your strategy guide?
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

// Rock = A, Paper = B, Scissors = C

int		get_score(char outcome)
{
	if (outcome == 'X')
		return 0;
	else if (outcome == 'Y')
		return 3;
	else
		return 6;
}

int		get_additionnal_score(char action)
{
	if (action == 'A')
		return 1;
	else if (action == 'B')
		return 2;
	else
		return 3;
}

// Rock = A, Paper = B, Scissors = C
int		get_my_action(char ennemyAction, char outcome)
{
	if (outcome == 'X')
	{
		if (ennemyAction == 'A')
			return 'C';
		else if (ennemyAction == 'B')
			return 'A';
		else
			return 'B';
	}
	else if (outcome == 'Y')
		return ennemyAction;
	else
	{
		if (ennemyAction == 'A')
			return 'B';
		else if (ennemyAction == 'B')
			return 'C';
		else
			return 'A';
	}
}


int main(void)
{
	std::vector<std::string>	content = get_filecontent("input.txt");
	int							score = 0;
	char						player1 = 0;
	char						player2 = 0;
	char						outcome = 0;
	
	for (size_t i = 0; i < content.size(); i++)
	{
		player1 = content[i][0];
		outcome = content[i][2];
		player2 = get_my_action(player1, outcome);
		score += get_additionnal_score(player2) + get_score(outcome);
		std::cout << "Player1 action : " << player1 << " Player2 action : " << player2 << " Outcome : " << outcome << " Score : " << get_score(outcome) << " Additionnal score : " << get_additionnal_score(player2) << std::endl;
	}
	std::cout << "Your score is " << score << std::endl;
	return 0;
}