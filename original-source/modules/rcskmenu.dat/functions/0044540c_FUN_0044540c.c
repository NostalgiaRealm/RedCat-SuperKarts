/*
 * FUN_0044540c at 0044540c
 * undefined __register FUN_0044540c(int param_1, int param_2)
 * Address ranges: 0044540c-004454e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044540c(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  HWND hWndInsertAfter;
  int *piVar4;
  
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x134) != 0) {
      param_2 = param_2 - *(int *)(*(int *)(iVar3 + 0x134) + 8);
    }
    iVar3 = FUN_0040f70c(*(int *)(iVar3 + 0x180),param_1);
    if (-1 < iVar3) {
      piVar4 = *(int **)(*(int *)(param_1 + 0x24) + 0x180);
      iVar1 = piVar4[2];
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar1 <= param_2) {
        param_2 = iVar1 + -1;
      }
      if (iVar3 != param_2) {
        FUN_0040f550(piVar4,iVar3);
        FUN_0040f72c(*(int **)(*(int *)(param_1 + 0x24) + 0x180),param_2,param_1);
      }
    }
    if (*(int *)(param_1 + 0x14c) != 0) {
      if (param_2 == 0) {
        hWndInsertAfter = (HWND)0x1;
      }
      else {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x180);
        if (param_2 == puVar2[2] + -1) {
          hWndInsertAfter = (HWND)0x0;
        }
        else if (iVar3 < param_2) {
          piVar4 = (int *)FUN_0040f6b0(puVar2,param_2 + 1);
          hWndInsertAfter = (HWND)FUN_00445724(piVar4);
        }
        else {
          if (iVar3 <= param_2) {
            return;
          }
          piVar4 = (int *)FUN_0040f6b0(puVar2,param_2);
          hWndInsertAfter = (HWND)FUN_00445724(piVar4);
        }
      }
      SetWindowPos(*(HWND *)(param_1 + 0x14c),hWndInsertAfter,0,0,0,0,3);
    }
  }
  return;
}

