/*
 * FUN_004b88d0 at 004b88d0
 * undefined FUN_004b88d0(void)
 * Address ranges: 004b88d0-004b8927
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b88d0(int param_1)

{
  int iVar1;
  
  DAT_00501328 = param_1;
  DAT_006ab894 = LocalAlloc(0x40,param_1 * 0xc);
  if (DAT_006ab894 != (HLOCAL)0x0) {
    if (0 < param_1) {
      iVar1 = 0;
      do {
        *(undefined4 *)(iVar1 + 8 + (int)DAT_006ab894) = 0;
        *(undefined4 *)(iVar1 + 4 + (int)DAT_006ab894) = 0;
        *(undefined4 *)(iVar1 + (int)DAT_006ab894) = 0;
        iVar1 = iVar1 + 0xc;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    return 0;
  }
  return 2000;
}

