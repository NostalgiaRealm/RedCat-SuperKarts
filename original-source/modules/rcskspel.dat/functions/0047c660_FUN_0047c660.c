/*
 * FUN_0047c660 at 0047c660
 * undefined FUN_0047c660(void)
 * Address ranges: 0047c660-0047c6b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047c660(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_0047c850(&local_4,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  DAT_00544fb4 = DAT_00544fb4 + -1;
  if (DAT_00544fb4 == 0) {
    FUN_004bc150(DAT_00544fb0);
    DAT_00544fb0 = 0;
  }
  return;
}

