/*
 * FUN_00474048 at 00474048
 * undefined __register FUN_00474048(void)
 * Address ranges: 00474048-004740f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00474048(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004578f0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
  if (iVar1 != -1) {
    FUN_00457cd0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar1);
    iVar2 = FUN_00457c88(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar1);
    if (iVar2 < 0) {
      iVar2 = FUN_00457cac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar1);
    }
    FUN_004578f4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar2);
    FUN_0045792c(*(undefined4 *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar2);
    *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x14) = iVar2;
    FUN_0045aa5c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
  }
  return;
}

