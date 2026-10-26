/*
 * FUN_004c8eb4 at 004c8eb4
 * undefined FUN_004c8eb4(void)
 * Address ranges: 004c8eb4-004c8ee8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c8eb4(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_004c8eff();
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_004c8f91(uVar1);
  return uVar1;
}

