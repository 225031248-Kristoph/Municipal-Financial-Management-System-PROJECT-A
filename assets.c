#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset()
{
    printf("\nEnter Asset ID: ");
    scanf("%d", &assets[assetCount].id);

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", assets[assetCount].name);

    printf("Enter Asset Type: ");
    scanf(" %[^\n]", assets[assetCount].type);

    printf("Enter Purchase Value: ");
    scanf("%f", &assets[assetCount].value);

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
        printf("\nAsset ID: %d", assets[i].id);
        printf("\nName: %s", assets[i].name);
        printf("\nType: %s", assets[i].type);
        printf("\nValue: %.2f", assets[i].value);
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
        if (assets[i].id == id)
        {
            printf("\nAsset Found!");
            printf("\nName: %s", assets[i].name);
            printf("\nType: %s", assets[i].type);
            printf("\nValue: %.2f", assets[i].value);
            printf("\nDepartment: %s", assets[i].department);
            printf("\nCondition: %s\n", assets[i].condition);
            return;
        }
    }

    printf("\nAsset not found.\n");
}