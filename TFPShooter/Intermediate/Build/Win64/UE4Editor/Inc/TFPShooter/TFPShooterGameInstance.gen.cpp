// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TFPShooter/TFPShooterGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTFPShooterGameInstance() {}
// Cross Module References
	TFPSHOOTER_API UClass* Z_Construct_UClass_UTFPShooterGameInstance_NoRegister();
	TFPSHOOTER_API UClass* Z_Construct_UClass_UTFPShooterGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_TFPShooter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	TFPSHOOTER_API UClass* Z_Construct_UClass_ATFPShooterCharacter_NoRegister();
// End Cross Module References
	void UTFPShooterGameInstance::StaticRegisterNativesUTFPShooterGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UTFPShooterGameInstance_NoRegister()
	{
		return UTFPShooterGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UTFPShooterGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BP_SMC_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_BP_SMC;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTFPShooterGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TFPShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTFPShooterGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "TFPShooterGameInstance.h" },
		{ "ModuleRelativePath", "TFPShooterGameInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_BP_SMC_MetaData[] = {
		{ "Category", "TFPShooterGameInstance" },
		{ "ModuleRelativePath", "TFPShooterGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_BP_SMC = { "BP_SMC", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTFPShooterGameInstance, BP_SMC), Z_Construct_UClass_ATFPShooterCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_BP_SMC_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_BP_SMC_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTFPShooterGameInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_BP_SMC,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTFPShooterGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTFPShooterGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTFPShooterGameInstance_Statics::ClassParams = {
		&UTFPShooterGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTFPShooterGameInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTFPShooterGameInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UTFPShooterGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTFPShooterGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTFPShooterGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTFPShooterGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTFPShooterGameInstance, 1164338178);
	template<> TFPSHOOTER_API UClass* StaticClass<UTFPShooterGameInstance>()
	{
		return UTFPShooterGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTFPShooterGameInstance(Z_Construct_UClass_UTFPShooterGameInstance, &UTFPShooterGameInstance::StaticClass, TEXT("/Script/TFPShooter"), TEXT("UTFPShooterGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTFPShooterGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
