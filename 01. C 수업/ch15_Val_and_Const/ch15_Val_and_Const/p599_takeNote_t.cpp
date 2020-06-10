// 599p

enum ACTION { MOVE, JUMP, ATTACK, DIE = 999, DEATH };
enum STATUS { IDLE, WAIT };
// 같은 값이지만, 여러 상태를 표현하기 위해 이런식으로도 사용됨

enum { t1, t2, t3 };
// 지정 없을 경우 0부터 시작해서 +1

int main()
{
	char playerTest[ACTION::ATTACK];

	char test2[t2];

}