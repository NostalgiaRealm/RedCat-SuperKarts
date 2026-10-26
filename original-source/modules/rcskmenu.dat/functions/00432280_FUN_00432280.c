/*
 * FUN_00432280 at 00432280
 * undefined __register FUN_00432280(int param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5)
 * Address ranges: 00432280-004322fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432280(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x94) == '\0') {
    if (*(HWND *)(param_1 + 0x24) != (HWND)0x0) {
      SendMessageA(*(HWND *)(param_1 + 0x24),0xb020,1,(LPARAM)&param_4);
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x98) + 8);
    if (-1 < iVar3 + -1) {
      iVar2 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x98),iVar2);
        if ((*piVar1 == param_4) && (param_5 == piVar1[1])) {
          FUN_0040272c((int)piVar1);
          FUN_0040f550(*(int **)(param_1 + 0x98),iVar2);
          return;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

