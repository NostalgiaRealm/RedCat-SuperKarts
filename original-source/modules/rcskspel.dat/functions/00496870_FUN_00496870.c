/*
 * FUN_00496870 at 00496870
 * undefined FUN_00496870(void)
 * Address ranges: 00496870-00496891
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00496870(int param_1,int param_2,int param_3)

{
  return (uint)*(ushort *)(*(int *)(param_1 + 0x6e) + (param_2 + param_3) * 2) * 0x20 +
         *(int *)(param_1 + 0x6a);
}

