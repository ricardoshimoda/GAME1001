#pragma once

void InitPlayer();
double LosesErrorIQ();
double GetPlayerIQ();
bool DetectEmptyRepertoire();
bool CheckPlayerIQ();
void PrintPlayerStatus();
int* GetPlayerRepertoire();
void AddQuoteToRepertoire(int quoteIndex, int uses);
void AddIQ(double usageIQ);
