/*
 * FUN_00432cb8 at 00432cb8
 * undefined __register FUN_00432cb8(int param_1, UINT param_2, undefined1 param_3)
 * Address ranges: 00432cb8-00432cef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432cb8(int param_1,UINT param_2,undefined1 param_3)

{
  UINT_PTR UVar1;
  
  FUN_00432cf0(param_1);
  UVar1 = SetTimer((HWND)0x0,0,param_2,FUN_00430cc4);
  *(short *)(param_1 + 0x7a) = (short)UVar1;
  *(undefined1 *)(param_1 + 0x79) = param_3;
  if (*(short *)(param_1 + 0x7a) == 0) {
    FUN_00432e8c(param_1);
  }
  return;
}

