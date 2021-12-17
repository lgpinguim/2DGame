// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Jogo2D : ModuleRules
{
	public Jogo2D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });
	}
}
