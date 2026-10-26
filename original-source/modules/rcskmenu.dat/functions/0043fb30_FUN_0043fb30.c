/*
 * FUN_0043fb30 at 0043fb30
 * undefined FUN_0043fb30(void)
 * Address ranges: 0043fb30-0043fc08;0043fc10-0043fc27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fb30(int *param_1)

{
  bool bVar1;
  HWND pHVar2;
  HDC hdc;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar3;
  
  if (((*(char *)((int)param_1 + 0x47) != '\0') ||
      (((*(byte *)(param_1 + 8) & 0x10) != 0 && ((*(byte *)((int)param_1 + 0x41) & 4) == 0)))) &&
     (param_1[9] != 0)) {
    bVar1 = FUN_00445a20(param_1[9]);
    if (bVar1) {
      if ((*(byte *)(param_1 + 0x10) & 0x40) != 0) {
        pHVar2 = (HWND)FUN_00445724((int *)param_1[9]);
        hdc = GetDC(pHVar2);
        uVar3 = *in_FS_OFFSET;
        *in_FS_OFFSET = &stack0xffffffe4;
        IntersectClipRect(hdc,param_1[0xc],param_1[0xd],param_1[0xc] + param_1[0xe],
                          param_1[0xd] + param_1[0xf]);
        FUN_00443524(param_1[9],hdc,(int)param_1);
        *in_FS_OFFSET = uVar3;
        pHVar2 = (HWND)FUN_00445724((int *)param_1[9]);
        ReleaseDC(pHVar2,hdc);
        return;
      }
      (**(code **)(*param_1 + 0x74))();
      (**(code **)(*param_1 + 0x80))();
    }
  }
  return;
}

