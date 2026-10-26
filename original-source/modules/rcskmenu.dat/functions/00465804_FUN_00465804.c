/*
 * FUN_00465804 at 00465804
 * undefined __register FUN_00465804(int * param_1, uint param_2, char param_3)
 * Address ranges: 00465804-0046584a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465804(int *param_1,uint param_2,char param_3)

{
  bool bVar1;
  HWND pHVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    iVar4 = -0x10;
    pHVar2 = (HWND)FUN_00445724(param_1);
    uVar3 = GetWindowLongA(pHVar2,iVar4);
    if (param_3 == '\0') {
      uVar3 = uVar3 & ~param_2;
    }
    else {
      uVar3 = uVar3 | param_2;
    }
    iVar4 = -0x10;
    pHVar2 = (HWND)FUN_00445724(param_1);
    SetWindowLongA(pHVar2,iVar4,uVar3);
  }
  return;
}

