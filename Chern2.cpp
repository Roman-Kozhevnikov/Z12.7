#include <iostream>
#include <string>
using namespace std;

bool isKPeriodic(string& str, int K)
{
	int n_Str = str.size();
	int n_Int = 9;

	string iter_text;
	string iter_text_save;

	int word_size(0);
	int word_size2(0);

	int temp(0);
	int i(0);

	while (++i <= n_Int)
	{
		if (n_Str % i)
			continue;
		temp = n_Str / i;
		word_size = word_size2 = temp;
		while (word_size)
		{
			if (str[temp - word_size] == str[word_size2++])
			{
				iter_text += str[temp - word_size];
				word_size--;
			}
			else
			{
				if (!(word_size == 0))
					iter_text = "\0";
				break;
			}
		}

		if (word_size == 0)
			iter_text_save = iter_text;
		iter_text = "\0";

	}

	if (K < 0)
		K = -K;
	int j(0);
	j = n_Int;
	while (n_Str % j--)
		if (iter_text_save.size() == 0 || j)
			cout << " ";
		else if (K == iter_text_save.size())
			return true;
		else return false;

	i = temp;

	while (--i > 1)
	{
		if (n_Str % i)
			continue;

		word_size = word_size2 = i;

		while (word_size)
		{
			if (str[i - word_size] == str[word_size2++])
			{
				iter_text += str[i - word_size];
				word_size--;
			}
			else
			{
				if (!(word_size == 0))
					iter_text = "\0";
				break;
			}
		}

		if (word_size == 0)
			iter_text_save = iter_text;
		iter_text = "\0";
	}

	if (iter_text_save.size() != 0)
	{
		int save_size = iter_text_save.size();

		while (save_size-- > 0)
		{
			if (!(iter_text_save[0] == iter_text_save[save_size]))
				break;
		}

		if (!++save_size)
		{
			if (K == 1)
				return true;
			else return false;
		}
	}

	if (iter_text_save.size() == 0)
	{
		int save_n_Str = n_Str;
		while (save_n_Str-- > 0)
		{
			if (!(str[0] == str[save_n_Str]))
				break;
		}

		if (!++save_n_Str)
		{
			if (K == 1)
				return true;
			else return false;
		}
	}

	if (K < 0)
		K = -K;
	if (K == iter_text_save.size())
		return true;
	else return false;

}

int main()
{
	std::string str("abc"); // 0
	//std::string str("abcabcabcabcabc"); // 3
	//std::string str("aabcaaaabcaaaabcaaaabcaaaabcaaaabcaa"); // 6     
	//std::string str("aa"); // 1  
	//std::string str("aaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaaaaabcaa"); // 7 
	//std::string str("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"); // 3
	//std::string str("abababababababab"); // 2
	//std::string str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); // 1
	// добавить продолжение деления,  сейчас проходит только ONE
	if (isKPeriodic(str, 0))
		std::cout << "Yesss";
	else std::cout << "No";

}
