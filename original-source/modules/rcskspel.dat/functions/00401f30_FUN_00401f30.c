/*
 * FUN_00401f30 at 00401f30
 * undefined FUN_00401f30(void)
 * Address ranges: 00401f30-00401f7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401f30(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040a120(*(int *)(&DAT_00503ef8 + param_1 * 0x11c),
                       *(undefined4 *)
                        (*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0x24 + DAT_0067ee20));
  if (iVar1 == -1) {
    iVar1 = FUN_00401cf0(param_1);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

