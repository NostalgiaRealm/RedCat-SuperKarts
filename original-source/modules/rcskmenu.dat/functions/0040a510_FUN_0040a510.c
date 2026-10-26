/*
 * FUN_0040a510 at 0040a510
 * uint __register FUN_0040a510(LCID param_1, LCTYPE param_2, uint param_3)
 * Address ranges: 0040a510-0040a537
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0040a510(LCID param_1,LCTYPE param_2,uint param_3)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_3;
  iVar1 = GetLocaleInfoA(param_1,param_2,(LPSTR)&local_10,2);
  if (0 < iVar1) {
    param_3 = CONCAT31((int3)((uint)iVar1 >> 8),(undefined1)local_10);
  }
  return param_3;
}

