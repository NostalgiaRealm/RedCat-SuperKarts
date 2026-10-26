/*
 * FUN_0042c8cc at 0042c8cc
 * int __register FUN_0042c8cc(int param_1)
 * Address ranges: 0042c8cc-0042c8de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042c8cc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x244);
  if (iVar1 == 0) {
    iVar1 = *(int *)(DAT_0047d774 + 0x34);
  }
  return iVar1;
}

