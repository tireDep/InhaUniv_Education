#include"p904_tabtenn1.h"
#include<iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : firstName(fn), lastName(ln), hasTable(ht) { } 

void TableTennisPlayer::Name()const
{
	std::cout << lastName << ", " << firstName;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r) { }