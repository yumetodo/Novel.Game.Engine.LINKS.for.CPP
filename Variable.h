// Variable Manage Source
#ifndef VALIABLE_H_
#define VALIABLE_H_

#include <vector>
#include <string>

// ¶ÌTCY
extern const std::int32_t moji_size = 24;

int DrawPointX = 0, DrawPointY = 0;	// ¶ñ`æÌÊu
int SP = 0, CP = 0;	// QÆ·é¶ñÔÆ¶ñÌ¶|C^

int EndFlag = 0;	// I¹tO

					//XNvgi[Ï
static std::vector<std::string> Script;

//wiæi[Ï
static std::vector<int> BackGround;

//§¿Gi[Ï
static std::vector<int> Character;

//BGMi[Ï
static std::vector<int> BackGroundMusic;

static std::vector<int> SoundEffect;

//®æi[Ï
static std::vector<std::string> Movie;

#endif //VALIABLE_H_