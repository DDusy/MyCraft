// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCraft_Utility.h"

DEFINE_LOG_CATEGORY(DDUSY_LOG);

void DDusyLog::Log(FString _Value)
{
	//DDUSY_WARNING(TEXT("%s%s"), *_FILE, *_Function, _Line, *_Value);
}

void DDusyLog::Log(FVector _Value)
{
	//DDUSY_WARNING(TEXT("%s %s"), *_FILE, *_Function, _Line, *_Value.ToString());
}

void DDusyLog::Log(FVector2D _Value)
{
	
}

void DDusyLog::Log(float _Value)
{

}

void DDusyLog::Log(int32 _Value)
{

}

void DDusyLog::Log( int8 _Value)
{
	

}

