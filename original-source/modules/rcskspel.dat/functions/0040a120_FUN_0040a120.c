/*
 * FUN_0040a120 at 0040a120
 * undefined FUN_0040a120(void)
 * Address ranges: 0040a120-0040a1a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040a120(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 local_c [12];
  
  bVar1 = false;
  if (-1 < param_2) {
    iVar3 = DAT_00680ae0 + param_2 * 0x50;
    iVar2 = *(int *)(iVar3 + 0x14);
    if (((iVar2 < 0) && (iVar2 = *(int *)(iVar3 + 0x1c), iVar2 < 0)) &&
       (iVar2 = *(int *)(iVar3 + 0x18), iVar2 < 0)) {
      iVar2 = *(int *)(iVar3 + 0x20);
      if (iVar2 < 0) {
        return 1;
      }
      bVar1 = true;
    }
    FUN_004113c0(iVar2,local_c);
    iVar3 = FUN_00401320(param_1,local_c);
    iVar2 = iVar3;
    if ((bVar1) && (iVar2 = iVar3 + -0x800, iVar2 < 0)) {
      iVar2 = iVar3 + 0x800;
    }
    if ((0x3ff < iVar2) && (iVar2 < 0xc01)) {
      return 0xffffffff;
    }
  }
  return 1;
}

