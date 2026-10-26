/*
 * FUN_0042c990 at 0042c990
 * undefined4 __register FUN_0042c990(int param_1)
 * Address ranges: 0042c990-0042c9a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042c990(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x80000005;
  if (*(char *)(param_1 + 0x217) == '\x02') {
    uVar1 = 0x8000000c;
  }
  return uVar1;
}

