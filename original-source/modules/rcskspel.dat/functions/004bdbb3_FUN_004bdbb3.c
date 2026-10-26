/*
 * FUN_004bdbb3 at 004bdbb3
 * undefined FUN_004bdbb3(void)
 * Address ranges: 004bdbb3-004bdbcb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004bdbb3(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_004c12ca(*(int *)(param_1 + 0x50));
    if (iVar1 < 0) {
      return 0xffffffff;
    }
  }
  return 0;
}

