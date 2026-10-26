/*
 * FUN_00405e47 at 00405e47
 * undefined4 __cdecl FUN_00405e47(LPCSTR param_1, byte param_2)
 * Address ranges: 00405e47-00405e8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00405e47(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    FUN_00402a47(DVar1);
  }
  else {
    if (((DVar1 & 1) == 0) || ((param_2 & 2) == 0)) {
      return 0;
    }
    DAT_00408c04 = 0xd;
    DAT_00408c08 = 5;
  }
  return 0xffffffff;
}

