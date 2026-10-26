/*
 * FUN_004294c0 at 004294c0
 * bool __register FUN_004294c0(HWND param_1, uint param_2)
 * Address ranges: 004294c0-004294df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004294c0(HWND param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DAT_0047b6b8;
  SendMessageA(param_1,param_2 & 0xffff,0,0);
  return iVar1 == DAT_0047b6b8;
}

