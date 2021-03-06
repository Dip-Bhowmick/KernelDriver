#pragma once
#include "pch.h"

#define PROCESS_ID		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x111, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IMAGE_BASE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x222, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) 
#define MODULE_BASE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x333, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) 
#define VM_QUERY		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x444, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VM_PROTECT		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x555, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) 
#define VM_READ			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x666, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VM_WRITE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x777, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VM_ALLOCATE		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x888, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VM_FREE			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x999, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
//#define CREATE_THREAD	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x000, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

typedef struct _PROCESS_ID_REQUEST {
	WCHAR ProcessName[256];
	ULONGLONG ProcessId;
} PROCESS_ID_REQUEST,* PPROCESS_ID_REQUEST;

typedef struct _IMAGE_BASE_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG ImageBase;
} IMAGE_BASE_REQUEST,* PIMAGE_BASE_REQUEST;

typedef struct _MODULE_BASE_REQUEST {
	ULONGLONG ProcessId;
	WCHAR ModuleName[256];
	ULONGLONG ModuleBase;
	ULONG ModuleSize;
} MODULE_BASE_REQUEST,* PMODULE_BASE_REQUEST;

typedef struct _VM_QUERY_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG BaseAddress;
	MEMORY_BASIC_INFORMATION MBI;
} VM_QUERY_REQUEST,* PVM_QUERY_REQUEST;

typedef struct _VM_PROTECT_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG BaseAddress;
	SIZE_T RegionSize;
	ULONG NewProtect;
	ULONG OldProtect;
} VM_PROTECT_REQUEST,* PVM_PROTECT_REQUEST;

typedef struct _VM_READ_WRITE_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG BaseAddress;
	ULONGLONG Buffer;
	SIZE_T BufferSize;
	SIZE_T NumberOfBytesReadWrite;
} VM_READ_WRITE_REQUEST,* PVM_READ_WRITE_REQUEST;

typedef struct _VM_ALLOCATE_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG BaseAddress;
	ULONGLONG ZeroBits;
	SIZE_T RegionSize;
	ULONG AllocationType;
	ULONG Protect;
} VM_ALLOCATE_REQUEST,* PVM_ALLOCATE_REQUEST;

typedef struct _VM_FREE_REQUEST {
	ULONGLONG ProcessId;
	ULONGLONG BaseAddress;
	SIZE_T RegionSize;
	ULONG FreeType;
} VM_FREE_REQUEST, * PVM_FREE_REQUEST;


NTSTATUS IoCreate(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS IoClose(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp);

