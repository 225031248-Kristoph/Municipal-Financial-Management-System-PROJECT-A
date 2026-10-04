#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset()
{
    printf("\nEnter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", assets[assetCount].assetName);

    printf("Enter Asset Type: ");
    scanf(" %[^\n]", assets[assetCount].assetType);

    printf("Enter Purchase Value: ");
    scanf("%f", &assets[assetCount].purchaseValue);

    printf("Enter Department: ");
    scanf(" %[^\n]", assets[assetCount].department);

    printf("Enter Condition: ");
    scanf(" %[^\n]", assets[assetCount].condition);

    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets()
{
    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d", assets[i].assetID);
        printf("\nName: %s", assets[i].assetName);
        printf("\nType: %s", assets[i].assetType);
        printf("\nValue: %.2f", assets[i].purchaseValue);
        printf("\nDepartment: %s", assets[i].department);
        printf("\nCondition: %s\n", assets[i].condition);
    }
}

void searchAsset()
{
    int id;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < assetCount; i++)
    {
        if (assets[i].assetID == id)
        {
            printf("\nAsset Found!");
            printf("\nName: %s", assets[i].assetName);
            printf("\nType: %s", assets[i].assetType);
            printf("\nValue: %.2f", assets[i].purchaseValue);
            printf("\nDepartment: %s", assets[i].department);
            printf("\nCondition: %s\n", assets[i].condition);
            return;
        }
    }

    printf("\nAsset not found.\n");
}