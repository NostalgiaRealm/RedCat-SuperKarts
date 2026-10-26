/*
 * FUN_00406e30 at 00406e30
 * undefined4 __fastcall FUN_00406e30(undefined4 param_1, undefined4 param_2, byte param_3)
 * Address ranges: 00406e30-00407012
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00406e30(undefined4 param_1,undefined4 param_2,byte param_3)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  HWND hWnd;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_EBX;
  uint uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint auStack_28 [2];
  DWORD aDStack_20 [2];
  
  if (DAT_0040e888 < 0x20) {
    return 1;
  }
  if (DAT_0040e87c == (int *)0x0) {
    iVar3 = (*DAT_004104d0)(0,&DAT_0040e87c,0);
    if (iVar3 != 0) {
      return 1;
    }
    hWnd = GetTopWindow((HWND)0x0);
    DVar4 = GetCurrentProcessId();
    while ((hWnd != (HWND)0x0 && (GetWindowThreadProcessId(hWnd,aDStack_20), DVar4 != aDStack_20[0])
           )) {
      hWnd = GetWindow(hWnd,2);
    }
    if (hWnd == (HWND)0x0) {
      hWnd = GetActiveWindow();
    }
    DAT_0040e880 = '\x01';
    (**(code **)(*DAT_0040e87c + 0x18))(DAT_0040e87c,hWnd,1);
    param_1 = extraout_ECX;
    param_2 = extraout_EDX;
  }
  puVar5 = (undefined4 *)FUN_00402c30(param_1,param_2,0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    puVar8 = puVar5;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    puVar9 = auStack_28;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    auStack_28[0] = 0x14;
    if ((param_3 & 0x40) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0x80;
    }
    if ((param_3 & 0x20) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x40;
    }
    auStack_28[1] = uVar6 | uVar7 | 0x4000;
    uVar7 = (uint)unaff_EBX[2] >> 4 & 0xfffffffc;
    puVar5[3] = uVar7;
    aDStack_20[0] = uVar7 << 2;
    puVar5[4] = aDStack_20[0];
    iVar3 = (**(code **)(*DAT_0040e87c + 0xc))(DAT_0040e87c,auStack_28,puVar5 + 1,0);
    if (iVar3 == 0) {
      (**(code **)(*(int *)puVar5[1] + 0x3c))((int *)puVar5[1],0);
      if (*(short *)((int)unaff_EBX + 0xe) == 8) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x2a) = uVar2;
      puVar5[9] = unaff_EBX[2];
      puVar5[2] = DAT_0040e874;
      DAT_0040e874 = puVar5;
      *unaff_EBX = puVar5;
      return 0;
    }
    FUN_00402c10();
  }
  piVar1 = DAT_0040e874;
  if ((DAT_0040e874 == (int *)0x0) && (DAT_0040e880 != '\0')) {
    (**(code **)(*DAT_0040e87c + 8))(DAT_0040e87c);
    DAT_0040e87c = piVar1;
  }
  return 1;
}

