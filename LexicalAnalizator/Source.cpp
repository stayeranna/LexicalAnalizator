#include"Hash.h"
#include"Lexer.h"
using std::ofstream;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	Hash table;
	Lexer lexer;
	string s = lexer.getLexem(in);
	while (s != "")
	{
		string type = lexer.getType(s);
		if (type == "error")
		{
			out << "error: " << s << '\n';
		}
		else
		{
			table.insert(Token(type, s));
		}
		s = lexer.getLexem(in);
	}
	table.print(out);
	in.close();
	out.close();
}