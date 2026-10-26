/*
 * FUN_0043271c at 0043271c
 * undefined FUN_0043271c(void)
 * Address ranges: 0043271c-00432845
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0043271c(int param_1,ushort param_2,ULONG_PTR param_3)

{
  int *piVar1;
  bool bVar2;
  HWND pHVar3;
  LPCSTR pCVar4;
  BOOL BVar5;
  uint uVar6;
  char acStack_10 [4];
  
  uVar6 = 0;
  acStack_10[0] = '\x01';
  piVar1 = *(int **)(DAT_0047d774 + 0x5c);
  if ((piVar1 == (int *)0x0) || (*(short *)((int)piVar1 + 0x292) == 0)) {
    if (*(short *)(param_1 + 0xca) != 0) {
      uVar6 = (**(code **)(param_1 + 200))
                        (*(undefined4 *)(param_1 + 0xcc),param_2,param_3,acStack_10);
    }
  }
  else {
    uVar6 = (*(code *)piVar1[0xa4])(piVar1[0xa5],param_2,param_3,acStack_10);
  }
  if (acStack_10[0] != '\0') {
    if (((piVar1 != (int *)0x0) && (bVar2 = FUN_00445a20((int)piVar1), bVar2)) &&
       (piVar1[0x89] != 0)) {
      pHVar3 = (HWND)FUN_00445724(piVar1);
      uVar6 = (uint)param_2;
      pCVar4 = FUN_00403f94((undefined *)piVar1[0x89]);
      BVar5 = WinHelpA(pHVar3,pCVar4,uVar6,param_3);
      return (uint)(BVar5 != 0);
    }
    if (*(int *)(param_1 + 0x40) == 0) {
      if (*(char *)(param_1 + 0x94) == '\0') {
        PostMessageA(*(HWND *)(param_1 + 0x24),0xb01f,(uint)param_2,param_3);
      }
    }
    else {
      pHVar3 = *(HWND *)(param_1 + 0x24);
      if (*(int **)(param_1 + 0x38) != (int *)0x0) {
        pHVar3 = (HWND)FUN_00445724(*(int **)(param_1 + 0x38));
      }
      uVar6 = (uint)param_2;
      pCVar4 = FUN_00403f94(*(undefined **)(param_1 + 0x40));
      BVar5 = WinHelpA(pHVar3,pCVar4,uVar6,param_3);
      uVar6 = (uint)(BVar5 != 0);
    }
  }
  return uVar6;
}

