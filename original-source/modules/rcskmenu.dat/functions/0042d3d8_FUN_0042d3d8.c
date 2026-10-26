/*
 * FUN_0042d3d8 at 0042d3d8
 * undefined FUN_0042d3d8(void)
 * Address ranges: 0042d3d8-0042d647;0042d65b-0042d662
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042d3d8(int *param_1,int *param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  HWND pHVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  int *piVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  DAT_0047b6b8 = DAT_0047b6b8 + 1;
  if (param_1[0x8e] == 0) {
    if (param_1 == param_2) {
      param_1[0x82] = 0;
    }
    else {
      param_1[0x82] = (int)param_2;
    }
  }
  *(int **)(DAT_0047d774 + 0x58) = param_2;
  *(int **)(DAT_0047d774 + 0x5c) = param_1;
  puStack_18 = (undefined1 *)0x42d42f;
  FUN_0040f848(*(int **)(DAT_0047d774 + 0x44),(int)param_1);
  puStack_18 = (undefined1 *)0x42d440;
  FUN_0040f72c(*(int **)(DAT_0047d774 + 0x44),0,(int)param_1);
  puStack_18 = (undefined1 *)0x42d44d;
  uVar3 = FUN_00403024(param_1,(int)&PTR_FUN_00428110);
  if ((char)uVar3 == '\0') {
    *(undefined4 *)(DAT_0047d774 + 0x60) = 0;
  }
  else {
    *(int **)(DAT_0047d774 + 0x60) = param_1;
    puStack_18 = (undefined1 *)0x42d468;
    FUN_0040f848(*(int **)(DAT_0047d774 + 0x40),(int)param_1);
    puStack_18 = (undefined1 *)0x42d479;
    FUN_0040f72c(*(int **)(DAT_0047d774 + 0x40),0,(int)param_1);
  }
  if ((*(byte *)(param_2 + 0x11) & 0x20) != 0) {
    return (int *)0x0;
  }
  *(ushort *)(param_2 + 0x11) = *(ushort *)(param_2 + 0x11) | 0x20;
  puStack_1c = &LAB_0042d648;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  piVar1 = *(int **)(DAT_0047d774 + 0x6c);
  puStack_18 = &stack0xfffffffc;
  if (param_1 != piVar1) {
    puStack_18 = &stack0xfffffffc;
    if (piVar1 != (int *)0x0) {
      puStack_18 = &stack0xfffffffc;
      pHVar4 = (HWND)FUN_00445724(piVar1);
      *(undefined4 *)(DAT_0047d774 + 0x6c) = 0;
      bVar2 = FUN_004294c0(pHVar4,0xb001);
      if (!bVar2) {
        FUN_004036a4();
        return (int *)0x0;
      }
    }
    *(int **)(DAT_0047d774 + 0x6c) = param_1;
    pHVar4 = (HWND)FUN_00445724(param_1);
    bVar2 = FUN_004294c0(pHVar4,CONCAT22(extraout_var,0xb000));
    if (!bVar2) {
      FUN_004036a4();
      return (int *)0x0;
    }
  }
  if (param_1[0x83] == 0) {
    param_1[0x83] = (int)param_1;
  }
  if ((int *)param_1[0x83] != param_2) {
    while ((param_1[0x83] != 0 && (bVar2 = thunk_FUN_0044243d(param_1[0x83],(int)param_2), !bVar2)))
    {
      pHVar4 = (HWND)FUN_00445724((int *)param_1[0x83]);
      param_1[0x83] = *(int *)(param_1[0x83] + 0x24);
      bVar2 = FUN_004294c0(pHVar4,CONCAT22(extraout_var_00,0xb01b));
      if (!bVar2) {
        FUN_004036a4();
        return (int *)0x0;
      }
    }
    while (piVar1 = param_2, (int *)param_1[0x83] != param_2) {
      do {
        piVar5 = piVar1;
        piVar1 = (int *)piVar5[9];
      } while ((int *)piVar5[9] != (int *)param_1[0x83]);
      param_1[0x83] = (int)piVar5;
      pHVar4 = (HWND)FUN_00445724(piVar5);
      bVar2 = FUN_004294c0(pHVar4,CONCAT22(extraout_var_01,0xb01a));
      if (!bVar2) {
        FUN_004036a4();
        return (int *)0x0;
      }
    }
    for (piVar1 = (int *)param_2[9]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[9]) {
      uVar3 = FUN_00403024(piVar1,(int)&PTR_FUN_004270a8);
      if ((char)uVar3 != '\0') {
        (**(code **)(*piVar1 + 0xb8))(piVar1,param_2);
      }
    }
    FUN_004405f0((int)param_1,0xb007,0,param_2);
    piVar1 = (int *)param_1[0x99];
    if ((piVar1 != (int *)0x0) && (piVar1 != param_2)) {
      FUN_004405f0((int)piVar1,0xb02a,0,0);
    }
  }
  *in_FS_OFFSET = uStack_20;
  *(ushort *)(param_2 + 0x11) = *(ushort *)(param_2 + 0x11) & 0xffdf;
  return param_2;
}

