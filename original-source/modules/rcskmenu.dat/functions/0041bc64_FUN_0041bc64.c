/*
 * FUN_0041bc64 at 0041bc64
 * undefined __register FUN_0041bc64(int * param_1)
 * Address ranges: 0041bc64-0041bd42;0041bd4a-0041bd4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bc64(int *param_1)

{
  HDC hdc;
  HGDIOBJ pvVar1;
  HPALETTE pHVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  if (param_1[0x16] != 0) {
    puStack_14 = (undefined1 *)0x41bc82;
    FUN_004185e8((int)param_1);
    puStack_18 = &LAB_0041bd43;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    puStack_14 = &stack0xfffffffc;
    FUN_0041cf14(param_1[0x16]);
    FUN_0041bae0(*(int *)(*(int *)(param_1[0x16] + 0x20) + 8));
    FUN_0041d064(param_1[0x16]);
    hdc = CreateCompatibleDC((HDC)0x0);
    pvVar1 = *(HGDIOBJ *)(*(int *)(param_1[0x16] + 0x20) + 8);
    if (pvVar1 == (HGDIOBJ)0x0) {
      param_1[0x17] = 0;
    }
    else {
      pvVar1 = SelectObject(hdc,pvVar1);
      param_1[0x17] = (int)pvVar1;
    }
    pHVar2 = *(HPALETTE *)(*(int *)(param_1[0x16] + 0x20) + 0x10);
    if (pHVar2 == (HPALETTE)0x0) {
      param_1[0x18] = 0;
    }
    else {
      pHVar2 = SelectPalette(hdc,pHVar2,-1);
      param_1[0x18] = (int)pHVar2;
      RealizePalette(hdc);
    }
    FUN_00418a14(param_1,(int)hdc);
    FUN_0040f9e8(DAT_0047b5dc,(int)param_1);
    *in_FS_OFFSET = uStack_1c;
    puStack_14 = (undefined1 *)0x41bd4a;
    puStack_18 = (undefined1 *)0x41bd42;
    FUN_0041888c((int)param_1);
    return;
  }
  return;
}

