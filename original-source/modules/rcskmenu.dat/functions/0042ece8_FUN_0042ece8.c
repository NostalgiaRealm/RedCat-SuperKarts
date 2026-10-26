/*
 * FUN_0042ece8 at 0042ece8
 * undefined FUN_0042ece8(void)
 * Address ranges: 0042ece8-0042ed55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ece8(int *param_1)

{
  undefined1 *puVar1;
  char cVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_14 = &LAB_0042ed56;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  if (*(char *)((int)param_1 + 0x216) != '\0') goto LAB_0042ed40;
  puVar1 = &stack0xfffffffc;
  if (*(char *)((int)param_1 + 0x47) == '\0') {
LAB_0042ed18:
    puStack_10 = puVar1;
    FUN_00405438((undefined4 *)PTR_PTR_0047c93c,(int *)&puStack_8);
    piVar3 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',puStack_8);
    FUN_00403604(piVar3);
  }
  else {
    cVar2 = (**(code **)(*param_1 + 0x4c))();
    puVar1 = puStack_10;
    if (cVar2 == '\0') goto LAB_0042ed18;
  }
  FUN_0042d66c(param_1);
LAB_0042ed40:
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0042ed5d;
  puStack_14 = (undefined1 *)0x42ed55;
  FUN_00403b50((int *)&puStack_8);
  return;
}

