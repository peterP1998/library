#pragma once
#include "Set.h"
#include "Reader.h"
class Community :public Set<Reader>,public ReadingRankable
{
public :
	 int getReadingRank() const;
};