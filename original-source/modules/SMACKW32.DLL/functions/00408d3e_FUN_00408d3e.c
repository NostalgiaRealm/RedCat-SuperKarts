/*
 * FUN_00408d3e at 00408d3e
 * undefined8 __fastcall FUN_00408d3e(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408d3e-00408e0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00408d3e(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  HMODULE in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00410844,0x104);
  pcVar3 = s_This_Dynamic_Link_Library_is_alr_0040e4e0;
  GetModuleFileNameA(in_EAX,&DAT_00410948,0x104);
  DAT_0041065c = 0;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  pcVar3 = &DAT_00410844;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  pcVar3 = s_The_Watcom_WIN32_runtime_library_0040e511;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  MessageBoxA((HWND)0x0,&DAT_0041065c,&DAT_00410948,0);
  return CONCAT44(param_2,1);
}

