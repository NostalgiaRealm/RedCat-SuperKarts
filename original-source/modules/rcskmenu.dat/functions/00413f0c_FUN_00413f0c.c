/*
 * FUN_00413f0c at 00413f0c
 * undefined __register FUN_00413f0c(int param_1, int param_2)
 * Address ranges: 00413f0c-00413f88;00413fa0-00413fb5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413f0c(int param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 local_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *local_c;
  int local_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_28 = &stack0xfffffffc;
  local_c = (byte *)0x0;
  puStack_20 = &LAB_00413fb6;
  local_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_24;
  puStack_2c = &LAB_00413f89;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  local_8 = param_1;
  uVar2 = FUN_004140d0(param_1,param_2,0);
  if ((char)uVar2 != '\v') {
    FUN_004124c0();
  }
  iVar3 = FUN_0040d254(param_2);
  pcVar1 = (char *)**(undefined4 **)(iVar3 + 1);
  uVar2 = extraout_ECX;
  while (FUN_00413fec(local_8,(int *)&local_c,uVar2), local_c != (byte *)0x0) {
    FUN_004124d8(pcVar1,local_c);
    uVar2 = extraout_ECX_00;
  }
  *in_FS_OFFSET = uStack_30;
  *in_FS_OFFSET = local_24;
  puStack_1c = &LAB_00413fbd;
  puStack_20 = (undefined1 *)0x413fb5;
  FUN_00403b50((int *)&local_c);
  return;
}

