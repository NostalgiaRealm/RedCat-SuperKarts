/*
 * FUN_0040d5c0 at 0040d5c0
 * undefined FUN_0040d5c0(void)
 * Address ranges: 0040d5c0-0040d601
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d5c0(int param_1)

{
  undefined4 uVar1;
  
  if (((&DAT_00503ef4)[param_1 * 0x47] != 9) && ((&DAT_00503ef4)[param_1 * 0x47] != 0x1b)) {
    (&DAT_00503ef4)[param_1 * 0x47] = 0x1b;
    (&DAT_00503f8c)[param_1 * 0x11c] = 1;
    uVar1 = FUN_0040e000(param_1);
    *(undefined4 *)(&DAT_00503fc4 + param_1 * 0x11c) = uVar1;
  }
  return;
}

