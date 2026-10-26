/*
 * FUN_00404ac4 at 00404ac4
 * undefined __register FUN_00404ac4(VARIANT * param_1, VARIANTARG * param_2, undefined4 param_3)
 * Address ranges: 00404ac4-00404b3c;00404b44-00404ba1;00404ba9-00404bb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404ac4(VARIANT *param_1,VARIANTARG *param_2,undefined4 param_3)

{
  VARTYPE VVar1;
  VARTYPE VVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  _union_2683 local_14;
  
  VVar1 = (param_2->n1).n2.vt;
  VVar2 = (VARTYPE)param_3;
  if (VVar2 == VVar1) {
    puStack_20 = (undefined1 *)0x404ae0;
    FUN_004048b0(param_1,param_2);
  }
  else if (VVar1 == 0x100) {
    if (VVar2 != 8) {
      local_14.n2.vt = 0;
      puStack_20 = (undefined1 *)0x404b0c;
      FUN_00404aa4((VARIANTARG *)&local_14.n2,(int)param_2);
      puStack_24 = &LAB_00404b3d;
      uStack_28 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_28;
      puStack_20 = &stack0xfffffffc;
      FUN_004049d0(param_1,(VARIANTARG *)&local_14.n2,param_3);
      *in_FS_OFFSET = uStack_28;
      puStack_20 = (undefined1 *)0x404bb3;
      puStack_24 = (undefined1 *)0x404b3c;
      FUN_0040486c((VARIANTARG *)&local_14.n2);
      return;
    }
    puStack_20 = (undefined1 *)0x404af9;
    FUN_00404aa4(param_1,(int)param_2);
  }
  else if ((VVar2 == 0x100) && (VVar1 != 0x101)) {
    if (VVar1 != 8) {
      local_14.n2.vt = 0;
      puStack_20 = (undefined1 *)0x404b73;
      FUN_004049d0((VARIANTARG *)&local_14.n2,param_2,CONCAT22((short)((uint)param_3 >> 0x10),8));
      puStack_24 = &LAB_00404ba2;
      uStack_28 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_28;
      puStack_20 = &stack0xfffffffc;
      FUN_00404a74(param_1,(int)&local_14);
      *in_FS_OFFSET = uStack_28;
      puStack_20 = (undefined1 *)0x404bb3;
      puStack_24 = (undefined1 *)0x404ba1;
      FUN_0040486c((VARIANTARG *)&local_14.n2);
      return;
    }
    puStack_20 = (undefined1 *)0x404b5f;
    FUN_00404a74(param_1,(int)param_2);
  }
  else {
    puStack_20 = (undefined1 *)0x404bb3;
    FUN_004049d0(param_1,param_2,param_3);
  }
  return;
}

