/*
 * FUN_00446db8 at 00446db8
 * undefined __register FUN_00446db8(int param_1)
 * Address ranges: 00446db8-00446e77;00446e7f-00446e83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446db8(int param_1)

{
  UINT flags;
  int cx;
  HICON pHVar1;
  undefined4 *in_FS_OFFSET;
  int cy;
  undefined4 uVar2;
  int cInitial;
  int cGrow;
  POINT local_10;
  HIMAGELIST local_8;
  
  if (*(short *)(param_1 + 0x60) != -1) {
    cGrow = 1;
    cInitial = 0xe;
    flags = (**(code **)PTR_DAT_0047c734)();
    cy = 0xd;
    cx = (**(code **)PTR_DAT_0047c734)();
    local_8 = ImageList_Create(cx,cy,flags,cInitial,cGrow);
    uVar2 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffd8;
    pHVar1 = (HICON)FUN_00430608(*(int *)PTR_DAT_0047c9bc,(int)*(short *)(param_1 + 0x60));
    FUN_00415984(local_8,pHVar1);
    pHVar1 = (HICON)FUN_00430608(*(int *)PTR_DAT_0047c9bc,(int)*(short *)(param_1 + 0x60));
    FUN_00415984(local_8,pHVar1);
    ImageList_SetDragCursorImage(local_8,0,0,0);
    ImageList_GetDragImage((POINT *)0x0,&local_10);
    ImageList_SetDragCursorImage(local_8,1,local_10.x,local_10.y);
    *in_FS_OFFSET = uVar2;
    ImageList_Destroy(local_8);
    return;
  }
  return;
}

