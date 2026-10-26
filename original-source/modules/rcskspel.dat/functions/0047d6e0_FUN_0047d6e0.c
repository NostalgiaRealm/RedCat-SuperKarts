/*
 * FUN_0047d6e0 at 0047d6e0
 * undefined FUN_0047d6e0(void)
 * Address ranges: 0047d6e0-0047d72c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047d6e0(int *param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  (**(code **)*param_1)();
  (**(code **)(*param_1 + 0xc))();
  DVar1 = GetTickCount();
  DVar2 = GetTickCount();
  while (DVar1 - DVar2 < 800) {
    FUN_004baf80();
    DVar2 = GetTickCount();
  }
  (**(code **)(*param_1 + 0x10))();
  (**(code **)(*param_1 + 8))();
  return;
}

