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
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_charSkeletalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_charSkeletalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_charMaterialInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_charMaterialInstance;
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charSkeletalMesh_MetaData[] = {
		{ "Category", "TFPShooterGameInstance" },
		{ "ModuleRelativePath", "TFPShooterGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charSkeletalMesh = { "charSkeletalMesh", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTFPShooterGameInstance, charSkeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charSkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charSkeletalMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charMaterialInstance_MetaData[] = {
		{ "Category", "TFPShooterGameInstance" },
		{ "ModuleRelativePath", "TFPShooterGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charMaterialInstance = { "charMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTFPShooterGameInstance, charMaterialInstance), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charMaterialInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charMaterialInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTFPShooterGameInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charSkeletalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTFPShooterGameInstance_Statics::NewProp_charMaterialInstance,
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
	IMPLEMENT_CLASS(UTFPShooterGameInstance, 856330576);
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
