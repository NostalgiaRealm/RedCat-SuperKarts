/*
 * FUN_0044a880 at 0044a880
 * undefined FUN_0044a880(void)
 * Address ranges: 0044a880-0044aa0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044a880(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  void **ppvVar5;
  int iVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cd8b1;
  iVar2 = *(int *)(param_1 + 0x60);
  local_4 = 2;
  ppvVar5 = &local_c;
  local_c = ExceptionList;
  while (ExceptionList = ppvVar5, iVar2 != 0) {
    iVar6 = *(int *)(param_1 + 0x40) + 4;
    *(int *)(param_1 + 0x40) = iVar6;
    *(int *)(param_1 + 0x60) = iVar2 + -1;
    if ((iVar2 + -1 == 0) || (iVar6 == *(int *)(param_1 + 0x3c))) {
      puVar3 = *(undefined4 **)(param_1 + 0x44);
      *(undefined4 **)(param_1 + 0x44) = puVar3 + 1;
      FUN_004bc150(*puVar3);
      if (*(int *)(param_1 + 0x60) == 0) {
        FUN_0043a8f0();
        *(undefined4 *)(param_1 + 0x38) = local_2c;
        *(undefined4 *)(param_1 + 0x3c) = local_28;
        *(undefined4 *)(param_1 + 0x40) = local_24;
        *(undefined4 *)(param_1 + 0x44) = local_20;
        *(undefined4 *)(param_1 + 0x48) = local_2c;
        *(undefined4 *)(param_1 + 0x4c) = local_28;
        *(undefined4 *)(param_1 + 0x50) = local_24;
        *(undefined4 *)(param_1 + 0x54) = local_20;
        FUN_004bc150(*(undefined4 *)(param_1 + 0x58));
      }
      else {
        FUN_0043ac50(**(undefined4 **)(param_1 + 0x44),*(undefined4 **)(param_1 + 0x44));
        *(undefined4 *)(param_1 + 0x38) = local_1c;
        *(undefined4 *)(param_1 + 0x3c) = local_18;
        *(undefined4 *)(param_1 + 0x40) = local_14;
        *(undefined4 *)(param_1 + 0x44) = local_10;
      }
    }
    ppvVar5 = ExceptionList;
    iVar2 = *(int *)(param_1 + 0x60);
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  iVar6 = *(int *)(param_1 + 0x28);
  uVar4 = (uint)local_4 >> 8;
  local_4 = CONCAT31((int3)uVar4,1);
  for (; iVar6 != iVar2; iVar6 = iVar6 + 0x60) {
    FUN_0044b6b0();
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0x28));
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

