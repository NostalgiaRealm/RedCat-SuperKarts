/*
 * FUN_0044b8c0 at 0044b8c0
 * undefined FUN_0044b8c0(void)
 * Address ranges: 0044b8c0-0044b9af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b8c0(int *param_1,int param_2)

{
  undefined1 *puVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  RECT *pRVar4;
  BOOL BVar5;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int iStack_18;
  RECT RStack_14;
  
  puStack_28 = &stack0xfffffffc;
  iStack_18 = 0;
  puStack_2c = &LAB_0044b9b0;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puVar1 = &stack0xfffffffc;
  if (*(char *)((int)param_1 + 0x205) == '\0') {
    FUN_0043f64c((int)param_1,&iStack_18);
    puVar1 = puStack_28;
    if (iStack_18 == 0) {
      iVar3 = param_1[0x80];
      if (*(char *)((int)param_1 + 0x1f9) != '\0') {
        iVar3 = iVar3 + param_1[0x7f];
      }
      if (*(char *)((int)param_1 + 0x1fa) != '\0') {
        iVar3 = iVar3 + param_1[0x7f];
      }
      if (0 < iVar3) {
        RStack_14.right = param_1[0xe];
        RStack_14.bottom = param_1[0xf];
        if (*(int *)(*(int *)(param_2 + 8) + 0x10) != RStack_14.right) {
          RStack_14.top = 0;
          RStack_14.left = (RStack_14.right - iVar3) + -1;
          BVar5 = -1;
          pRVar4 = &RStack_14;
          pHVar2 = (HWND)FUN_00445724(param_1);
          InvalidateRect(pHVar2,pRVar4,BVar5);
        }
        if (*(int *)(*(int *)(param_2 + 8) + 0x14) != RStack_14.bottom) {
          RStack_14.left = 0;
          RStack_14.top = (RStack_14.bottom - iVar3) + -1;
          BVar5 = -1;
          pRVar4 = &RStack_14;
          pHVar2 = (HWND)FUN_00445724(param_1);
          InvalidateRect(pHVar2,pRVar4,BVar5);
        }
      }
      goto LAB_0044b991;
    }
  }
  puStack_28 = puVar1;
  (**(code **)(*param_1 + 0x74))();
LAB_0044b991:
  FUN_00443a64(param_1,param_2);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_0044b9b7;
  puStack_2c = (undefined1 *)0x44b9af;
  FUN_00403b50(&iStack_18);
  return;
}

