/*
 * FUN_0044cc38 at 0044cc38
 * undefined __register FUN_0044cc38(int param_1, int param_2)
 * Address ranges: 0044cc38-0044ccea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044cc38(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffc8;
  int *piVar7;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  byte *local_18;
  int local_14;
  undefined1 local_10;
  int local_c;
  int local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_18 = (byte *)0x0;
  puStack_2c = &LAB_0044cceb;
  puStack_30 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_30;
  iVar6 = 0;
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 4) + -1;
  local_c = param_2;
  local_8 = param_1;
  if (-1 < iVar3) {
    do {
      uVar5 = (uint)(iVar3 + iVar6) >> 1;
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 8 + uVar5 * 0xc);
      puVar2 = &stack0xfffffffc;
      if (iVar1 == param_2) goto LAB_0044ccd5;
      if (iVar1 < param_2) {
        iVar6 = uVar5 + 1;
      }
      else {
        iVar3 = uVar5 - 1;
      }
    } while (iVar6 <= iVar3);
  }
  puVar2 = &stack0xfffffffc;
  if (*(char *)(param_1 + 4) != '\0') {
    local_10 = 0;
    piVar7 = &local_14;
    in_stack_ffffffc8 = 0;
    local_14 = param_2;
    FUN_0044cb68(DAT_0047d868,1,(int *)&local_18);
    uVar4 = FUN_0040aca0((int)&DAT_0044ca4c,'\x01',local_18,in_stack_ffffffc8,piVar7);
    FUN_00403604(uVar4);
    puVar2 = puStack_28;
  }
LAB_0044ccd5:
  puStack_28 = puVar2;
  *in_FS_OFFSET = in_stack_ffffffc8;
  puStack_30 = &LAB_0044ccf2;
  FUN_00403b50((int *)&local_18);
  return;
}

