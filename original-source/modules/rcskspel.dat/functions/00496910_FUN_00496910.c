/*
 * FUN_00496910 at 00496910
 * undefined FUN_00496910(void)
 * Address ranges: 00496910-00496931
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00496910(int param_1,int param_2,int param_3)

{
  return (uint)*(ushort *)(*(int *)(param_1 + 0x5e) + (param_2 + param_3) * 2) * 0x20 +
         *(int *)(param_1 + 0x5a);
}

