// Q. ���Ƿ� �� �ܾ �����ϰ�, ����ڰ� �� ���� �� ���ڸ��� �����ϵ��� �ϴ� ��� ������ �ۼ��϶�.
// �ܾ��� �� ���ڴ� *�� ǥ�õȴ�.
// ����ڰ� �ùٸ� ������ �Ͽ��� ���� ���� ���ڰ� ȭ�鿡 ǥ�õȴ�.
// ����ڰ� �ܾ� ���߱⸦ ������ ���� �Ǽ��� ȸ���� ǥ���ϰ� �ٸ� �ܾ�� ����� �������� ���´�.

// string words[] = {"write", "hospital", ... }

// ex)
// �ܾ� �� �� ���ڸ� �Է��Ͻÿ� ***** > w
// �ܾ� �� �� ���ڸ� �Է��Ͻÿ� w**** > p
// p�� �ܾ ���Ե��� �ʽ��ϴ�.
// �ܾ� �� �� ���ڸ� �Է��Ͻÿ� w**** > w
// w�� �̹� ���Ե� �ܾ��Դϴ�.
// ...
// �� n�� ����, n�� ���� ���� �ܾ� �ϼ�

// max = 10

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Class_Wordslist.h"

bool CheckReplay(int inputMenu, bool &isPlaying);

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	// �ܾ� ����Ʈ ����
	string allword[] = 
	{	"time", "year", "people", "way", "day", "man", "thing", "woman", "life", "child", "world", "school", "state",
		"family", "student", "group", "country", "problem", "hand", "part", "place", "case", "week", "company", "system", "program", "question",
		"work", "government", "number", "night", "point", "home", "water", "room", "mother", "area", "money", "story", "fact", "month", "book",
		"eye", "job", "word", "business", "issue", "side", "head", "house", "service", "friend", "father", "power", "hour", "game", "line", "end",
		"member", "law", "car", "city", "name", "president", "team", "minute", "idea", "kid", "body", "information", "back", "parent", "face", "others",
		"level", "office", "door", "health", "person", "art", "war", "history", "party", "result", "change", "morning", "reason", "research", "girl",
		"guy", "food", "moment", "air", "teacher", "force", "education", "foot", "boy", "age", "process", "music", "market", "sense", "nation", "plan",
		"college", "interest", "death", "experience", "effect", "class", "control", "care", "field", "development", "role", "effort", "rate", "heart",
		"drug", "leader", "voice", "wife", "police", "mind", "price", "report", "son", "view", "relationship","town", "road", "difference", "value",
		"building", "action", "model", "season", "society", "tax", "director", "position", "player", "record", "paper", "space", "ground", "form", "event",
		"center", "couple", "project", "activity", "star", "table", "American", "oil", "situation", "cost", "street", "image", "phone", "picture", "practice",
		"piece", "land", "product", "doctor", "wall", "patient", "worker", "news", "test", "movie", "north", "love", "technology", "step", "baby", "computer",
		"type", "film", "tree", "source", "hair", "look", "window", "culture", "chance", "brother", "energy", "summer", "plant", "opportunity", "letter", "condition",
		"choice", "rule", "daughter", "south", "husband", "floor", "call", "economy", "hospital", "church", "risk", "fire", "future", "security", "bank", "west",
		"sport", "board", "subject", "officer", "rest", "behavior", "performance", "top", "goal", "bed", "order", "author", "blood", "nature", "color", "store", "sound",
		"movement", "race", "language", "animal", "factor", "article", "east", "artist", "scene", "stock","career","size","dog","fund","media","sign","thought",
		"list","individual","quality","pressure","answer","resource","meeting","disease","success","cup","amount","ability","staff","character","region",
		"television","box","training","deal","feeling","standard","bill","message","lawyer","glass","skill","sister","professor","stage","design","knowledge",
		"gun","station","truth","song","example","environment","leg","set""rock","note","manager","help","network","science","memory","card","seat","expert",
		"spring","ball","direction","peace","pain","interview","chair","fish","camera","weight","trip","evening","ear","shop","competition","equipment","failure",
		"Christmas","comment","baseball","egg","gift","religion","review","editor","coffee","speed""youth","wave","move","background","reaction","suit","shoe",
		"grade","context","mistake","focus","smile","location","clothes","neighbor","drive","function","bone","average","wine","bus","category","victory","key",
		"visit","Internet","medicine","tour","photo","classroom","contact","justice","exercise","knee","flower","actor","circle","device","bottom","island",
		"studio","lady","colleague","neck","damage","plate","expression","football","chicken","army","theater","map","danger","rain","respect","fuel","leaf",
		"fight","pool","lead","engine","salt", "metal", "ticket"
	};
	string word;
	WORDSLIST_C wordsList;

	int arrSize = sizeof(allword)/sizeof(allword[0]);
	bool isPlaying = true;
	int inputMenu = 1;
	char inputAlpha;
	while (1)
	{
		if (wordsList.GetDeadCnt() <= 0)
		{
			cout << "Ƚ�� ���� �ʰ��� ���� ����\n";
			cout << "���� : " << wordsList.GetAnswerWords() << endl;
			cout << "�õ� Ƚ�� : " << wordsList.GetTry() << endl;
			if (!CheckReplay(inputMenu, isPlaying))
				break;
			else
				system("cls");
		}

		if (wordsList.GetClrCnt() == wordsList.GetLen() && wordsList.GetClrCnt() != 0)
		{
			cout << "����!\n�ܾ� : " << wordsList.GetAnswerWords() << endl;
			cout << "�õ� Ƚ�� : " << wordsList.GetTry() << endl;
			if (!CheckReplay(inputMenu, isPlaying))
				break;
			else
				system("cls");
		}

		if (inputMenu == 1)
		{
			rewind(stdin);
			if (isPlaying == true)
			{
				isPlaying = false;
				word = allword[rand() % arrSize];
				wordsList.SetValue(word);
			}
			cout << "�ܾ� : ";
			wordsList.PrintBoard();
			cout << "\n���ĺ� �Է� : ";
			cin >> inputAlpha;

			wordsList.CompareInputAlpha(inputAlpha);
		}
	}

	cout << "���α׷� ����\n";

	return 0;
}

bool CheckReplay(int inputMenu, bool &isPlaying)
{
	cout << "\n�絵��?(�絵�� : 1, ���� : ��Ÿ �Է�)\n";
	cin >> inputMenu;
	if (inputMenu == 1)
		isPlaying = true;
	else
		isPlaying = false;

	return isPlaying;
}