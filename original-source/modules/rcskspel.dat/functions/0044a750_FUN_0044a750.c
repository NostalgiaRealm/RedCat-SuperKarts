/*
 * FUN_0044a750 at 0044a750
 * undefined FUN_0044a750(void)
 * Address ranges: 0044a750-0044a852
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044a750(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd831;
  iVar1 = *(int *)(param_1 + 8);
  local_c = ExceptionList;
  ExceptionList = &local_c;
  for (iVar3 = *(int *)(param_1 + 4); iVar3 != iVar1; iVar3 = iVar3 + 0x78) {
    local_4 = 2;
    cVar2 = FUN_0044aa90();
    while (cVar2 == '\0') {
      FUN_00438b80();
      cVar2 = FUN_0044aa90();
    }
    local_4._1_3_ = (uint3)((uint)local_4 >> 8);
    local_4._0_1_ = 1;
    FUN_0044aa50(*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c));
    FUN_0044aa80(*(int *)(iVar3 + 0x28),(*(int *)(iVar3 + 0x30) - *(int *)(iVar3 + 0x28)) / 0x60);
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0;
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0040b4f0(1);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = local_c;
  return;
}

