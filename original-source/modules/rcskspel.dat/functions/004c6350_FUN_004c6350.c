/*
 * FUN_004c6350 at 004c6350
 * undefined FUN_004c6350(void)
 * Address ranges: 004c6350-004c637a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c6350(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_006b6d9c;
  while( true ) {
    if (DAT_006b6d9c + DAT_006b6d98 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}

