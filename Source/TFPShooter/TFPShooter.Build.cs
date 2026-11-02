using UnrealBuildTool;

public class TFPShooter : ModuleRules
{
	public TFPShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        //PrivatePCHHeaderFile = "TFPShooter.h";
        //MinFilesUsingPrecompiledHeaderOverride = 1;
        //bUseUnity = false;

        PublicDependencyModuleNames.AddRange(new string[] 
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput",
			"HeadMountedDisplay",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
        });
	}
}
