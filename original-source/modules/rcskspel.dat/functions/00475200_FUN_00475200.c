/*
 * FUN_00475200 at 00475200
 * undefined FUN_00475200(void)
 * Address ranges: 00475200-0047535c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00475200(int param_1)

{
  int iVar1;
  void **ppvVar2;
  char *pcVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_004d0a34;
  iVar1 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x14);
  local_4 = 0;
  ppvVar2 = &local_c;
  local_c = ExceptionList;
  for (; ExceptionList = ppvVar2, iVar4 != iVar1; iVar4 = iVar4 + 0x60) {
    local_4._1_3_ = (uint3)((uint)local_4 >> 8);
    local_4._0_1_ = 5;
    FUN_00418ec0();
    local_4._0_1_ = 4;
    FUN_0040b4f0(1);
    local_4._0_1_ = 3;
    FUN_0040b4f0(1);
    local_4._0_1_ = 2;
    FUN_0040b4f0(1);
    local_4._0_1_ = 1;
    FUN_0040b4f0(1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0040b4f0(1);
    ppvVar2 = ExceptionList;
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 4);
  local_4 = 0xffffffff;
  for (; iVar4 != iVar1; iVar4 = iVar4 + 0x20) {
    local_4 = 6;
    FUN_0040b4f0(1);
    local_4 = 0xffffffff;
    if (*(int *)(iVar4 + 4) != 0) {
      pcVar3 = (char *)FUN_00476980(*(int *)(iVar4 + 4));
      if ((*pcVar3 == '\0') ||
         (pcVar3 = (char *)FUN_00476980(*(undefined4 *)(iVar4 + 4)), *pcVar3 == -1)) {
        FUN_0044aa80(*(int *)(iVar4 + 4) + -1,*(int *)(iVar4 + 0xc) + 2);
      }
      else {
        pcVar3 = (char *)FUN_00476980(*(undefined4 *)(iVar4 + 4));
        *pcVar3 = *pcVar3 + -1;
      }
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = local_c;
  return;
}

