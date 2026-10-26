/*
 * FUN_0048ed00 at 0048ed00
 * undefined FUN_0048ed00(void)
 * Address ranges: 0048ed00-0048ed5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __thiscall FUN_0048ed00(int param_1,LPCSTR param_2)

{
  char cVar1;
  int iVar2;
  WCHAR local_208 [260];
  
  FUN_0048ecd0();
  cVar1 = FUN_0048ec50();
  if (cVar1 == '\0') {
    return false;
  }
  MultiByteToWideChar(0,0,param_2,-1,local_208,0x104);
  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x34))(*(int **)(param_1 + 4),local_208,0);
  return -1 < iVar2;
}

