/*
 * FUN_00473fb0 at 00473fb0
 * undefined FUN_00473fb0(void)
 * Address ranges: 00473fb0-00474032
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473fb0(int param_1,undefined4 param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  uint uVar3;
  undefined1 local_4 [4];
  
  FUN_004707f0();
  FUN_004b4d70(param_2,0);
  FUN_004739c0(local_4);
  FUN_004715e0(1,param_1 + 2,9);
  FUN_00471d10(1);
  FUN_004aff70();
  DVar1 = GetTickCount();
  DVar2 = GetTickCount();
  uVar3 = DVar2 - DVar1;
  while (uVar3 < 100) {
    FUN_00473d40();
    DVar2 = GetTickCount();
    uVar3 = DVar2 - DVar1;
  }
  FUN_004739c0(local_4);
  FUN_00471d10(1);
  FUN_004aff70();
  return;
}

