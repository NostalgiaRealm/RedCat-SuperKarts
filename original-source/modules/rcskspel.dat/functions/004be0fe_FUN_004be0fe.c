/*
 * FUN_004be0fe at 004be0fe
 * undefined FUN_004be0fe(void)
 * Address ranges: 004be0fe-004be132
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004be0fe(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x24);
  while (uVar1 < 8) {
    if ((*(int *)(&DAT_006b6658 + *(int *)(param_1 + 0x24) * 4) == 0) ||
       (*(int *)(&DAT_006b6658 + *(int *)(param_1 + 0x24) * 4) == param_1)) break;
    uVar1 = *(int *)(param_1 + 0x24) + 1;
    *(uint *)(param_1 + 0x24) = uVar1;
  }
  *(int *)(&DAT_006b6658 + *(int *)(param_1 + 0x24) * 4) = param_1;
  (&DAT_006b667c)[*(int *)(param_1 + 0x24)] = (&DAT_006b667c)[*(int *)(param_1 + 0x24)] + '\x01';
  return;
}

