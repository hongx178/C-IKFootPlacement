// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FootIKPlacement : ModuleRules
{
	public FootIKPlacement(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
