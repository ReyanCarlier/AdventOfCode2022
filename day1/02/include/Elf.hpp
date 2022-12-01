#ifndef ELF_HPP
# define ELF_HPP

class Elf
{
	public:
		Elf();
		Elf(Elf const & src);
		~Elf();

		Elf & operator=(Elf const & rhs);

		int		getCalories(void) const;
		void	setCalories(int calories);

	private:
		int	calories;
};

#endif