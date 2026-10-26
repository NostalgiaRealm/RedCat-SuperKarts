/*
 * FUN_0047c340 at 0047c340
 * undefined FUN_0047c340(void)
 * Address ranges: 0047c340-0047c4d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047c340(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_004d0f0a;
  local_c = ExceptionList;
  local_14 = param_1 + 0x70;
  local_4 = 6;
  uStack_3 = 0;
  ExceptionList = &local_c;
  FUN_00418ec0();
  local_4 = 5;
  FUN_00439a50(*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78));
  FUN_004bc150(*(undefined4 *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  local_4 = 4;
  FUN_0040b4f0(1);
  uVar4 = *(undefined4 *)(param_1 + 0x50);
  _local_4 = CONCAT31(uStack_3,3);
  puVar3 = (undefined4 *)FUN_0047c840(&local_14);
  FUN_0047c850(local_10,*puVar3,uVar4);
  FUN_004bc150(*(undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  DAT_00544fb4 = DAT_00544fb4 + -1;
  if (DAT_00544fb4 == 0) {
    FUN_004bc150(DAT_00544fb0);
    DAT_00544fb0 = 0;
  }
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  ExceptionList = local_c;
  return;
}

