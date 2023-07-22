// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Listener/FEditorListener.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FUnrealCSharpEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void PluginButtonClicked() const;

private:
	void RegisterMenus();

private:
	void Generator() const;

private:
	TSharedPtr<class FUICommandList> PluginCommands;

	FEditorListener EditorListener;
};
