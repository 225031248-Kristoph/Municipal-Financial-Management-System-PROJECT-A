#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct {
    int assetID;
    char assetName[100];
    char assetType[50];
    float purchaseValue;
    char department[50];
    char condition[50];
} Asset;

void addAsset(void);
void displayAssets(void);
void searchAsset(void);

#endif