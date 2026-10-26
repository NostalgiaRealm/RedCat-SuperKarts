/*
 * FUN_00439f3c at 00439f3c
 * undefined __register FUN_00439f3c(int * param_1, undefined4 param_2, int param_3, undefined1 param_4)
 * Address ranges: 00439f3c-00439f93
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439f3c(int *param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  undefined4 uVar1;
  
  if (param_1[0xb] != 0) {
    uVar1 = FUN_004398c0(param_1);
    if (param_3 == 0) {
      SendMessageA((HWND)param_1[0xb],0xb015,0,0);
    }
    if ((char)uVar1 != '\0') {
      DrawMenuBar((HWND)param_1[0xb]);
    }
  }
  FUN_00439a38(param_1,param_2,param_3,param_4);
  return;
}

