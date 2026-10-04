#ifndef ASSET_H
#define ASSET_H

int getAssetCount(void);
int getAssetId(int index);
char* getAssetName(int index);
char* getAssetType(int index);
double getAssetValue(int index);
char* getAssetDepartment(int index);
char* getAssetCondition(int index);

void addAsset(void);
void displayAssets(void);
void searchAsset(void);

#endif