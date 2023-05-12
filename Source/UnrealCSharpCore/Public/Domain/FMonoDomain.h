﻿#pragma once

#include "mono/metadata/appdomain.h"

struct UNREALCSHARPCORE_API FMonoDomainInitializeParams
{
	FString Domain;

	FString AssemblyUtil;

	TArray<FString> Assemblies;

	FMonoDomainInitializeParams(const FString& InDomain, const FString& InAssemblyUtil,
	                            const TArray<FString>& InAssemblies):
		Domain(InDomain),
		AssemblyUtil(InAssemblyUtil),
		Assemblies(InAssemblies)
	{
	}
};

class UNREALCSHARPCORE_API FMonoDomain
{
public:
	static void Initialize(const FMonoDomainInitializeParams& InParams);

	static void Deinitialize();

public:
	static MonoObject* Object_New(MonoClass* InMonoClass);

	static MonoObject* Object_New(MonoClass* InMonoClass, const int32 InParamCount, void** InParams);

	static void Runtime_Object_Init(MonoObject* InMonoObject);

	static MonoClass* Class_From_Name(const FString& InNameSpace, const FString& InMonoClassName);

	static MonoMethod* Class_Get_Method_From_Name(MonoClass* InMonoClass, const FString& InFunctionName,
	                                              int32 InParamCount);

	static mono_bool Class_Is_Subclass_Of(MonoClass* InMonoClass, MonoClass* InSuperMonoClass,
	                                      mono_bool bCheckInterfaces);

	static const char* Class_Get_Name(MonoClass* InMonoClass);

	static MonoClass* Class_Get_Parent(MonoClass* InMonoClass);

	static MonoType* Class_Get_Type(MonoClass* InMonoClass);

	static MonoClassField* Class_Get_Fields(MonoClass* InMonoClass, void** InIterator);

	static MonoProperty* Class_Get_Properties(MonoClass* InMonoClass, void** InIterator);

	static MonoMethod* Class_Get_Methods(MonoClass* InMonoClass, void** InIterator);

	static MonoCustomAttrInfo* Custom_Attrs_From_Field(MonoClass* InMonoClass, MonoClassField* InMonoClassField);

	static MonoCustomAttrInfo* Custom_Attrs_From_Property(MonoClass* InMonoClass, MonoProperty* InMonoProperty);

	static MonoCustomAttrInfo* Custom_Attrs_From_Method(MonoMethod* InMonoMethod);

	static mono_bool Custom_Attrs_Has_Attr(MonoCustomAttrInfo* InMonoCustomAttrInfo, MonoClass* InMonoClass);

	static const char* Field_Get_Name(MonoClassField* InMonoClassField);

	static MonoType* Field_Get_Type(MonoClassField* InMonoClassField);

	static const char* Property_Get_Name(MonoProperty* InMonoProperty);

	static MonoMethod* Property_Get_Get_Method(MonoProperty* InMonoProperty);

	static const char* Method_Get_Name(MonoMethod* InMonoMethod);

	static void Method_Get_Param_Names(MonoMethod* InMonoMethod, const char** InNames);

	static MonoMethodSignature* Method_Signature(MonoMethod* InMonoMethod);

	static uint32_t Signature_Get_Param_Count(MonoMethodSignature* InMonoMethodSignature);

	static MonoType* Signature_Get_Params(MonoMethodSignature* InMonoMethodSignature, void** InIterator);

	static MonoType* Signature_Get_Return_Type(MonoMethodSignature* InMonoMethodSignature);

	static MonoType* Reflection_Type_Get_Type(MonoReflectionType* InMonoReflectionType);

	static MonoClass* Type_Get_Class(MonoType* InMonoType);

	static MonoReflectionType* Type_Get_Object(MonoType* InMonoType);

	static MonoType* Type_Get_Underlying_Type(MonoType* InMonoType);

	static MonoReflectionMethod* Method_Get_Object(MonoMethod* InMethod, MonoClass* InMonoClass);

	static MonoObject* Runtime_Invoke(MonoMethod* InFunction, void* InMonoObject, void** InParams);

	static MonoObject* Runtime_Invoke(MonoMethod* InFunction, void* InMonoObject, void** InParams, MonoObject** InExc);

	static MonoObject* Runtime_Delegate_Invoke(MonoObject* InDelegate, void** InParams);

	static MonoObject* Runtime_Delegate_Invoke(MonoObject* InDelegate, void** InParams, MonoObject** InExc);

	static void Unhandled_Exception(MonoObject* InException);

	static MonoClass* Object_Get_Class(MonoObject* InMonoObject);

	static MonoObject* Value_Box(MonoClass* InMonoClass, void* InValue);

	static void* Object_Unbox(MonoObject* InMonoObject);

	static MonoString* String_New(const char* InText);

	static MonoString* Object_To_String(MonoObject* InMonoObject, MonoObject** InExc);

	static char* String_To_UTF8(MonoString* InMonoString);

	static MonoArray* Array_New(MonoClass* InMonoClass, uint32 InNum);

	static uint64 Array_Length(MonoArray* InMonoArray);

	static MonoClass* Get_Byte_Class();

	static MonoClass* Get_Object_Class();

	static MonoClass* Get_UInt16_Class();;

	static MonoClass* Get_UInt32_Class();

	static MonoClass* Get_UInt64_Class();

	static MonoClass* Get_Int16_Class();

	static MonoClass* Get_Int32_Class();

	static MonoClass* Get_Int64_Class();

	static MonoClass* Get_Boolean_Class();

	static MonoClass* Get_Single_Class();

	static MonoClass* Get_Enum_Class();

	static MonoClass* Get_Double_Class();

	static uint32 GCHandle_New(MonoObject* InMonoObject, mono_bool bPinned);

	static uint32 GCHandle_New_WeakRef(MonoObject* InMonoObject, mono_bool bTrackResurrection);

	static MonoObject* GCHandle_Get_Target(uint32 InGCHandle);

	static void GCHandle_Free(uint32 InGCHandle);

public:
	static MonoMethod* Parent_Class_Get_Method_From_Name(MonoClass* InMonoClass, const FString& InFunctionName,
	                                                     int32 InParamCount);

	static MonoType* Property_Get_Type(MonoProperty* InMonoProperty);

public:
	static void InitializeAssembly(const TArray<FString>& InAssemblies);

	static void DeinitializeAssembly();

	static void InitializeAssemblyLoadContext();

	static void DeinitializeAssemblyLoadContext();

	static void LoadAssembly(const TArray<FString>& InAssemblies);

	static void UnloadAssembly();

private:
	static void RegisterMonoTrace();

	static void RegisterLog();

public:
	static MonoDomain* Domain;

	static MonoAssembly* AssemblyUtilAssembly;

	static MonoImage* AssemblyUtilImage;

	static TArray<MonoGCHandle> AssemblyGCHandles;

	static TArray<MonoAssembly*> Assemblies;

	static TArray<MonoImage*> Images;
};