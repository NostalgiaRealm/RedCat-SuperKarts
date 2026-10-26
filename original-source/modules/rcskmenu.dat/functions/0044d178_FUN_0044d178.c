/*
 * FUN_0044d178 at 0044d178
 * undefined __register FUN_0044d178(char * param_1, int param_2, int param_3)
 * Address ranges: 0044d178-0044d1fe;0044d220-0044d235
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044d178(char *param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 *in_FS_OFFSET;
  char **ppcVar3;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  undefined4 local_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  char *local_c;
  int local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = (char *)0x0;
  puStack_20 = &LAB_0044d236;
  local_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_24;
  puVar1 = &stack0xfffffffc;
  if (param_3 < 1) {
    puStack_28 = (undefined1 *)0x44d1b2;
    FUN_00403b34("aStartPos must be > 0");
    puVar1 = puStack_1c;
  }
  puStack_1c = puVar1;
  local_8 = 0;
  puStack_2c = &DAT_0044d1ff;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  ppcVar3 = &local_c;
  puStack_28 = &stack0xfffffffc;
  uVar2 = FUN_00403dd0(param_2);
  FUN_00403fd8(param_2,param_3,uVar2,(int *)ppcVar3);
  local_8 = FUN_004040bc(param_1,local_c);
  if (0 < local_8) {
    local_8 = param_3 + local_8 + -1;
  }
  *in_FS_OFFSET = uStack_30;
  *in_FS_OFFSET = local_24;
  puStack_1c = &LAB_0044d23d;
  puStack_20 = (undefined1 *)0x44d235;
  FUN_00403b50((int *)&local_c);
  return;
}

