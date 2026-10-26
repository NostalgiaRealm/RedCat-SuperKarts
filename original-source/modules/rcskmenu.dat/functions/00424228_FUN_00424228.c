/*
 * FUN_00424228 at 00424228
 * undefined __register FUN_00424228(int * param_1)
 * Address ranges: 00424228-0042425e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424228(int *param_1)

{
  bool bVar1;
  HWND hWnd;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar4;
  int nIndex;
  
  (**(code **)(*param_1 + -0x10))();
  bVar1 = FUN_00445a20((int)param_1);
  uVar3 = extraout_ECX;
  uVar4 = extraout_EDX;
  if (bVar1) {
    nIndex = -0x10;
    hWnd = (HWND)FUN_00445724(param_1);
    uVar2 = GetWindowLongA(hWnd,nIndex);
    uVar3 = extraout_ECX_00;
    uVar4 = extraout_EDX_00;
    if ((uVar2 & 4) == 0) {
      return;
    }
  }
  FUN_00403088(param_1,uVar4,uVar3);
  return;
}

