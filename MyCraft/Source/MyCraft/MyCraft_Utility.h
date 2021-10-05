#pragma once

#include"CoreMinimal.h"

// 이름 , Log? , ALL?
DECLARE_LOG_CATEGORY_EXTERN(DDUSY_LOG,Log, All);

#define __FILENAME__ (strrchr(__FILE__,'\\')+1 )

#define DDUSY_LOG_CALLINFO (FString(__FILENAME__) + TEXT("	")+ FString(__FUNCTION__) +TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define DDUSY_LOG(Verbosity,Format,...) UE_LOG(DDUSY_LOG,Verbosity,TEXT("%s %s"), *DDUSY_LOG_CALLINFO, *FString::Printf(Format,##__VA_ARGS__))

//#define DDUSY_WARNING(Format,...) UE_LOG(DDUSY_LOG,Warning,TEXT("%s %s"), *DDUSY_LOG_CALLINFO, *FString::Printf(Format,##__VA_ARGS__))

//*DDUSY_LOG_CALLINFO
#define DDUSY_WARNING(Format,...) UE_LOG(DDUSY_LOG,Warning, TEXT(Format), *DDUSY_LOG_CALLINFO,__VA_ARGS__)


//C++ ## 매크로 매개변수를 문자화
#define DDUSY_CHECK(Expr,...){if(!(Expr)) {DDUSY_LOG(Error,TEXT("ASSERTION : %s"),TEXT("'"#Expr"'")); return __VA_ARGS; }}


class DDusyLog
{
public:

	void Log(FString _Value);
	void Log(FVector _Value);
	void Log(FVector2D _Value);
	void Log(float _Value);
	void Log(int32 _Value);
	void Log(int8 _Value);


};