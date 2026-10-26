/*
 * FUN_004aad10 at 004aad10
 * undefined FUN_004aad10(void)
 * Address ranges: 004aad10-004aae9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004aad10(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1848;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004ae7c0();
  local_4 = 0;
  local_58 = 0x40000000;
  local_54 = 0x41f00000;
  local_50 = 0x41f00000;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_70 = 0;
  local_6c = 0x3f800000;
  local_68 = 0;
  *(undefined4 *)(param_1 + 0x274) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  puVar1 = (undefined4 *)FUN_004a1ad0(local_4c,&local_58,&local_64,&local_70,0);
  puVar3 = (undefined4 *)(param_1 + 0x1dc);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004a1a40(local_4c,0x41200000,0x46435000,0x3f20d97c);
  puVar3 = (undefined4 *)(param_1 + 0x19c);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_006a5c90;
  puVar3 = (undefined4 *)(param_1 + 0x21c);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x284) = 3;
  *(undefined4 *)(param_1 + 0x2c4) = 3;
  *(undefined4 *)(param_1 + 0x27c) = 0;
  *(undefined4 *)(param_1 + 0x298) = 1;
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x29c) = 1;
  *(undefined4 *)(param_1 + 0x2a0) = 1;
  *(undefined4 *)(param_1 + 0x2a4) = 1;
  *(undefined4 *)(param_1 + 0x2c8) = 0;
  *(undefined4 *)(param_1 + 0x280) = 0xffffff;
  *(undefined4 *)(param_1 + 0x28c) = 0x40500000;
  *(undefined4 *)(param_1 + 0x290) = 0x42480000;
  *(undefined4 *)(param_1 + 0x288) = 0x3f4ccccd;
  *(undefined4 *)(param_1 + 0x294) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2c0) = 2;
  *(undefined4 *)(param_1 + 0x2b0) = 2;
  *(undefined4 *)(param_1 + 0x2ac) = 0xffffffff;
  ExceptionList = local_c;
  return param_1;
}

