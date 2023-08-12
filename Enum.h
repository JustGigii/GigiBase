#pragma once
#ifndef Enum_h
#define Enum_h  
typedef enum
{
	CANNOT_ALLOCTE,
	SUCCES,
	NOT_FOUND

}Erros;
typedef enum
{
	NUMBER,
	LONG,
	SHORT,
	UNUMBER,
	ULONG,
	USHORT,
	DOUBLE,
	FLOAT,
	VARCHAR,
	BOOL,
	TIME,
} DataType;
#endif