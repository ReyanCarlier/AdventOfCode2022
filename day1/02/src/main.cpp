#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Elf.hpp"

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

int	count_elves(std::vector<std::string> content)
{
	int				elves = 0;
	std::size_t		i = 0;

	while (i < content.size())
	{
		if (content[i].size() == 0)
			elves++;
		i++;
	}
	return elves;
}

void	compute_calories(Elf *elves, std::vector<std::string> content, int elves_count)
{
	int _calories = 0;
	std::size_t j = 0;

	for (int i = 0; i < elves_count; i++)
	{
		_calories = 0;
		while (j < content.size())
		{
			if (content[j].size() == 0)
			{
				j++;
				break;
			}
			_calories += std::stoi(content[j]);
			j++;
		}
		elves[i].setCalories(_calories);
	}
}

Elf *get_three_elves_with_most_calories(Elf *elves, int elves_count)
{
	Elf *three_elves = new Elf[3];
	int max = 0;
	int max2 = 0;
	int max3 = 0;
	int j = 0;

	for (int i = 0; i < elves_count; i++)
	{
		if (elves[i].getCalories() > max)
		{
			max = elves[i].getCalories();
			j = i;
		}
	}
	three_elves[0] = elves[j];
	j = 0;
	for (int i = 0; i < elves_count; i++)
	{
		if (elves[i].getCalories() > max2 && elves[i].getCalories() < max)
		{
			max2 = elves[i].getCalories();
			j = i;
		}
	}
	three_elves[1] = elves[j];
	j = 0;
	for (int i = 0; i < elves_count; i++)
	{
		if (elves[i].getCalories() > max3 && elves[i].getCalories() < max2)
		{
			max3 = elves[i].getCalories();
			j = i;
		}
	}
	three_elves[2] = elves[j];
	return three_elves;
}

int	main(void)
{
	std::vector<std::string> input_content = get_filecontent("input.txt");
	int						 elves_count = count_elves(input_content);

	Elf		*elves = new Elf[elves_count];
	Elf		*most_calories;

	compute_calories(elves, input_content, elves_count);
	most_calories = get_three_elves_with_most_calories(elves, elves_count);

	std::cout << "The three elves with the most calories are:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Elf " << i + 1 << " has " << most_calories[i].getCalories() << " calories." << std::endl;
	}

	std::cout << "The sum of the calories of the three elves is " << most_calories[0].getCalories() + most_calories[1].getCalories() + most_calories[2].getCalories() << std::endl;
	
	delete [] elves;
	delete [] most_calories;

	return 0;
}