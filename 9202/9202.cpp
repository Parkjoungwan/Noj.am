#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

int w, b;
bool visited[4][4];
string map[4];
unordered_set<string> res;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

struct Trie
{
	Trie *next[26];
	bool isFin;

	Trie()
	{
		memset(this -> next, 0, sizeof(this -> next));
		this -> isFin = false;
	}
	~Trie()
	{
		int i;

		i = 0;
		while (i < 26)
		{
			if (this -> next[i])
				delete this -> next[i];
			i++;
		}
	}

	void insert(string key)
	{
		int i, index;

		i = 0;
		Trie *pNode = this;
		while (i < key.length())
		{
			index = key[i] - 'A';
			if (!pNode -> next[index])
				pNode -> next[index] = new Trie();
			pNode = pNode -> next[index];
			i++;
		}
		pNode -> isFin = true;
	}

	void search(int y, int x, string key)
	{
		if (key.length() > 8)
			return;
		visited[y][x] = true;
		key += map[y][x];

		Trie *pNode = this -> next[map[y][x] - 'A'];
		if (pNode == NULL)
		{
			visited[y][x] = false;
			return;
		}
		if (pNode -> isFin)
		{
			res.insert(key);
		}
		for (int dir = 0; dir < 8; ++dir) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)continue;
			if (visited[ny][nx])continue;
			pNode->search(ny, nx, key);
		}
		visited[y][x] = false;
	}
};

int main()
{
	int i, j, x, y;
	int Max, match, scoreSum;

	Trie *root = new Trie();
	cin >> w;
	i = 0;
	while (i < w)
	{
		string str;
		cin >> str;
		root -> insert(str);
		i++;
	}
	cin >> b;
	i = 0;
	j = 0;
	while (i < b)
	{
		j = 0;
		while (j < 4)
		{
			cin >> map[j];
			j++;
		}
		res.clear();
		y = 0;
		x = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				root -> search(y, x, "");
				x++;
			}
			y++;
		}
		string longest = "";
		Max = 0;
		match = res.size();
		scoreSum = 0;
		for (string item : res)
		{
			if (Max == item.length())
			{
				longest = longest < item ? longest : item;
			}
			else if (Max < item.length())
			{
				Max = item.length();
				longest = item;
			}
			scoreSum += score[item.length()];
		}
		cout << scoreSum << " " << longest << " " << match << '\n';
		i++;
	}
	return 0;
}
