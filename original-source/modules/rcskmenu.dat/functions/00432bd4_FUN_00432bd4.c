/*
 * FUN_00432bd4 at 00432bd4
 * undefined __register FUN_00432bd4(byte param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00432bd4-00432c2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432bd4(byte param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  BOOL BVar1;
  
  BVar1 = IsWindowVisible(*(HWND *)(*(int *)(param_4 + -4) + 0x24));
  if (((BVar1 != 0) == (bool)DAT_0047b7e4) && (param_1 != DAT_0047b7e4)) {
    SetWindowPos(*(HWND *)(*(int *)(param_4 + -4) + 0x24),(HWND)0x0,0,0,0,0,
                 (uint)*(ushort *)(&DAT_0047b7e8 + (uint)param_1 * 2));
    DAT_0047b7e4 = param_1;
  }
  return;
}

