// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RoleOfTheWidget.h"
#include "UI_Inventory.generated.h"

class UUniformGridPanel;
class UUI_InventorySlot;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_Inventory : public UUI_RoleOfTheWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	void LayoutInventorySlot(int32 ColumnNumber, int32 RowNumber);

private:
	UPROPERTY(meta = (BindWidget))
		UUniformGridPanel* SlotArrayInventory;

	UPROPERTY(EditDefaultsOnly, Category = UI)
		TSubclassOf<UUI_InventorySlot> InventorySlotClass;

	TArray<UUI_InventorySlot*> InventorySlotArray;
};
