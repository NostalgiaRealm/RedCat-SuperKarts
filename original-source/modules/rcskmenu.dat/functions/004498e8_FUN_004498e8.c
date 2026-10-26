/*
 * FUN_004498e8 at 004498e8
 * undefined __register FUN_004498e8(int param_1, int param_2)
 * Address ranges: 004498e8-00449948
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004498e8(int param_1,int param_2)

{
  LRESULT LVar1;
  LRESULT extraout_ECX;
  undefined4 extraout_EDX;
  
  if (param_2 == 0) {
    FUN_0044984c(param_1);
    if (*(char *)(param_1 + 0xd) != '\0') {
      FUN_00449868(param_1);
      return;
    }
    FUN_00449898(param_1,extraout_EDX,extraout_ECX);
  }
  else if ((param_2 == 0x68) && (*(char *)(param_1 + 0x20) != '\0')) {
    if (*(char *)(param_1 + 0xd) == '\0') {
      LVar1 = SendMessageA(*(HWND *)(param_1 + 0x18),*(UINT *)(param_1 + 0x14),0,0);
      *(LRESULT *)(param_1 + 0x10) = LVar1;
    }
    else {
      SystemParametersInfoA(0x68,0,(PVOID)(param_1 + 0x10),0);
    }
  }
  return;
}

