/*
 * FUN_00419520 at 00419520
 * UINT __register FUN_00419520(HPALETTE param_1, LPPALETTEENTRY param_2, int param_3)
 * Address ranges: 00419520-00419570
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

UINT FUN_00419520(HPALETTE param_1,LPPALETTEENTRY param_2,int param_3)

{
  int iVar1;
  UINT local_10;
  
  local_10 = 0;
  if (param_1 != (HPALETTE)0x0) {
    iVar1 = GetObjectA(param_1,4,&local_10);
    if ((iVar1 != 0) && (local_10 != 0)) {
      if ((int)(param_3 + 1U) < (int)local_10) {
        local_10 = param_3 + 1U;
      }
      GetPaletteEntries(param_1,0,local_10,param_2);
      FUN_00419274((int)param_2,local_10);
    }
  }
  return local_10;
}

