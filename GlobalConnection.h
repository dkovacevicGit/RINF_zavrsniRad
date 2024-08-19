#ifndef GlobalConnectionH
#define GlobalConnectionH

#include <FireDAC.Comp.Client.hpp>

extern TFDConnection *GlobalFDConnection;

void InitializeGlobalConnection();
void FinalizeGlobalConnection();

#endif

